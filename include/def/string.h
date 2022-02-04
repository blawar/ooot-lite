#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_LIBC_BAK_STRING_C
void* memcpy(void* dst, const void* src, u32 size);
u32 strlen(const char* str);
#else
void* memcpy(void* dst, const void* src, u32 size);
u32 strlen(const char* str);
#endif
