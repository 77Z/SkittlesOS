#include "../drivers/screen.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"
#include "../cpu/timer.h"
#include "../drivers/keyboard.h"
#include "kernel.h"

//Applications
#include "../programs/pi.h"
#include "../programs/uname.h"
#include "../programs/whoami.h"
#include "../programs/game.h"

void about() { kprint("\nSkittles OS Ver 0.1.0\nBadoom Cha\n"); }
void reset_view() { kprint("\n> "); }

void kernel_main() {
	// Initialization stuffs
	isr_install();
	irq_install();
	clear_screen();

	/* for (int i = 0; i < sizeof Applications / sizeof Applications[0]; i++) {
		kprint(Applications[i]);
		kprint("\n");
	} */

	about();
	kprint("Type something!\n");
	reset_view();
}


void user_input(char *input) {

	char *Applications[] = {
		"pi",
		"uname",
		"game",
		"whoami"
	};

	if (strcmp(input, "END") == 0) {
		clear_screen();
		kprint_at("Halting the CPU. Have a good day\n", 23, 11); // Centerish
		asm volatile("hlt");
	} else if (strcmp(input, "clear") == 0) {
		clear_screen();
		reset_view();
	} else if (strcmp(input, "about") == 0) {
		about();
		reset_view();
	} else {
		//Not a system command, check if it's an application command

		int MatchFound = 0;

		for (int i = 0; i < sizeof Applications / sizeof Applications[0]; i++) {
			
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

		/* kprint("You said: ");
		kprint(input);
		reset_view(); */
	}
}