#pragma once
struct WeaponInfo;

extern Gfx* D_80125DE8[];
extern Gfx* D_80125E08[];
extern Gfx* D_80125E18[];
extern Gfx* D_80125EF8[];
extern Gfx gCullBackDList[];
extern Gfx gCullFrontDList[];
extern u8 gPlayerModelTypes[][5];
extern FlexSkeletonHeader* gPlayerSkelHeaders[2];

#ifdef INTERNAL_SRC_CODE_Z_PLAYER_LIB_C
s32 Player_ActionToBottle(Player* player, s32 actionParam);
s32 Player_ActionToExplosive(Player* player, s32 actionParam);
s32 Player_ActionToMagicSpell(Player* player, s32 actionParam);
s32 Player_ActionToModelGroup(Player* player, s32 actionParam);
s32 Player_ActionToSword(s32 actionParam);
void Player_DrawGetItem(GlobalContext* globalCtx, Player* player);
s32 Player_GetBottleHeld(Player* player);
s32 Player_GetExplosiveHeld(Player* player);
u8 Player_GetMask(GlobalContext* globalCtx);
s32 Player_GetStrength(void);
s32 Player_GetSwordHeld(Player* player);
s32 Player_HasMirrorShieldEquipped(GlobalContext* globalCtx);
s32 Player_HasMirrorShieldSetToDraw(GlobalContext* globalCtx);
s32 Player_HoldsBrokenKnife(Player* player);
s32 Player_HoldsHookshot(Player* player);
s32 Player_HoldsTwoHandedWeapon(Player* player);
s32 Player_InBlockingCsMode(GlobalContext* globalCtx, Player* player);
s32 Player_InCsMode(GlobalContext* globalCtx);
s32 Player_IsBurningStickInRange(GlobalContext* globalCtx, Vec3f* pos, f32 radius, f32 arg3);
s32 Player_IsChildWithHylianShield(Player* player);
void Player_SetBootData(GlobalContext* globalCtx, Player* player);
void Player_SetEquipmentData(GlobalContext* globalCtx, Player* player);
void Player_SetModelGroup(Player* player, s32 modelGroup);
void Player_SetModels(Player* player, s32 modelGroup);
void Player_SetModelsForHoldingShield(Player* player);
Player* Player_UnsetMask(GlobalContext* globalCtx);
void Player_UpdateBottleHeld(GlobalContext* globalCtx, Player* player, s32 item, s32 actionParam);
s32 func_8008E9C4(Player* player);
void func_8008EC70(Player* player);
void func_8008EDF0(Player* player);
void func_8008EE08(Player* player);
void func_8008EEAC(GlobalContext* globalCtx, Actor* actor);
s32 func_8008EF44(GlobalContext* globalCtx, s32 ammo);
s32 func_8008F128(Player* player);
s32 func_8008F2BC(Player* player, s32 actionParam);
s32 func_8008F2F8(GlobalContext* globalCtx);
void func_8008F470(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, s32 dListCount, s32 lod, s32 tunic, s32 boots, s32 face, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* this);
s32 func_8008FCC8(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
s32 func_80090014(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
s32 func_800902F0(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
s32 func_80090440(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
u8 func_80090480(GlobalContext* globalCtx, ColliderQuad* collider, WeaponInfo* weaponDim, Vec3f* newTip, Vec3f* newBase);
void func_80090D20(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* data);
u32 func_80091738(GlobalContext* globalCtx, u8* segment, SkelAnime* skelAnime);
void func_8009214C(GlobalContext* globalCtx, u8* segment, SkelAnime* skelAnime, Vec3f* pos, Vec3s* rot, f32 scale, s32 sword, s32 tunic, s32 shield, s32 boots);
#else
s32 Player_ActionToBottle(struct Player* player, s32 actionParam);
s32 Player_ActionToExplosive(struct Player* player, s32 actionParam);
s32 Player_ActionToMagicSpell(struct Player* player, s32 actionParam);
s32 Player_ActionToModelGroup(struct Player* player, s32 actionParam);
s32 Player_ActionToSword(s32 actionParam);
void Player_DrawGetItem(struct GlobalContext* globalCtx, struct Player* player);
s32 Player_GetBottleHeld(struct Player* player);
s32 Player_GetExplosiveHeld(struct Player* player);
u8 Player_GetMask(struct GlobalContext* globalCtx);
s32 Player_GetStrength(void);
s32 Player_GetSwordHeld(struct Player* player);
s32 Player_HasMirrorShieldEquipped(struct GlobalContext* globalCtx);
s32 Player_HasMirrorShieldSetToDraw(struct GlobalContext* globalCtx);
s32 Player_HoldsBrokenKnife(struct Player* player);
s32 Player_HoldsHookshot(struct Player* player);
s32 Player_HoldsTwoHandedWeapon(struct Player* player);
s32 Player_InBlockingCsMode(struct GlobalContext* globalCtx, struct Player* player);
s32 Player_InCsMode(struct GlobalContext* globalCtx);
s32 Player_IsBurningStickInRange(struct GlobalContext* globalCtx, struct Vec3f* pos, f32 radius, f32 arg3);
s32 Player_IsChildWithHylianShield(struct Player* player);
void Player_SetBootData(struct GlobalContext* globalCtx, struct Player* player);
void Player_SetEquipmentData(struct GlobalContext* globalCtx, struct Player* player);
void Player_SetModelGroup(struct Player* player, s32 modelGroup);
void Player_SetModels(struct Player* player, s32 modelGroup);
void Player_SetModelsForHoldingShield(struct Player* player);
struct Player* Player_UnsetMask(struct GlobalContext* globalCtx);
void Player_UpdateBottleHeld(struct GlobalContext* globalCtx, struct Player* player, s32 item, s32 actionParam);
s32 func_8008E9C4(struct Player* player);
void func_8008EC70(struct Player* player);
void func_8008EDF0(struct Player* player);
void func_8008EE08(struct Player* player);
void func_8008EEAC(struct GlobalContext* globalCtx, struct Actor* actor);
s32 func_8008EF44(struct GlobalContext* globalCtx, s32 ammo);
s32 func_8008F128(struct Player* player);
s32 func_8008F2BC(struct Player* player, s32 actionParam);
s32 func_8008F2F8(struct GlobalContext* globalCtx);
void func_8008F470(struct GlobalContext* globalCtx, void** skeleton, struct Vec3s* jointTable, s32 dListCount, s32 lod, s32 tunic, s32 boots, s32 face, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* this);
s32 func_8008FCC8(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, struct Vec3f* pos, struct Vec3s* rot, void* data);
s32 func_80090014(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, struct Vec3f* pos, struct Vec3s* rot, void* data);
s32 func_800902F0(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, struct Vec3f* pos, struct Vec3s* rot, void* data);
s32 func_80090440(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, struct Vec3f* pos, struct Vec3s* rot, void* data);
u8 func_80090480(struct GlobalContext* globalCtx, struct ColliderQuad* collider, struct WeaponInfo* weaponDim, struct Vec3f* newTip, struct Vec3f* newBase);
void func_80090D20(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, struct Vec3s* rot, void* data);
u32 func_80091738(struct GlobalContext* globalCtx, u8* segment, struct SkelAnime* skelAnime);
void func_8009214C(struct GlobalContext* globalCtx, u8* segment, struct SkelAnime* skelAnime, struct Vec3f* pos, struct Vec3s* rot, f32 scale, s32 sword, s32 tunic, s32 shield, s32 boots);
#endif
