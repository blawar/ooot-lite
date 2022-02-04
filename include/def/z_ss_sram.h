#pragma once
#if defined(OS_DESKTOP)
void SsSram_Dma(void* dramAddr, size_t size, s32 direction);
void SsSram_Init(void* addr, u8 handleType, u8 handleDomain, u8 handleLatency, u8 handlePageSize, u8 handleRelDuration, u8 handlePulse, u32 handleSpeed);
void SsSram_ReadWrite(u32 addr, void* dramAddr, size_t size, s32 direction);
#elif defined(INTERNAL_SRC_CODE_Z_SS_SRAM_C)
void SsSram_Dma(void* dramAddr, size_t size, s32 direction);
void SsSram_Init(u32 addr, u8 handleType, u8 handleDomain, u8 handleLatency, u8 handlePageSize, u8 handleRelDuration, u8 handlePulse, u32 handleSpeed);
void SsSram_ReadWrite(u32 addr, void* dramAddr, size_t size, s32 direction);
#else
void SsSram_Dma(void* dramAddr, size_t size, s32 direction);
void SsSram_Init(u32 addr, u8 handleType, u8 handleDomain, u8 handleLatency, u8 handlePageSize, u8 handleRelDuration, u8 handlePulse, u32 handleSpeed);
void SsSram_ReadWrite(u32 addr, void* dramAddr, size_t size, s32 direction);
#endif
