/* SPDX-FileCopyrightText: 2022 Hayden Kowalchuk 819028+mrneo240@users.noreply.github.com */
/* SPDX-License-Identifier: BSD-3-Clause */
/* Note: The above applies to parts of this file modified by Hayden Kowalchuk only and not existing code */

#pragma once

/* Contains defs for the lut tables generated by ZAPD and used throughout */
typedef struct LutEntry {
    /* 0x00 */ u8* data;
    /* 0x04 */ size_t size;
} LutEntry;

typedef LutEntry LutInfo;

size_t lutGetTotalSize(LutEntry *entries, size_t count);
void lutDma(void* ram0, LutEntry *entries, size_t count, const char* file, s32 line);
