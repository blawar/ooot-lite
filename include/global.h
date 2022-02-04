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

#if defined(_MSC_VER)
#define bcopy(b1, b2, len) (memmove((b2), (b1), (len)), (void)0)
#define bzero(b, len) (memset((b), '\0', (len)), (void)0)
#else
//void bzero(void* __s, size_t __n);
//void bcopy(void* __s, void* __d, size_t __n);
#endif

u64 osGetTime();
void __assert(const char* exp, const char* file, s32 line);

#include "z_debug_display.h"

