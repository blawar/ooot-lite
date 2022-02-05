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
#define osRecvMesg(a, b, c) 0
#define osSendMesg(a, b, c) 0

#if defined(OS_WINDOWS) && (defined(_MSC_VER) || defined(__MINGW32__))
void bzero(void* __s, size_t __n);
void bcopy(void* __s, void* __d, size_t __n);
#else
#include <strings.h>
#endif

u64 osGetTime();
void __assert(const char* exp, const char* file, s32 line);

#include "z_debug_display.h"

