#pragma once

#ifndef Z64_DMA_H
#define Z64_DMA_H

#include "ultra64.h"

typedef struct {
    /* 0x00 */ void*      vromAddr; // VROM address (source)
    /* 0x04 */ void*    dramAddr; // DRAM address (destination)
    /* 0x08 */ uintptr_t      size;     // File Transfer size
    /* 0x0C */ const char* filename; // Filename for debugging
    /* 0x10 */ s32      line;     // Line for debugging
    /* 0x14 */ s32      unk_14;
    /* 0x18 */ OSMesgQueue* notifyQueue; // Message queue for the notification message
    /* 0x1C */ OSMesg   notifyMsg;       // Completion notification message
} DmaRequest; // size = 0x20

#endif
