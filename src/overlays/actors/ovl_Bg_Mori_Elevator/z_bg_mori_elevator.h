/* SPDX-FileCopyrightText: 2022 Hayden Kowalchuk 819028+mrneo240@users.noreply.github.com */
/* SPDX-License-Identifier: BSD-3-Clause */
/* Note: The above applies to parts of this file modified by Hayden Kowalchuk only and not existing code */

#ifndef Z_BG_MORI_ELEVATOR_H
#define Z_BG_MORI_ELEVATOR_H

#include "ultra64.h"
#include "global.h"

struct BgMoriElevator;

typedef void (*BgMoriElevatorActionFunc)(struct BgMoriElevator*, GlobalContext*);

typedef struct BgMoriElevator {
    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgMoriElevatorActionFunc actionFunc;
    /* 0x0168 */ f32 targetY;
    /* 0x016C */ s32 unk_16C;
    /* 0x0170 */ u8 unk_170;
    /* 0x0171 */ s32 moriTexObjIndex;
    /* 0x0175 */ bool unk_172;
} BgMoriElevator; // size = 0x0174

#endif
