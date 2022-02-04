#pragma once
void* THA_GetHead(TwoHeadArena* tha);
void THA_SetHead(TwoHeadArena* tha, void* start);
void* THA_GetTail(TwoHeadArena* tha);
void* THA_AllocStart(TwoHeadArena* tha, u32 size);
void* THA_AllocStart1(TwoHeadArena* tha);
void* THA_AllocEnd(TwoHeadArena* tha, u32 size);
void* THA_AllocEndAlign16(TwoHeadArena* tha, u32 size);
void* THA_AllocEndAlign(TwoHeadArena* tha, u32 size, uintptr_t mask);
s32 THA_GetSize(TwoHeadArena* tha);
u32 THA_IsCrash(TwoHeadArena* tha);
void THA_Init(TwoHeadArena* tha);
void THA_Ct(TwoHeadArena* tha, void* ptr, u32 size);
void THA_Dt(TwoHeadArena* tha);
