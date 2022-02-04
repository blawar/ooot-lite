#pragma once

#ifndef USE_NATIVE_MALLOC
extern u32 __osMalloc_FreeBlockTest_Enable;

#ifdef INTERNAL_SRC_CODE_OSMALLOC_C
void ArenaImpl_FaultClient(Arena* arena);
u32 ArenaImpl_GetCheckFreeBlock(Arena* arena);
u32 ArenaImpl_GetFillAllocBlock(Arena* arena);
u32 ArenaImpl_GetFillFreeBlock(Arena* arena);
ArenaNode* ArenaImpl_GetLastBlock(Arena* arena);
ArenaNode* ArenaImpl_GetNextBlock(ArenaNode* node);
ArenaNode* ArenaImpl_GetPrevBlock(ArenaNode* node);
void ArenaImpl_GetSizes(Arena* arena, u32* outMaxFree, u32* outFree, u32* outAlloc);
void ArenaImpl_Lock(Arena* arena);
void ArenaImpl_LockInit(Arena* arena);
void ArenaImpl_RemoveAllBlocks(Arena* arena);
void ArenaImpl_SetCheckFreeBlock(Arena* arena);
void ArenaImpl_SetDebugInfo(ArenaNode* node, const char* file, s32 line, Arena* arena);
void ArenaImpl_SetFillAllocBlock(Arena* arena);
void ArenaImpl_SetFillFreeBlock(Arena* arena);
void ArenaImpl_Unlock(Arena* arena);
void ArenaImpl_UnsetCheckFreeBlock(Arena* arena);
void ArenaImpl_UnsetFillAllocBlock(Arena* arena);
void ArenaImpl_UnsetFillFreeBlock(Arena* arena);
u32 __osCheckArena(Arena* arena);
void __osDisplayArena(Arena* arena);
void __osFree(Arena* arena, void* ptr);
void __osFreeDebug(Arena* arena, void* ptr, const char* file, s32 line);
void __osFree_NoLock(Arena* arena, void* ptr);
void __osFree_NoLockDebug(Arena* arena, void* ptr, const char* file, s32 line);
void* __osMalloc(Arena* arena, u32 size);
void __osMallocAddBlock(Arena* arena, void* start, s32 size);
void __osMallocCleanup(Arena* arena);
void* __osMallocDebug(Arena* arena, u32 size, const char* file, s32 line);
void __osMallocInit(Arena* arena, void* start, u32 size);
u8 __osMallocIsInitalized(Arena* arena);
void* __osMallocR(Arena* arena, u32 size);
void* __osMallocRDebug(Arena* arena, u32 size, const char* file, s32 line);
void __osMalloc_FreeBlockTest(Arena* arena, ArenaNode* node);
void* __osMalloc_NoLock(Arena* arena, u32 size);
void* __osMalloc_NoLockDebug(Arena* arena, u32 size, const char* file, s32 line);
void* __osRealloc(Arena* arena, void* ptr, u32 newSize);
void* __osReallocDebug(Arena* arena, void* ptr, u32 newSize, const char* file, s32 line);
u8 func_800FF334(Arena* arena);
#else
void ArenaImpl_FaultClient(struct Arena* arena);
u32 ArenaImpl_GetCheckFreeBlock(struct Arena* arena);
u32 ArenaImpl_GetFillAllocBlock(struct Arena* arena);
u32 ArenaImpl_GetFillFreeBlock(struct Arena* arena);
struct ArenaNode* ArenaImpl_GetLastBlock(struct Arena* arena);
struct ArenaNode* ArenaImpl_GetNextBlock(struct ArenaNode* node);
struct ArenaNode* ArenaImpl_GetPrevBlock(struct ArenaNode* node);
void ArenaImpl_GetSizes(struct Arena* arena, u32* outMaxFree, u32* outFree, u32* outAlloc);
void ArenaImpl_Lock(struct Arena* arena);
void ArenaImpl_LockInit(struct Arena* arena);
void ArenaImpl_RemoveAllBlocks(struct Arena* arena);
void ArenaImpl_SetCheckFreeBlock(struct Arena* arena);
void ArenaImpl_SetDebugInfo(struct ArenaNode* node, const char* file, s32 line, struct Arena* arena);
void ArenaImpl_SetFillAllocBlock(struct Arena* arena);
void ArenaImpl_SetFillFreeBlock(struct Arena* arena);
void ArenaImpl_Unlock(struct Arena* arena);
void ArenaImpl_UnsetCheckFreeBlock(struct Arena* arena);
void ArenaImpl_UnsetFillAllocBlock(struct Arena* arena);
void ArenaImpl_UnsetFillFreeBlock(struct Arena* arena);
u32 __osCheckArena(struct Arena* arena);
void __osDisplayArena(struct Arena* arena);
void __osFree(struct Arena* arena, void* ptr);
void __osFreeDebug(struct Arena* arena, void* ptr, const char* file, s32 line);
void __osFree_NoLock(struct Arena* arena, void* ptr);
void __osFree_NoLockDebug(struct Arena* arena, void* ptr, const char* file, s32 line);
void* __osMalloc(struct Arena* arena, u32 size);
void __osMallocAddBlock(struct Arena* arena, void* start, s32 size);
void __osMallocCleanup(struct Arena* arena);
void* __osMallocDebug(struct Arena* arena, u32 size, const char* file, s32 line);
void __osMallocInit(struct Arena* arena, void* start, u32 size);
u8 __osMallocIsInitalized(struct Arena* arena);
void* __osMallocR(struct Arena* arena, u32 size);
void* __osMallocRDebug(struct Arena* arena, u32 size, const char* file, s32 line);
void __osMalloc_FreeBlockTest(struct Arena* arena, struct ArenaNode* node);
void* __osMalloc_NoLock(struct Arena* arena, u32 size);
void* __osMalloc_NoLockDebug(struct Arena* arena, u32 size, const char* file, s32 line);
void* __osRealloc(struct Arena* arena, void* ptr, u32 newSize);
void* __osReallocDebug(struct Arena* arena, void* ptr, u32 newSize, const char* file, s32 line);
u8 func_800FF334(struct Arena* arena);
#endif
#endif
