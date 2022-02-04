#pragma once

extern void* D_8012D1F0;
extern Color_RGBA8_u32 D_801614B0;
extern s32 gTrnsnUnkState;

#ifdef INTERNAL_SRC_CODE_Z_PLAY_C
s32 FrameAdvance_IsEnabled(GlobalContext* globalCtx);
s32 Gameplay_CameraChangeSetting(GlobalContext* globalCtx, s16 camId, s16 arg2);
s32 Gameplay_CameraSetAtEye(GlobalContext* globalCtx, s16 camId, Vec3f* at, Vec3f* eye);
s32 Gameplay_CameraSetAtEyeUp(GlobalContext* globalCtx, s16 camId, Vec3f* at, Vec3f* eye, Vec3f* up);
s32 Gameplay_CameraSetFov(GlobalContext* globalCtx, s16 camId, f32 fov);
s16 Gameplay_ChangeCameraStatus(GlobalContext* globalCtx, s16 camId, s16 status);
void Gameplay_ClearAllSubCameras(GlobalContext* globalCtx);
void Gameplay_ClearCamera(GlobalContext* globalCtx, s16 camId);
void Gameplay_CopyCamera(GlobalContext* globalCtx, s16 camId1, s16 camId2);
s16 Gameplay_CreateSubCamera(GlobalContext* globalCtx);
void Gameplay_Destroy(GameState* thisx);
s16 Gameplay_GetActiveCamId(GlobalContext* globalCtx);
Camera* Gameplay_GetCamera(GlobalContext* globalCtx, s16 camId);
s32 Gameplay_InCsMode(GlobalContext* globalCtx);
void Gameplay_Init(GameState* thisx);
void* Gameplay_LoadFile(GlobalContext* globalCtx, RomFile* file);
void Gameplay_Main(GameState* thisx);
void Gameplay_SaveSceneFlags(GlobalContext* globalCtx);
s32 Gameplay_SetCameraRoll(GlobalContext* globalCtx, s16 camId, s16 roll);
Gfx* Gameplay_SetFog(GlobalContext* globalCtx, Gfx* gfx);
void Gameplay_SetupRespawnPoint(GlobalContext* globalCtx, s32 respawnMode, s32 playerParams);
void Gameplay_SpawnScene(GlobalContext* globalCtx, s32 sceneNum, s32 spawn);
void Gameplay_TriggerRespawn(GlobalContext* globalCtx);
void Gameplay_TriggerVoidOut(GlobalContext* globalCtx);
void func_800BC490(GlobalContext* globalCtx, s16 point);
s32 func_800BC56C(GlobalContext* globalCtx, s16 arg1);
void func_800BC590(GlobalContext* globalCtx);
void func_800BC5E0(GlobalContext* globalCtx, s32 arg1);
f32 func_800BFCB8(GlobalContext* globalCtx, MtxF* mf, Vec3f* vec);
void func_800C016C(GlobalContext* globalCtx, Vec3f* src, Vec3f* dest);
s32 func_800C0808(GlobalContext* globalCtx, s16 camId, Player* player, s16 arg3);
void func_800C08AC(GlobalContext* globalCtx, s16 camId, s16 arg2);
s32 func_800C0CB8(GlobalContext* globalCtx);
s32 func_800C0D34(GlobalContext* globalCtx, Actor* actor, s16* yaw);
s32 func_800C0DB4(GlobalContext* globalCtx, Vec3f* pos);
#else
s32 FrameAdvance_IsEnabled(struct GlobalContext* globalCtx);
s32 Gameplay_CameraChangeSetting(struct GlobalContext* globalCtx, s16 camId, s16 arg2);
s32 Gameplay_CameraSetAtEye(struct GlobalContext* globalCtx, s16 camId, struct Vec3f* at, struct Vec3f* eye);
s32 Gameplay_CameraSetAtEyeUp(struct GlobalContext* globalCtx, s16 camId, struct Vec3f* at, struct Vec3f* eye, struct Vec3f* up);
s32 Gameplay_CameraSetFov(struct GlobalContext* globalCtx, s16 camId, f32 fov);
s16 Gameplay_ChangeCameraStatus(struct GlobalContext* globalCtx, s16 camId, s16 status);
void Gameplay_ClearAllSubCameras(struct GlobalContext* globalCtx);
void Gameplay_ClearCamera(struct GlobalContext* globalCtx, s16 camId);
void Gameplay_CopyCamera(struct GlobalContext* globalCtx, s16 camId1, s16 camId2);
s16 Gameplay_CreateSubCamera(struct GlobalContext* globalCtx);
void Gameplay_Destroy(struct GameState* thisx);
s16 Gameplay_GetActiveCamId(struct GlobalContext* globalCtx);
struct Camera* Gameplay_GetCamera(struct GlobalContext* globalCtx, s16 camId);
s32 Gameplay_InCsMode(struct GlobalContext* globalCtx);
void Gameplay_Init(struct GameState* thisx);
void* Gameplay_LoadFile(struct GlobalContext* globalCtx, struct RomFile* file);
void Gameplay_Main(struct GameState* thisx);
void Gameplay_SaveSceneFlags(struct GlobalContext* globalCtx);
s32 Gameplay_SetCameraRoll(struct GlobalContext* globalCtx, s16 camId, s16 roll);
Gfx* Gameplay_SetFog(struct GlobalContext* globalCtx, Gfx* gfx);
void Gameplay_SetupRespawnPoint(struct GlobalContext* globalCtx, s32 respawnMode, s32 playerParams);
void Gameplay_SpawnScene(struct GlobalContext* globalCtx, s32 sceneNum, s32 spawn);
void Gameplay_TriggerRespawn(struct GlobalContext* globalCtx);
void Gameplay_TriggerVoidOut(struct GlobalContext* globalCtx);
void func_800BC490(struct GlobalContext* globalCtx, s16 point);
s32 func_800BC56C(struct GlobalContext* globalCtx, s16 arg1);
void func_800BC590(struct GlobalContext* globalCtx);
void func_800BC5E0(struct GlobalContext* globalCtx, s32 arg1);
f32 func_800BFCB8(struct GlobalContext* globalCtx, MtxF* mf, struct Vec3f* vec);
void func_800C016C(struct GlobalContext* globalCtx, struct Vec3f* src, struct Vec3f* dest);
s32 func_800C0808(struct GlobalContext* globalCtx, s16 camId, struct Player* player, s16 arg3);
void func_800C08AC(struct GlobalContext* globalCtx, s16 camId, s16 arg2);
s32 func_800C0CB8(struct GlobalContext* globalCtx);
s32 func_800C0D34(struct GlobalContext* globalCtx, struct Actor* actor, s16* yaw);
s32 func_800C0DB4(struct GlobalContext* globalCtx, struct Vec3f* pos);
#endif
