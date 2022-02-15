#!/usr/bin/env python3

import argparse
from os import path
import io
import sys
import struct
import hashlib
from libyaz0 import decompress

# Used for retail 1.0
UNCOMPRESSED_SIZE = 0x34D3040

def cancel():
    input("Press Enter To Cancel...")
    sys.exit(1)

def as_word(b, off=0):
    return struct.unpack(">I", b[off:off+4])[0]

def as_word_list(b):
    return [i[0] for i in struct.iter_unpack(">I",  b)]

def calc_crc(rom_data, cic_type):
    start = 0x1000
    end = 0x101000

    unsigned_long = lambda i: i & 0xFFFFFFFF
    rol = lambda i, b: unsigned_long(i << b) | (i >> (-b & 0x1F))

    if cic_type == 6101 or cic_type == 6102:
        seed = 0xF8CA4DDC
    elif cic_type == 6103:
        seed = 0xA3886759
    elif cic_type == 6105:
        seed = 0xDF26F436
    elif cic_type == 6106:
        seed = 0x1FEA617A
    else:
        assert False , f"Unknown cic type: {cic_type}"

    t1 = t2 = t3 = t4 = t5 = t6 = seed

    for pos in range(start, end, 4):
        d = as_word(rom_data, pos)
        r = rol(d, d & 0x1F)

        t6d = unsigned_long(t6 + d)
        if t6d < t6:
            t4 = unsigned_long(t4 + 1)
        t6 = t6d
        t3 ^= d
        t5 = unsigned_long(t5 + r)

        if t2 > d:
            t2 ^= r
        else:
            t2 ^= t6 ^ d

        if cic_type == 6105:
            t1 = unsigned_long(t1 + (as_word(rom_data, 0x0750 + (pos & 0xFF)) ^ d))
        else:
            t1 = unsigned_long(t1 + (t5 ^ d))

    chksum = [0,0]

    if cic_type == 6103:
        chksum[0] = unsigned_long((t6 ^ t4) + t3)
        chksum[1] = unsigned_long((t5 ^ t2) + t1)
    elif cic_type == 6106:
        chksum[0] = unsigned_long((t6 * t4) + t3)
        chksum[1] = unsigned_long((t5 * t2) + t1)
    else:
        chksum[0] = t6 ^ t4 ^ t3
        chksum[1] = t5 ^ t2 ^ t1

    return struct.pack(">II", chksum[0], chksum[1])

def read_dmadata_entry(addr, fileContent):
    return as_word_list(fileContent[addr:addr+0x10])

def read_dmadata(start, fileContent):
    dmadata = []
    addr = start
    entry = read_dmadata_entry(addr, fileContent)
    i = 0
    while any([e != 0 for e in entry]):
        # print(f"0x{addr:08X} " + str([f"{e:08X}" for e in entry]))
        dmadata.append(entry)
        addr += 0x10
        i += 1
        entry = read_dmadata_entry(addr, fileContent)
    # print(f"0x{addr:08X} " + str([f"{e:08X}" for e in entry]))
    return dmadata

def update_crc(decompressed):
    print("Recalculating crc...")
    new_crc = calc_crc(decompressed.getbuffer(), 6105)

    decompressed.seek(0x10)
    decompressed.write(new_crc)
    return decompressed

def decompress_rom(dmadata_addr, dmadata, fileContent):
    rom_segments = {} # vrom start : data s.t. len(data) == vrom_end - vrom_start
    new_dmadata = bytearray() # new dmadata: {vrom start , vrom end , vrom start , 0}

    decompressed = io.BytesIO(b"")

    for v_start, v_end, p_start, p_end in dmadata:
        if p_start == 0xFFFFFFFF and p_end == 0xFFFFFFFF:
            new_dmadata.extend(struct.pack(">IIII", v_start, v_end, p_start, p_end))
            continue
        if p_end == 0: # uncompressed
            rom_segments.update({v_start : fileContent[p_start:p_start + v_end - v_start]})
        else: # compressed
            rom_segments.update({v_start : decompress(fileContent[p_start:p_end])})
        new_dmadata.extend(struct.pack(">IIII", v_start, v_end, v_start, 0))

    # write rom segments to vaddrs
    for vrom_st,data in rom_segments.items():
        decompressed.seek(vrom_st)
        decompressed.write(data)
    # write new dmadata
    decompressed.seek(dmadata_addr)
    decompressed.write(new_dmadata)
    # pad to size
    decompressed.seek(UNCOMPRESSED_SIZE-1)
    decompressed.write(bytearray([0]))
    # re-calculate crc
    return update_crc(decompressed)

def get_str_hash(byte_array):
    return str(hashlib.md5(byte_array).hexdigest())

def find_baserom_original(rom_suffix:str):
    # Determine if we have a ROM file
    romFileExtensions = ["z64", "n64", "v64"]

    for romFileExtLower in romFileExtensions:
        for romFileExt in (romFileExtLower, romFileExtLower.upper()):
            romFileNameCandidate = f"baserom_original.{rom_suffix}." + romFileExt
            print(f"Checking for {romFileNameCandidate}...")
            if path.exists(romFileNameCandidate):
                return romFileNameCandidate
    return None

def main():
    # Command Line Interface
    parser = argparse.ArgumentParser(description="Setup")
    parser.add_argument("-mq", "--debug", help="Uses debug masterquest rom for Assets", action="store_true", default=False)
    parser.add_argument("-eu", "--retail", help="Uses retail pal 1.0 rom for Assets", action="store_true", default=False)
    args = parser.parse_args()

    if not args.debug and not args.retail:
        args.debug = True

    if args.debug and args.retail:
        print("Error: Both retail and debug flags set, only 1 allowed")
        sys.exit(1)

    if args.debug:
        rom_suffix = "mq"
        correct_input_hash = correct_output_hash = "f0b7f35375f9cc8ca1b2d59d78e35405"
    if args.retail:
        rom_suffix = "eu"
        correct_input_hash = "e040de91a74b61e3201db0e2323f768a"
        correct_output_hash = "c02c1d79679f7ceb9a3bde55fff8aa13"

    # If the baserom exists and is correct, we don't need to change anything
    if path.exists(f"baserom.{rom_suffix}.z64"):
        with open(f"baserom.{rom_suffix}.z64", mode="rb") as file:
            fileContent = bytearray(file.read())
            if get_str_hash(fileContent) == correct_output_hash:
                print("Found valid baserom - exiting early")
                sys.exit(0)

    romFileName = find_baserom_original(rom_suffix)

    if romFileName is None:
        print(f"Error: Could not find baserom_original.{rom_suffix}.z64/baserom_original.{rom_suffix}.n64/baserom_original.{rom_suffix}.v64.")
        sys.exit(1)

    # Read in the original ROM
    print("File '" + romFileName + "' found.")
    with open(romFileName, mode="rb") as file:
        fileContent = bytearray(file.read())

    if args.debug:
        # Strip the overdump
        print("Stripping overdump...")
        fileContent = fileContent[0:0x3600000]

    fileContentLen = len(fileContent)

    # Check if ROM needs to be byte/word swapped
    # Little-endian
    if fileContent[0] == 0x40:
        # Word Swap ROM
        print("ROM needs to be word swapped...")
        words = str(int(fileContentLen/4))
        little_byte_format = "<" + words + "I"
        big_byte_format = ">" + words + "I"
        tmp = struct.unpack_from(little_byte_format, fileContent, 0)
        struct.pack_into(big_byte_format, fileContent, 0, *tmp)

        print("Word swapping done.")

    # Byte-swapped
    elif fileContent[0] == 0x37:
        # Byte Swap ROM
        print("ROM needs to be byte swapped...")
        halfwords = str(int(fileContentLen/2))
        little_byte_format = "<" + halfwords + "H"
        big_byte_format = ">" + halfwords + "H"
        tmp = struct.unpack_from(little_byte_format, fileContent, 0)
        struct.pack_into(big_byte_format, fileContent, 0, *tmp)

        print("Byte swapping done.")

    if args.debug:
        # Patch the header
        print("Patching header...")
        fileContent[0x3E] = 0x50

        for i in range(0x35CF000, len(fileContent)):
            fileContent[i] = 0xFF

    if args.retail:
        # Decompress
        FILE_TABLE_OFFSET = 0x7950
        if any([b != 0 for b in fileContent[FILE_TABLE_OFFSET + 0x9C:FILE_TABLE_OFFSET + 0x9C + 0x4]]):
            print("Decompressing rom...")
            fileContent = decompress_rom(FILE_TABLE_OFFSET, read_dmadata(FILE_TABLE_OFFSET, fileContent), fileContent).getbuffer()

    # Check to see if the ROM is a "vanilla" Debug ROM
    str_hash = get_str_hash(bytearray(fileContent))
    if str_hash != correct_output_hash:
        print(f"Error: Expected a hash of {correct_output_hash} but got " + str_hash + ". " +
              "The baserom has probably been tampered, find a new one")
        sys.exit(1)

    # Write out our new ROM
    print(f"Writing new ROM 'baserom.{rom_suffix}.z64'.")
    with open(f"baserom.{rom_suffix}.z64", mode="wb") as file:
        file.write(bytes(fileContent))

    print("Done!")

if __name__ == "__main__":
    main()