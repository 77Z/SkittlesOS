// Code from DiyOS
// https://github.com/leonardoms/DiyOS/blob/2019/drivers/mouse.c

#include "mouse.h"
#include <cpu/types.h>
#include <cpu/ports.h>

queue_t mouse_queue, mouse_wait;

void mouse_write(u8 write) {
    port_byte_out(0x64, 0xD4);
    port_byte_out(0x60, write);
}

u8 mouse_read() {
    return port_byte_in(0x60);
}

struct mouse_packet* packet;

u8 mouse_listen(task_t* t, void* data) {
    if (t->listen && MOUSE)
}