#pragma once
#ifdef INTERNAL_SRC_CODE_Z_VIMODE_C
void ViMode_Configure(ViMode* viMode, s32 mode, s32 type, s32 unk_70, s32 unk_74, s32 unk_78, s32 unk_7C, s32 width, s32 height, s32 unk_left, s32 unk_right, s32 unk_top, s32 unk_bottom);
void ViMode_ConfigureFeatures(ViMode* viMode, s32 viFeatures);
void ViMode_Destroy(ViMode* viMode);
void ViMode_Init(ViMode* viMode);
void ViMode_Load(ViMode* viMode);
void ViMode_LogPrint(OSViMode* viMode);
void ViMode_Save(ViMode* viMode);
#else
void ViMode_Configure(ViMode* viMode, s32 mode, s32 type, s32 unk_70, s32 unk_74, s32 unk_78, s32 unk_7C, s32 width, s32 height, s32 unk_left, s32 unk_right, s32 unk_top, s32 unk_bottom);
void ViMode_ConfigureFeatures(ViMode* viMode, s32 viFeatures);
void ViMode_Destroy(ViMode* viMode);
void ViMode_Init(ViMode* viMode);
void ViMode_Load(ViMode* viMode);
void ViMode_LogPrint(struct OSViMode* viMode);
void ViMode_Save(ViMode* viMode);
#endif
