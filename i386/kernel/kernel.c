#include "../drivers/screen.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"
#include "../cpu/timer.h"
#include "../drivers/keyboard.h"
#include "kernel.h"

void about() { kprint("\nSkittles OS Ver 0.1.0\nBadoom Cha\n"); }
void reset_view() { kprint("\n> "); }

void kernel_main() {
	// Initialization stuffs
	isr_install();
	irq_install();
	//clear_screen();

	about();
	kprint("Type something!\n");
	reset_view();
}


void user_input(char *input) {
	if (strcmp(input, "END") == 0) {
		kprint("Halting the CPU. Have a good day\n");
		asm volatile("hlt");
	} else if (strcmp(input, "PING") == 0) {
		kprint("PONG!");
		reset_view();
	} else if (strcmp(input, "CLEAR") == 0) {
		clear_screen();
		reset_view();
	} else if (strcmp(input, "ABOUT") == 0) {
		about();
		reset_view();
	} else {
		kprint("You said: ");
		kprint(input);
		reset_view();
	}
}