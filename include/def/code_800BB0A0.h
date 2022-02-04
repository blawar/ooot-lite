#pragma once
#ifdef INTERNAL_SRC_CODE_CODE_800BB0A0_C
void func_800BB0A0(f32 u, Vec3f* pos, f32* roll, f32* viewAngle, f32* point0, f32* point1, f32* point2, f32* point3);
s32 func_800BB2B4(Vec3f* pos, f32* roll, f32* fov, CutsceneCameraPoint* point, s16* keyframe, f32* curFrame);
#else
void func_800BB0A0(f32 u, struct Vec3f* pos, f32* roll, f32* viewAngle, f32* point0, f32* point1, f32* point2, f32* point3);
s32 func_800BB2B4(struct Vec3f* pos, f32* roll, f32* fov, struct CutsceneCameraPoint* point, s16* keyframe, f32* curFrame);
#endif
