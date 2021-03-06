#pragma once
#ifdef INTERNAL_SRC_CODE_Z_SKELANIME_C
void AnimationContext_DisableQueue(GlobalContext* globalCtx);
void AnimationContext_Reset(AnimationContext* animationCtx);
void AnimationContext_SetCopyAll(GlobalContext* globalCtx, s32 vecCount, Vec3s* dst, Vec3s* src);
void AnimationContext_SetCopyFalse(GlobalContext* globalCtx, s32 vecCount, Vec3s* dst, Vec3s* src, u8* copyFlag);
void AnimationContext_SetCopyTrue(GlobalContext* globalCtx, s32 vecCount, Vec3s* dst, Vec3s* src, u8* copyFlag);
void AnimationContext_SetInterp(GlobalContext* globalCtx, s32 vecCount, Vec3s* base, Vec3s* mod, f32 weight);
void AnimationContext_SetLoadFrame(GlobalContext* globalCtx, LinkAnimationHeader* animation, s32 frame, s32 limbCount, Vec3s* frameTable);
void AnimationContext_SetMoveActor(GlobalContext* globalCtx, Actor* actor, SkelAnime* skelAnime, f32 arg3);
void AnimationContext_SetNextQueue(GlobalContext* globalCtx);
void AnimationContext_Update(GlobalContext* globalCtx, AnimationContext* animationCtx);
void Animation_Change(SkelAnime* skelAnime, AnimationHeader* animation, f32 playSpeed, f32 startFrame, f32 endFrame, u8 mode, f32 morphFrames);
void Animation_ChangeImpl(SkelAnime* skelAnime, AnimationHeader* animation, f32 playSpeed, f32 startFrame, f32 endFrame, u8 mode, f32 morphFrames, s8 taper);
void Animation_EndLoop(SkelAnime* skelAnime);
s16 Animation_GetLastFrame(void* animation);
s16 Animation_GetLastFrameLegacy(LegacyAnimationHeader* animation);
s16 Animation_GetLength(void* animation);
s16 Animation_GetLengthLegacy(LegacyAnimationHeader* animation);
s16 Animation_GetLimbCountLegacy(LegacyAnimationHeader* animation);
void Animation_MorphToLoop(SkelAnime* skelAnime, AnimationHeader* animation, f32 morphFrames);
void Animation_MorphToPlayOnce(SkelAnime* skelAnime, AnimationHeader* animation, f32 morphFrames);
s32 Animation_OnFrame(SkelAnime* skelAnime, f32 frame);
void Animation_PlayLoop(SkelAnime* skelAnime, AnimationHeader* animation);
void Animation_PlayLoopSetSpeed(SkelAnime* skelAnime, AnimationHeader* animation, f32 playSpeed);
void Animation_PlayOnce(SkelAnime* skelAnime, AnimationHeader* animation);
void Animation_PlayOnceSetSpeed(SkelAnime* skelAnime, AnimationHeader* animation, f32 playSpeed);
void Animation_Reverse(SkelAnime* skelAnime);
void Animation_SetMorph(GlobalContext* globalCtx, SkelAnime* skelAnime, f32 morphFrames);
void LinkAnimation_AnimateFrame(GlobalContext* globalCtx, SkelAnime* skelAnime);
void LinkAnimation_BlendToJoint(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation1, f32 frame1, LinkAnimationHeader* animation2, f32 frame2, f32 weight, Vec3s* blendTable);
void LinkAnimation_BlendToMorph(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation1, f32 frame1, LinkAnimationHeader* animation2, f32 frame2, f32 weight, Vec3s* blendTable);
void LinkAnimation_Change(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation, f32 playSpeed, f32 startFrame, f32 endFrame, u8 mode, f32 morphFrames);
void LinkAnimation_CopyJointToMorph(GlobalContext* globalCtx, SkelAnime* skelAnime);
void LinkAnimation_CopyMorphToJoint(GlobalContext* globalCtx, SkelAnime* skelAnime);
void LinkAnimation_EndLoop(SkelAnime* skelAnime);
void LinkAnimation_InterpJointMorph(GlobalContext* globalCtx, SkelAnime* skelAnime, f32 frame);
void LinkAnimation_LoadToJoint(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation, f32 frame);
void LinkAnimation_LoadToMorph(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation, f32 frame);
s32 LinkAnimation_OnFrame(SkelAnime* skelAnime, f32 frame);
void LinkAnimation_PlayLoop(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation);
void LinkAnimation_PlayLoopSetSpeed(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation, f32 playSpeed);
void LinkAnimation_PlayOnce(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation);
void LinkAnimation_PlayOnceSetSpeed(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation, f32 playSpeed);
void LinkAnimation_SetUpdateFunction(SkelAnime* skelAnime);
s32 LinkAnimation_Update(GlobalContext* globalCtx, SkelAnime* skelAnime);
void SkelAnime_CopyFrameTable(SkelAnime* skelAnime, Vec3s* dst, Vec3s* src);
void SkelAnime_CopyFrameTableFalse(SkelAnime* skelAnime, Vec3s* dst, Vec3s* src, u8* copyFlag);
void SkelAnime_CopyFrameTableTrue(SkelAnime* skelAnime, Vec3s* dst, Vec3s* src, u8* copyFlag);
Gfx* SkelAnime_Draw(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* arg, Gfx* gfx);
Gfx* SkelAnime_DrawFlex(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, s32 dListCount, OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* arg, Gfx* gfx);
void SkelAnime_DrawFlexLod(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, s32 dListCount, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, s32 dListIndex);
void SkelAnime_DrawFlexOpa(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, s32 dListCount, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg);
void SkelAnime_DrawLod(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, s32 dListIndex);
void SkelAnime_DrawOpa(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg);
void SkelAnime_Free(SkelAnime* skelAnime, GlobalContext* globalCtx);
s32 SkelAnime_GetFrameDataLegacy(LegacyAnimationHeader* animation, s32 frame, Vec3s* frameTable);
s32 SkelAnime_Init(GlobalContext* globalCtx, SkelAnime* skelAnime, SkeletonHeader* skeletonHeaderSeg, AnimationHeader* animation, Vec3s* jointTable, Vec3s* morphTable, s32 limbCount);
s32 SkelAnime_InitFlex(GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeaderSeg, AnimationHeader* animation, Vec3s* jointTable, Vec3s* morphTable, s32 limbCount);
void SkelAnime_InitLink(GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeaderSeg, LinkAnimationHeader* animation, s32 initFlags, Vec3s* jointTable, Vec3s* morphTable, s32 limbCount);
s32 SkelAnime_InitSkin(GlobalContext* globalCtx, SkelAnime* skelAnime, SkeletonHeader* skeletonHeaderSeg, AnimationHeader* animation);
void SkelAnime_InterpFrameTable(s32 limbCount, Vec3s* dst, Vec3s* start, Vec3s* target, f32 weight);
s32 SkelAnime_Update(SkelAnime* skelAnime);
void SkelAnime_UpdateTranslation(SkelAnime* skelAnime, Vec3f* pos, s16 angle);
#else
void AnimationContext_DisableQueue(struct GlobalContext* globalCtx);
void AnimationContext_Reset(struct AnimationContext* animationCtx);
void AnimationContext_SetCopyAll(struct GlobalContext* globalCtx, s32 vecCount, struct Vec3s* dst, struct Vec3s* src);
void AnimationContext_SetCopyFalse(struct GlobalContext* globalCtx, s32 vecCount, struct Vec3s* dst, struct Vec3s* src, u8* copyFlag);
void AnimationContext_SetCopyTrue(struct GlobalContext* globalCtx, s32 vecCount, struct Vec3s* dst, struct Vec3s* src, u8* copyFlag);
void AnimationContext_SetInterp(struct GlobalContext* globalCtx, s32 vecCount, struct Vec3s* base, struct Vec3s* mod, f32 weight);
void AnimationContext_SetLoadFrame(struct GlobalContext* globalCtx, struct LinkAnimationHeader* animation, s32 frame, s32 limbCount, struct Vec3s* frameTable);
void AnimationContext_SetMoveActor(struct GlobalContext* globalCtx, struct Actor* actor, struct SkelAnime* skelAnime, f32 arg3);
void AnimationContext_SetNextQueue(struct GlobalContext* globalCtx);
void AnimationContext_Update(struct GlobalContext* globalCtx, struct AnimationContext* animationCtx);
void Animation_Change(struct SkelAnime* skelAnime, struct AnimationHeader* animation, f32 playSpeed, f32 startFrame, f32 endFrame, u8 mode, f32 morphFrames);
void Animation_ChangeImpl(struct SkelAnime* skelAnime, struct AnimationHeader* animation, f32 playSpeed, f32 startFrame, f32 endFrame, u8 mode, f32 morphFrames, s8 taper);
void Animation_EndLoop(struct SkelAnime* skelAnime);
s16 Animation_GetLastFrame(void* animation);
s16 Animation_GetLastFrameLegacy(struct LegacyAnimationHeader* animation);
s16 Animation_GetLength(void* animation);
s16 Animation_GetLengthLegacy(struct LegacyAnimationHeader* animation);
s16 Animation_GetLimbCountLegacy(struct LegacyAnimationHeader* animation);
void Animation_MorphToLoop(struct SkelAnime* skelAnime, struct AnimationHeader* animation, f32 morphFrames);
void Animation_MorphToPlayOnce(struct SkelAnime* skelAnime, struct AnimationHeader* animation, f32 morphFrames);
s32 Animation_OnFrame(struct SkelAnime* skelAnime, f32 frame);
void Animation_PlayLoop(struct SkelAnime* skelAnime, struct AnimationHeader* animation);
void Animation_PlayLoopSetSpeed(struct SkelAnime* skelAnime, struct AnimationHeader* animation, f32 playSpeed);
void Animation_PlayOnce(struct SkelAnime* skelAnime, struct AnimationHeader* animation);
void Animation_PlayOnceSetSpeed(struct SkelAnime* skelAnime, struct AnimationHeader* animation, f32 playSpeed);
void Animation_Reverse(struct SkelAnime* skelAnime);
void Animation_SetMorph(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, f32 morphFrames);
void LinkAnimation_AnimateFrame(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime);
void LinkAnimation_BlendToJoint(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct LinkAnimationHeader* animation1, f32 frame1, struct LinkAnimationHeader* animation2, f32 frame2, f32 weight, struct Vec3s* blendTable);
void LinkAnimation_BlendToMorph(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct LinkAnimationHeader* animation1, f32 frame1, struct LinkAnimationHeader* animation2, f32 frame2, f32 weight, struct Vec3s* blendTable);
void LinkAnimation_Change(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct LinkAnimationHeader* animation, f32 playSpeed, f32 startFrame, f32 endFrame, u8 mode, f32 morphFrames);
void LinkAnimation_CopyJointToMorph(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime);
void LinkAnimation_CopyMorphToJoint(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime);
void LinkAnimation_EndLoop(struct SkelAnime* skelAnime);
void LinkAnimation_InterpJointMorph(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, f32 frame);
void LinkAnimation_LoadToJoint(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct LinkAnimationHeader* animation, f32 frame);
void LinkAnimation_LoadToMorph(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct LinkAnimationHeader* animation, f32 frame);
s32 LinkAnimation_OnFrame(struct SkelAnime* skelAnime, f32 frame);
void LinkAnimation_PlayLoop(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct LinkAnimationHeader* animation);
void LinkAnimation_PlayLoopSetSpeed(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct LinkAnimationHeader* animation, f32 playSpeed);
void LinkAnimation_PlayOnce(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct LinkAnimationHeader* animation);
void LinkAnimation_PlayOnceSetSpeed(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct LinkAnimationHeader* animation, f32 playSpeed);
void LinkAnimation_SetUpdateFunction(struct SkelAnime* skelAnime);
s32 LinkAnimation_Update(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime);
void SkelAnime_CopyFrameTable(struct SkelAnime* skelAnime, struct Vec3s* dst, struct Vec3s* src);
void SkelAnime_CopyFrameTableFalse(struct SkelAnime* skelAnime, struct Vec3s* dst, struct Vec3s* src, u8* copyFlag);
void SkelAnime_CopyFrameTableTrue(struct SkelAnime* skelAnime, struct Vec3s* dst, struct Vec3s* src, u8* copyFlag);
Gfx* SkelAnime_Draw(struct GlobalContext* globalCtx, void** skeleton, struct Vec3s* jointTable, OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* arg, Gfx* gfx);
Gfx* SkelAnime_DrawFlex(struct GlobalContext* globalCtx, void** skeleton, struct Vec3s* jointTable, s32 dListCount, OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* arg, Gfx* gfx);
void SkelAnime_DrawFlexLod(struct GlobalContext* globalCtx, void** skeleton, struct Vec3s* jointTable, s32 dListCount, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, s32 dListIndex);
void SkelAnime_DrawFlexOpa(struct GlobalContext* globalCtx, void** skeleton, struct Vec3s* jointTable, s32 dListCount, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg);
void SkelAnime_DrawLod(struct GlobalContext* globalCtx, void** skeleton, struct Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, s32 dListIndex);
void SkelAnime_DrawOpa(struct GlobalContext* globalCtx, void** skeleton, struct Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg);
void SkelAnime_Free(struct SkelAnime* skelAnime, struct GlobalContext* globalCtx);
s32 SkelAnime_GetFrameDataLegacy(struct LegacyAnimationHeader* animation, s32 frame, struct Vec3s* frameTable);
s32 SkelAnime_Init(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct SkeletonHeader* skeletonHeaderSeg, struct AnimationHeader* animation, struct Vec3s* jointTable, struct Vec3s* morphTable, s32 limbCount);
s32 SkelAnime_InitFlex(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct FlexSkeletonHeader* skeletonHeaderSeg, struct AnimationHeader* animation, struct Vec3s* jointTable, struct Vec3s* morphTable, s32 limbCount);
void SkelAnime_InitLink(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct FlexSkeletonHeader* skeletonHeaderSeg, struct LinkAnimationHeader* animation, s32 initFlags, struct Vec3s* jointTable, struct Vec3s* morphTable, s32 limbCount);
s32 SkelAnime_InitSkin(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct SkeletonHeader* skeletonHeaderSeg, struct AnimationHeader* animation);
void SkelAnime_InterpFrameTable(s32 limbCount, struct Vec3s* dst, struct Vec3s* start, struct Vec3s* target, f32 weight);
s32 SkelAnime_Update(struct SkelAnime* skelAnime);
void SkelAnime_UpdateTranslation(struct SkelAnime* skelAnime, struct Vec3f* pos, s16 angle);
#endif
