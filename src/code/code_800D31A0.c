#define INTERNAL_SRC_CODE_CODE_800D31A0_C
#include "global.h"
#include "vt.h"
#include "padmgr.h"
#include "def/code_800D31A0.h"
#include "def/sleep.h"

u32 gIsCtrlr2Valid = false;

void func_800D31A0(void) {
    osSyncPrintf(VT_FGCOL(RED) "\n**** Freeze!! ****\n" VT_RST);
    while (true) {
        Sleep_Msec(1000);
    }
}

void func_800D31F0(void) {
    gIsCtrlr2Valid = (gPadMgr.validCtrlrsMask & 2) != 0;
}

void func_800D3210(void) {
    gIsCtrlr2Valid = false;
}
