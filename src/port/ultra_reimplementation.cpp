#include <stdio.h>
#include <string.h>
//#include <stdarg.h>
//#include "global.h"

extern "C" {
#include "global.h"
//#include "ultra64/message.h"
//#include "ultra64/convert.h"
//#include "ultra64/exception.h"
//#include "ultra64/time.h"
//#include "ultra64/pi.h"
//#include "ultra64/vi.h"
}

typedef u32 OSEvent;
typedef void* OSMesg;
typedef u64 OSTime;
typedef s32 OSPri;

#ifdef TARGET_WEB
#include <emscripten.h>
#endif

#if defined(__SWITCH__) && !defined(_MSC_VER)
#include "nx.h"
#endif

extern "C" {
#if !defined(_WIN32)
	bool fopen_s(FILE** fp, const char* filename, const char* mode)
	{
		*fp = fopen(filename, mode);
		return *fp != nullptr;
	}
#endif
}

#define UNUSED

#define OS_CLOCK_RATE           62500000LL
u64 osClockRate = OS_CLOCK_RATE;

s32 osPiStartDma(struct OSIoMesg* mb, UNUSED s32 priority, UNUSED s32 direction, uintptr_t devAddr, void* vAddr, size_t nbytes, struct OSMesgQueue* mq)
{
	memcpy(vAddr, (const void*)devAddr, nbytes);
	return 0;
}

void osSetEventMesg(UNUSED OSEvent e, UNUSED OSMesgQueue* mq, UNUSED OSMesg msg)
{
}

s32 osJamMesg(UNUSED OSMesgQueue* mq, UNUSED OSMesg msg, UNUSED s32 flag)
{
	return 0;
}

/*s32 osSendMesg(UNUSED OSMesgQueue* mq, UNUSED OSMesg msg, UNUSED s32 flag)
{
	return 0;
}*/

uintptr_t osVirtualToPhysical(void* addr)
{
	return (uintptr_t)addr;
}

void osCreateViManager(UNUSED OSPri pri)
{
}
void osViSetMode(UNUSED struct OSViMode* mode)
{
}
void osViSetEvent(UNUSED OSMesgQueue* mq, UNUSED OSMesg msg, UNUSED u32 retraceCount)
{
}
void osViBlack(UNUSED u8 active)
{
}
void osViSetSpecialFeatures(UNUSED u32 func)
{
}
void osViSwapBuffer(UNUSED void* vaddr)
{
}

#if defined(_MSC_VER)
#include <windows.h>

OSTime osGetTime(void) {
    return GetTickCount64();
}
#else
OSTime osGetTime(void)
{
	return 0;
}
#endif
#if defined(_WIN32)
#include <debugapi.h>
#endif

void osWritebackDCacheAll(void)
{
}

void osWritebackDCache(UNUSED void* a, UNUSED size_t b)
{
}

void osInvalDCache(UNUSED void* a, UNUSED size_t b)
{
}

u32 osGetCount(void)
{
	static u32 counter;
	return counter++;
}

s32 osAiSetFrequency(u32 freq)
{
	u32 a1;
	s32 a2;
	u32 D_8033491C;

	D_8033491C = 0x02E6D354;

	a1 = D_8033491C / (float)freq + .5f;

	if(a1 < 0x84)
	{
		return -1;
	}

	a2 = (a1 / 66) & 0xff;
	if(a2 > 16)
	{
		a2 = 16;
	}

	return D_8033491C / (s32)a1;
}

s32 osEepromProbe(UNUSED OSMesgQueue* mq)
{
	return 1;
}

#define OS_READ     0 // device -> RDRAM
#define OS_WRITE    1 // device <- RDRAM
#define SRAM_SIZE 0x8000

extern "C" {
	void SsSram_ReadWrite(u32 address, void* buffer, size_t nbytes, s32 direction)
	{
		if(address < 0xA8000000)
		{
			return;
		}

		address -= 0xA8000000;

		static u8 content[SRAM_SIZE] = { 0 };

		if(direction == OS_READ)
		{
			s32 ret = -1;

#if defined(__SWITCH__) && !defined(_MSC_VER) && !defined(BUILD_NRO)
			mountSaveData();

			FILE* fp = fopen("sv:/oot.sav", "rb");
			if(fp == NULL)
			{
				fp = fopen("sdmc:/oot.sav", "rb");

				if(fp == NULL)
				{
					unmountSaveData();
					return -1;
				}
			}

			if(fread(content, 1, SRAM_SIZE, fp) == SRAM_SIZE)
			{
				memcpy(buffer, content + address, nbytes);
				ret = 0;
			}
			fclose(fp);
			unmountSaveData();
#else
			FILE* fp = nullptr;

			if(fopen_s(&fp, "oot.sav", "rb") != 0)
			{
				return;
			}
			if(fread(content, 1, SRAM_SIZE, fp) == SRAM_SIZE)
			{
				memcpy(buffer, content + address, nbytes);
				ret = 0;
			}
			fclose(fp);
#endif
		}
		else if(direction == OS_WRITE)
		{
			memcpy(content + address, buffer, nbytes);

#if defined(__SWITCH__) && !defined(_MSC_VER) && !defined(BUILD_NRO)
			mountSaveData();
			FILE* fp = fopen("sv:/oot.sav", "wb");

			if(fp == NULL)
			{
				fp = fopen("sdmc:/oot.sav", "wb");

				if(fp == NULL)
				{
					return -1;
				}
			}

			s32 ret = fwrite(content, 1, SRAM_SIZE, fp) == SRAM_SIZE ? 0 : -1;
			fclose(fp);
			commitSave();
			unmountSaveData();
#else
			FILE* fp = nullptr;

			if(fopen_s(&fp, "oot.sav", "wb") != 0)
			{
				return;
			}

			s32 ret = fwrite(content, 1, SRAM_SIZE, fp) == SRAM_SIZE ? 0 : -1;
			fclose(fp);
#endif
		}
	}
}

s32 osEepromLongRead(UNUSED OSMesgQueue* mq, u8 address, u8* buffer, int nbytes)
{
	u8 content[512];
	s32 ret = -1;

#if defined(__SWITCH__) && !defined(_MSC_VER) && !defined(BUILD_NRO)
	mountSaveData();

	FILE* fp = fopen("sv:/oot.sav", "rb");
	if(fp == NULL)
	{
		fp = fopen("sdmc:/oot.sav", "rb");

		if(fp == NULL)
		{
			unmountSaveData();
			return -1;
		}
	}

	if(fread(content, 1, 512, fp) == 512)
	{
		memcpy(buffer, content + address * 8, nbytes);
		ret = 0;
	}
	fclose(fp);
	unmountSaveData();
#else
    FILE* fp = nullptr; 

    if (fopen_s(&fp, "oot.sav", "rb") != 0)
	{
		return -1;
	}
	if(fread(content, 1, 512, fp) == 512)
	{
		memcpy(buffer, content + address * 8, nbytes);
		ret = 0;
	}
	fclose(fp);
#endif
	return ret;
}

s32 osEepromLongWrite(UNUSED OSMesgQueue* mq, u8 address, u8* buffer, int nbytes)
{
	u8 content[512] = {0};
	if(address != 0 || nbytes != 512)
	{
		osEepromLongRead(mq, 0, content, 512);
	}
	memcpy(content + address * 8, buffer, nbytes);

#if defined(__SWITCH__) && !defined(_MSC_VER) && !defined(BUILD_NRO)
	mountSaveData();
	FILE* fp = fopen("sv:/oot.sav", "wb");

	if(fp == NULL)
	{
		fp = fopen("sdmc:/oot.sav", "wb");

		if(fp == NULL)
		{
			return -1;
		}
	}

	s32 ret = fwrite(content, 1, 512, fp) == 512 ? 0 : -1;
	fclose(fp);
	commitSave();
	unmountSaveData();
#else
    FILE* fp = nullptr;

	if (fopen_s(&fp, "oot.sav", "wb") != 0)
	{
		return -1;
	}

	s32 ret = fwrite(content, 1, 512, fp) == 512 ? 0 : -1;
	fclose(fp);
#endif
	return ret;
}

u32 bcmp(void* s1, void* s2, u32 size) {
    const u8* _s1 = (const u8*)s1;
    const u8* _s2 = (const u8*)s2;

    while (size > 0) {
        if (*_s1++ != *_s2++) {
            return 1;
        }
        size--;
    }

    return 0;
}

#include <stdio.h>
#include <string>
#include <vector>
#include <stdexcept>

std::wstring utf8_to_utf16(const std::string& utf8) {
    std::vector<unsigned long> unicode;
    size_t i = 0;
    while (i < utf8.size()) {
        unsigned long uni;
        size_t todo;
        bool error = false;
        unsigned char ch = utf8[i++];
        if (ch <= 0x7F) {
            uni = ch;
            todo = 0;
        } else if (ch <= 0xBF) {
            throw std::logic_error("not a UTF-8 string");
        } else if (ch <= 0xDF) {
            uni = ch & 0x1F;
            todo = 1;
        } else if (ch <= 0xEF) {
            uni = ch & 0x0F;
            todo = 2;
        } else if (ch <= 0xF7) {
            uni = ch & 0x07;
            todo = 3;
        } else {
            throw std::logic_error("not a UTF-8 string");
        }
        for (size_t j = 0; j < todo; ++j) {
            if (i == utf8.size())
                throw std::logic_error("not a UTF-8 string");
            unsigned char ch = utf8[i++];
            if (ch < 0x80 || ch > 0xBF)
                throw std::logic_error("not a UTF-8 string");
            uni <<= 6;
            uni += ch & 0x3F;
        }
        if (uni >= 0xD800 && uni <= 0xDFFF)
            throw std::logic_error("not a UTF-8 string");
        if (uni > 0x10FFFF)
            throw std::logic_error("not a UTF-8 string");
        unicode.push_back(uni);
    }
    std::wstring utf16;
    for (size_t i = 0; i < unicode.size(); ++i) {
        unsigned long uni = unicode[i];
        if (uni <= 0xFFFF) {
            utf16 += (wchar_t)uni;
        } else {
            uni -= 0x10000;
            utf16 += (wchar_t)((uni >> 10) + 0xD800);
            utf16 += (wchar_t)((uni & 0x3FF) + 0xDC00);
        }
    }
    return utf16;
}

static char buffer[0x10000];

void osSyncPrintf(const char* fmt, ...) {
#if defined(_WIN32)
    memset(buffer, 0, sizeof(buffer));
    va_list arg;
    int done;
    va_start(arg, fmt);
    vsprintf(buffer, fmt, arg);
    va_end(arg);

	auto s = utf8_to_utf16(buffer);
	//OutputDebugStringA(buffer);
	OutputDebugStringW(s.c_str());
#endif
}

#include "color.h"
#include <memory>
#include "ultra64/gbi.h"

static_assert(sizeof(Color_RGB8) == 3, "incorrect Color_RGB8 size");

extern "C" {
	#include "jpeg_decoder.h"
	s32 Jpeg_Decode(void* data, void* zbuffer, void* work, u32 workSize)
	{
		auto decoder = std::make_unique<Jpeg::Decoder>((const u8*)data, SCREEN_WIDTH * SCREEN_HEIGHT * 2);

		if(decoder->GetResult() != Jpeg::Decoder::OK)
		{
			return 1;
		}

		Color_RGB8* p = (Color_RGB8*)decoder->GetImage();
		u64 sz = decoder->GetImageSize() / sizeof(Color_RGB8);
		u16* out = (u16*)zbuffer;

		for(u64 i = 0; i < sz; i++, p++, out++)
		{
			u8 r = p->r / 8;
			u8 g = p->g / 8;
			u8 b = p->b / 8;
			*out = BE16((r << 11) + (g << 6) + (b << 1) + 1);
			//*out = BE16(1);
		}

		return 0;
	}
}