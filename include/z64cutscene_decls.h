#pragma once
struct GlobalContext;

void func_8006450C(struct GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_80064520(struct GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_80064534(struct GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_80064558(struct GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_800645A0(struct GlobalContext* globalCtx, CutsceneContext* csCtx);
void Cutscene_HandleEntranceTriggers(struct GlobalContext* globalCtx);
void Cutscene_HandleConditionalTriggers(struct GlobalContext* globalCtx);
void Cutscene_SetSegment(struct GlobalContext* globalCtx, void* segment);
