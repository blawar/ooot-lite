#pragma once

extern u32 D_80009460;
extern u32 gDmaMgrDmaBuffSize;

s32 DmaMgr_CompareName(const char* name1, const char* name2);
s32 DmaMgr_DmaHandler(OSPiHandle* pihandle, OSIoMesg* mb, s32 direction);
s32 DmaMgr_DmaRomToRam(void* rom, void* ram, uintptr_t size);
void DmaMgr_Error(DmaRequest* req, const char* file, const char* errorName, const char* errorDesc);
const char* DmaMgr_GetFileName(const void* vrom);
const char* DmaMgr_GetFileNameImpl(const void* vrom);
void DmaMgr_Init(void);
void DmaMgr_ProcessMsg(DmaRequest* req);
s32 DmaMgr_SendRequest0(void* ram, const void* vrom, uintptr_t size);
s32 DmaMgr_SendRequest1(void* ram0, const void* vrom, uintptr_t size, const char* file, s32 line);
s32 DmaMgr_SendRequest2(DmaRequest* req, void* ram, const void* vrom, uintptr_t size, u32 unk5, OSMesgQueue* queue, OSMesg msg, const char* file, s32 line);
s32 DmaMgr_SendRequestImpl(DmaRequest* req, void* ram, const void* vrom, uintptr_t size, u32 unk, OSMesgQueue* queue, OSMesg msg);
void DmaMgr_ThreadEntry(void* arg0);