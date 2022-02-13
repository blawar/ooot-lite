/* SPDX-FileCopyrightText: 2022 Hayden Kowalchuk 819028+mrneo240@users.noreply.github.com */
/* SPDX-License-Identifier: BSD-3-Clause */
/* Note: The above applies to parts of this file modified by Hayden Kowalchuk only and not existing code */

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_EG_Z_EN_EG_C
#include "actor_common.h"
/*
 * File: z_en_eg.c
 * Overlay: ovl_En_Eg
 * Description: Triggers a void out (used in the tower collapse sequence?)
 */

#include "z_en_eg.h"
#include "vt.h"
#include "def/code_800F9280.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_play.h"

#define FLAGS ACTOR_FLAG_4

void EnEg_Init(Actor* thisx, GlobalContext* globalCtx);
void EnEg_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnEg_Update(Actor* thisx, GlobalContext* globalCtx);
void EnEg_Draw(Actor* thisx, GlobalContext* globalCtx);
void EnEg_OnLoad(Actor* thisx, GlobalContext* globalCtx);

void func_809FFDC8(EnEg* this, GlobalContext* globalCtx);

static s32 voided = false;

static EnEgActionFunc sActionFuncs[] = {
    func_809FFDC8,
};

const ActorInit En_Eg_InitVars = {
    ACTOR_EN_EG,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_ZL2,
    sizeof(EnEg),
    (ActorFunc)EnEg_Init,
    (ActorFunc)EnEg_Destroy,
    (ActorFunc)EnEg_Update,
    (ActorFunc)EnEg_Draw,
    (ActorFunc)EnEg_OnLoad,
};

void EnEg_PlayVoidOutSFX() {
    func_800788CC(NA_SE_OC_ABYSS);
}

void EnEg_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnEg_OnLoad(Actor* thisx, GlobalContext* globalCtx) {
    voided = false;
}

void EnEg_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnEg* this = (EnEg*)thisx;

    this->action = 0;
}

void func_809FFDC8(EnEg* this, GlobalContext* globalCtx) {
    if (!voided && (gSaveContext.timer2Value < 1) && Flags_GetSwitch(globalCtx, 0x36) && (kREG(0) == 0)) {
        // Void the player out
        Gameplay_TriggerRespawn(globalCtx);
        gSaveContext.respawnFlag = -2;
        Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_STOP);
        globalCtx->fadeTransition = 2;
        EnEg_PlayVoidOutSFX();
        voided = true;
    }
}

void EnEg_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnEg* this = (EnEg*)thisx;
    s32 action = this->action;

    if (((action < 0) || (0 < action)) || (sActionFuncs[action] == NULL)) {
        // "Main Mode is wrong!!!!!!!!!!!!!!!!!!!!!!!!!"
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
    } else {
        sActionFuncs[action](this, globalCtx);
    }
}

void EnEg_Draw(Actor* thisx, GlobalContext* globalCtx) {
}
