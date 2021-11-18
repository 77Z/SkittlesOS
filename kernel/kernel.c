#include "../cpu/isr.h"
#include "../cpu/idt.h"
#include "../cpu/timer.h"

#include "../drivers/screen.h"
#include "../drivers/keyboard.h"
#include "../drivers/serial.h"
#include "../drivers/acpi.h"

#include "kernel.h"

#include "../libc/stdlib.h"

//Filesystem
#include "../fs/fs.h"

void about() {
	doubleprint("\nSkittles ");
	doubleprint(VERSION);
}
void reset_view() { kprint("\n# "); }
void halt_cpu() { asm("hlt"); }

void bootsuccess(char* message) {
	kprint("[");
	kprint_color("***", GREEN_ON_BLACK);
	kprint("] ");
	kprint(message);
	kprint("\n");
}

void bootfailure(char* message) {
	kprint("[");
	kprint_color("***", RED_ON_BLACK);
	kprint("] ");
	kprint(message);
	kprint("\n");
}

// Returns number of items in array
// with a little bit of modification this function can be a fully featured split function
int splitBySpace(char* base, char target[10][20]) {
	int n = 0;
	int i;
	int j = 0;

	for (i = 0; TRUE; i++) {
		if (base[i] != ' ') {
			target[n][j++] = base[i];
		} else {
			target[n][j++] = '\0'; // Insert NULL
			n++;
			j = 0;
		}
		if (base[i] == '\0')
			break;
	}
	return n;
}

void kernel_main() {
	// Initialization stuffs
	isr_install();
	bootsuccess("Installed ISR");
	irq_install();
	bootsuccess("Installed IRQ");
	register int ecx asm("ebx"); // Grab register ECX which has the bootdrive in it
	//clear_screen();
	if (initFS(ecx) == 0) {      // Initialize the filesystem and handle failure
		kprint("FATAL: CAN'T INITIALIZE FILESYSTEM");
		halt_cpu();
	} else {
		bootsuccess("Initialized Filesystem");
	}

	if (init_serial() == 0) {    // Initialize serial and handle failure
		bootfailure("Failed to start serial communication");
	} else {
		bootsuccess("Initialized Serial communication");
		printserial("[\033[0;32m***\033[0m] Initialized serial communication\n");
	}

	char driveint[64];
	int_to_ascii(ecx, driveint);
	kprint(driveint);
	kprint("\n");

	about();
	reset_view();
}

void user_input(char *input) {
	char arr[10][20];

	int n = splitBySpace(input, arr);

	if (strcmp(arr[0], "serial") == 0) {
		printserial(arr[1]);
		printserial("\n");

		kprint("Wrote to serial: ");
		kprint(arr[1]);
	} else if (strcmp(arr[0], "end") == 0) {
		clear_screen();
		kprint_at("Halting the CPU. Have a good day!", 24, 12);
		halt_cpu();
	} else if (strcmp(arr[0], "shutdown") == 0) {
		clear_screen();
		shutdown();
	} else if (strcmp(arr[0], "clear") == 0) {
		clear_screen();
	} else {
		kprint("Entered Command \"");
		kprint(arr[0]);
		kprint("\" Was not recognized as a system command or application.");
	}

	reset_view();
}

