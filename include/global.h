#pragma once

#include "porting_defs.h"
#include "z64.h"

#ifdef __cplusplus
#define _LANGUAGE_C_PLUS_PLUS
#endif

/*#include "functions.h"
#include "variables.h"*/
#include "macros.h"

#include <stdarg.h>
void osSyncPrintf(const char* fmt, ...);
#if defined(__GNUC__)
#define _CONST __attribute__((const))
#else
#define _CONST
#endif
s32 _CONST osRecvMesg(void* mq, void* msg, s32 flag);
s32 _CONST osSendMesg(void* mq, void* msg, s32 flag);
void osCreateMesgQueue(void* mq, void* msg, s32 count);

#if defined(OS_WINDOWS) && (defined(_MSC_VER) || defined(__MINGW32__))
void bzero(void* __s, size_t __n);
void bcopy(void* __s, void* __d, size_t __n);
#else
#include <strings.h>
#endif
#include <string.h>

u64 osGetTime();
void __assert(const char* exp, const char* file, s32 line);

#include "z_debug_display.h"

