#pragma once

extern u8 gBossMarkState;
#if defined(KEEP_OVERLAYS)
extern KaleidoMgrOverlay* gKaleidoMgrCurOvl;
extern KaleidoMgrOverlay gKaleidoMgrOverlayTable[KALEIDO_OVL_MAX];

#ifdef INTERNAL_SRC_CODE_Z_KALEIDO_MANAGER_C
void KaleidoManager_ClearOvl(KaleidoMgrOverlay* ovl);
void KaleidoManager_Destroy();
//void* KaleidoManager_GetRamAddr(void* vram);
void KaleidoManager_Init(GlobalContext* globalCtx);
void KaleidoManager_LoadOvl(KaleidoMgrOverlay* ovl);
#else
void KaleidoManager_ClearOvl(struct KaleidoMgrOverlay* ovl);
void KaleidoManager_Destroy(void);
//void* KaleidoManager_GetRamAddr(void* vram);
void KaleidoManager_Init(struct GlobalContext* globalCtx);
void KaleidoManager_LoadOvl(struct KaleidoMgrOverlay* ovl);
#endif
#else
extern KaleidoOverlayType gKaleidoMgrCurOvl;
extern KaleidoOverlayType gKaleidoMgrOverlayTable[KALEIDO_OVL_MAX];

#ifdef INTERNAL_SRC_CODE_Z_KALEIDO_MANAGER_C
void KaleidoManager_ClearOvl(KaleidoOverlayType ovl);
void KaleidoManager_Destroy();
void KaleidoManager_Init(GlobalContext* globalCtx);
void KaleidoManager_LoadOvl(KaleidoOverlayType ovl);
#else
void KaleidoManager_ClearOvl(KaleidoOverlayType ovl);
void KaleidoManager_Destroy(void);
void KaleidoManager_Init(struct GlobalContext* globalCtx);
void KaleidoManager_LoadOvl(KaleidoOverlayType ovl);
#endif
#endif
