#include "../drivers/screen.h"
#include "util.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"
#include "../cpu/timer.h"

void about() { kprint("\nCrystl OS Ver 0.1.0\nBadoom Cha\n"); }

void main() {
	isr_install();

	asm volatile("sti");
	init_timer(50);


	/* clear_screen();
	about(); */
	/* __asm__ __volatile__("int $2");
	__asm__ __volatile__("int $3"); */
}
