#pragma once

extern FaultThreadStruct gFaultStruct;

#ifdef INTERNAL_SRC_CODE_FAULT_C
void Fault_AddAddrConvClient(FaultAddrConvClient*, void*, void*);
void Fault_AddClient(FaultClient*, void*, void*, void*);
void Fault_AddHungupAndCrash(const char*, u32);
void Fault_AddHungupAndCrashImpl(const char*, const char*);
void Fault_ClientProcessThread(void* arg);
void Fault_CommitFB();
u32 Fault_ConvertAddress(FaultAddrConvClient*);
void Fault_DrawCornerRec(u16);
void Fault_DrawMemDump(u32, u32, u32, u32);
void Fault_DrawMemDumpPage(const char*, u32*, u32);
void Fault_DrawRec(s32, s32, s32, s32, u16);
void Fault_DrawStackTrace(OSThread* thread, s32 x, s32 y, s32 height);
void Fault_FillScreenBlack();
void Fault_FillScreenRed();
OSThread* Fault_FindFaultedThread();
void Fault_HangupFaultClient(const char*, const char*);
void Fault_Init(void);
void Fault_LogFPCR(u32);
void Fault_LogFReg(s32, f32*);
void Fault_LogStackTrace(OSThread* thread, s32 height);
void Fault_LogThreadContext(OSThread*);
void Fault_PadCallback(Input*);
void Fault_PrintFPCR(u32);
void Fault_PrintFReg(s32, f32*);
void Fault_PrintThreadContext(OSThread*);
u32 Fault_ProcessClient(u32, u32, u32);
void Fault_ProcessClientContext(FaultClientContext*);
void Fault_ProcessClients();
void Fault_RemoveAddrConvClient(FaultAddrConvClient*);
void Fault_RemoveClient(FaultClient*);
void Fault_ResumeThread(OSThread*);
void Fault_SetFB(void*, u16, u16);
void Fault_Sleep(u32);
void Fault_SleepImpl(u32);
void Fault_ThreadEntry(void*);
void Fault_UpdatePad();
void Fault_UpdatePadImpl();
void Fault_Wait5Seconds();
void Fault_WaitForButtonCombo();
void Fault_WaitForInput();
u32 Fault_WaitForInputImpl();
void Fault_WalkStack(u32* spPtr, u32* pcPtr, u32* raPtr);
#else
void Fault_AddAddrConvClient(struct FaultAddrConvClient*, void*, void*);
void Fault_AddClient(struct FaultClient*, void*, void*, void*);
void Fault_AddHungupAndCrash(const char*, u32);
void Fault_AddHungupAndCrashImpl(const char*, const char*);
void Fault_ClientProcessThread(void* arg);
void Fault_CommitFB(void);
u32 Fault_ConvertAddress(struct FaultAddrConvClient*);
void Fault_DrawCornerRec(u16);
void Fault_DrawMemDump(u32, u32, u32, u32);
void Fault_DrawMemDumpPage(const char*, u32*, u32);
void Fault_DrawRec(s32, s32, s32, s32, u16);
void Fault_DrawStackTrace(struct OSThread* thread, s32 x, s32 y, s32 height);
void Fault_FillScreenBlack(void);
void Fault_FillScreenRed(void);
struct OSThread* Fault_FindFaultedThread(void);
void Fault_HangupFaultClient(const char*, const char*);
void Fault_Init(void);
void Fault_LogFPCR(u32);
void Fault_LogFReg(s32, f32*);
void Fault_LogStackTrace(struct OSThread* thread, s32 height);
void Fault_LogThreadContext(struct OSThread*);
void Fault_PadCallback(struct Input*);
void Fault_PrintFPCR(u32);
void Fault_PrintFReg(s32, f32*);
void Fault_PrintThreadContext(struct OSThread*);
u32 Fault_ProcessClient(u32, u32, u32);
void Fault_ProcessClientContext(struct FaultClientContext*);
void Fault_ProcessClients(void);
void Fault_RemoveAddrConvClient(struct FaultAddrConvClient*);
void Fault_RemoveClient(struct FaultClient*);
void Fault_ResumeThread(struct OSThread*);
void Fault_SetFB(void*, u16, u16);
void Fault_Sleep(u32);
void Fault_SleepImpl(u32);
void Fault_ThreadEntry(void*);
void Fault_UpdatePad(void);
void Fault_UpdatePadImpl(void);
void Fault_Wait5Seconds(void);
void Fault_WaitForButtonCombo(void);
void Fault_WaitForInput(void);
u32 Fault_WaitForInputImpl(void);
void Fault_WalkStack(u32* spPtr, u32* pcPtr, u32* raPtr);
#endif
