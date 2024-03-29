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
#include "../filesystem/fs.h"

//Applications
#include "../programs/pi.h"
#include "../programs/uname.h"
#include "../programs/whoami.h"
#include "../programs/game.h"

void about() {
	doubleprint("\nSkittles Version ");
	doubleprint(VERSION);
	doubleprint("-");
	doubleprint(LOCALVERSION);
	doubleprint(" Compiled on: ");
	doubleprint(BUILDDATE);
	doubleprint("\n");
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
	register int ecx asm("ecx"); // Grab register ECX which has the bootdrive in it
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
	// Different method of looping through strings
	// than seen in other places in code since
	// there's no good NULL to end at.
	/*char programName[128];
	char arguments[128];
	char isarg = 0;

	//TODO: Program names work right now but not arguments for some reason.
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == 32) { // This char is spacebar
			isarg = 1;
		}
		if (!isarg) {
			programName[i] = input[i];
		} else {
			arguments[i] = input[i];
		}
	}

	kprint(programName);
	kprint("\n");
	kprint(arguments);

	if (strcmp(programName, "serial") == 0) {
		kprint("Wrote to serial");
		printserial(arguments);
	} else if (strcmp(programName, "end") == 0) {
		clear_screen();
		kprint_at("Halting the CPU. Have a good day!", 24, 12);
		halt_cpu();
	} else if (strcmp(programName, "write") == 0) {
		write_file("", "");
	} else {
		kprint("Entered Command \"");
		kprint(programName);
		kprint("\" Was not recognized as a system command or application.");
	}

	isarg = 0;
	reset_view();*/

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
	} /*else if (strcmp(arr[0], "uname") == 0) {
	    	// For whatever reason this program stops the keyboard from working...
		if (strcmp(arr[1], "-r") == 0) {
			kprint(VERSION);
			kprint("-");
			kprint(LOCALVERSION);
		} else if (strcmp(arr[1], "-d") == 0) {
			kprint(BUILDDATE);
		} else if (strcmp(arr[1], "-n") == 0) {
			kprint("Skittles");
		} else if (strcmp(arr[1], "-a") == 0) {
			kprint("Skittles ");
			kprint(VERSION);
			kprint("-");
			kprint(LOCALVERSION);
			kprint(" ");
			kprint(BUILDDATE);
		} else {
			kprint("Skittles");
		}
	}*/ else {
		kprint("Entered Command \"");
		kprint(arr[0]);
		kprint("\" Was not recognized as a system command or application.");
	}

	reset_view();
}

/*void user_input(char *input) {

	char *Applications[] = {
		"pi",
		"uname",
		"game",
		"whoami"
	};

	if (strcmp(input, "END") == 0) {
		clear_screen();
		kprint_at("Halting the CPU. Have a good day!", 24, 12); // Centerish
		halt_cpu();
	} else if (strcmp(input, "clear") == 0) {
		clear_screen();
		reset_view();
	} else if (strcmp(input, "about") == 0) {
		about();
		reset_view();
	} else if (strcmp(input, "serialwrite") == 0) {
		// Nothing here yet as i need to parse arguments
	} else {
		//Not a system command, check if it's an application command

		int MatchFound = 0;

		for (unsigned int i = 0; i < sizeof Applications / sizeof Applications[0]; i++) {

			//This needs to be rewritten to handle things like arguments, if only strtok wasn't so hard to write :'(
			//A good replacement for this is javascripts split function, but this aint js chief
			if (strcmp(Applications[i], input) == 0) {
				// Match
				MatchFound = 1;
				//Match was found, execute the programs main function
				if (strcmp(Applications[i], "pi") == 0) {
					// Run the pi program
					PI_main();
				} else if (strcmp(Applications[i], "uname") == 0) {
					UNAME_main();
				} else if (strcmp(Applications[i], "whoami") == 0) {
					WHOAMI_main();
				} else if (strcmp(Applications[i], "game") == 0) {
					GAME_main();
				}
			}
		}

		if (!MatchFound) {
			kprint("Entered Command \"");
			kprint(input);
			kprint("\" Was not recognized as a system command or application.");
		}

		reset_view();

		//kprint("You said: ");
		//kprint(input);
		//reset_view();
	}
}*/
