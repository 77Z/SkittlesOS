#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <cpu/types.h>
// #include <kernel.h>
// #include <ctypes.h>
// #include <queue.h>

#define MOUSE_LEFT    1
#define MOUSE_RIGHT   2
#define MOUSE_MIDLE   4

struct mouse_packet {
    u8 flags;
    s32 dx;
    s32 dy;
} __attribute__ ((packed));

void
mouse(void);

#endif