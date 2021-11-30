#include "keyboard.h"
#include <cpu/ports.h>
#include <cpu/isr.h>
#include "screen.h"
#include <libc/string.h>
#include <libc/function.h>
#include <kernel/kernel.h>

#define BACKSPACE 0x0E
#define CAPSLOCK 0x3A

#define CTRL	0x1D
#define LSHIFT	0x2A
#define RSHIFT	0x36
#define ALT	0x38

#define ENTER 0x1C

static char key_buffer[256];
static int CapsStatus = 0;
static int CtrlStatus = 0;
static int AltStatus  = 0;


#define SC_MAX 58
const char *sc_name[] = { "ERROR", "Esc", "1", "2", "3", "4", "5", "6",
	"7", "8", "9", "0", "-", "=", "Backspace", "Tab", "Q", "W", "E",
		"R", "T", "Y", "U", "I", "O", "P", "[", "]", "Enter", "Lctrl",
		"A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`",
		"LShift", "\\", "Z", "X", "C", "V", "B", "N", "M", ",", ".",
		"/", "RShift", "Keypad *", "LAlt", "Spacebar"};
const char sc_ascii[] = { '?', '?', '1', '2', '3', '4', '5', '6',
	'7', '8', '9', '0', '-', '=', '?', '?', 'Q', 'W', 'E', 'R', 'T', 'Y',
		'U', 'I', 'O', 'P', '[', ']', '?', '?', 'A', 'S', 'D', 'F', 'G',
		'H', 'J', 'K', 'L', ';', '\'', '`', '?', '\\', 'Z', 'X', 'C', 'V',
		'B', 'N', 'M', ',', '.', '/', '?', '?', '?', ' '};

/* LowerCase Chars */
const char *Lsc_name[] = { "ERROR", "Esc", "1", "2", "3", "4", "5", "6",
	"7", "8", "9", "0", "-", "=", "Backspace", "Tab", "q", "w", "e",
		"r", "t", "y", "u", "i", "o", "p", "[", "]", "Enter", "Lctrl",
		"a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'", "`",
		"LShift", "\\", "z", "x", "c", "v", "b", "n", "m", ",", ".",
		"/", "RShift", "Keypad *", "LAlt", "Spacebar", "CapsLock"};
const char Lsc_ascii[] = { '?', '?', '1', '2', '3', '4', '5', '6',
	'7', '8', '9', '0', '-', '=', '?', '?', 'q', 'w', 'e', 'r', 't', 'y',
		'u', 'i', 'o', 'p', '[', ']', '?', '?', 'a', 's', 'd', 'f', 'g',
		'h', 'j', 'k', 'l', ';', '\'', '`', '?', '\\', 'z', 'x', 'c', 'v',
		'b', 'n', 'm', ',', '.', '/', '?', '?', '?', ' ', '?'};

static void keyboard_callback(registers_t regs) {
	// The PIC leaves us the scancode in port 0x60
	u8 scancode = port_byte_in(0x60);
	// Thank you opuntiaOS for the incredible idea of detecting when the key is released.
	if (scancode & 0x80) {
		scancode -= 0x80;
		// Key up
		
		if (scancode == CTRL)
			CtrlStatus = 0;

		if (scancode == LSHIFT)
			CapsStatus = 0;

		if (scancode == ALT)
			AltStatus = 0;
	} else {

		// Key down

		if (scancode > SC_MAX) return;
		if (scancode == BACKSPACE) {
			kprint_backspace(key_buffer);
			backspace(key_buffer);
		} else if (scancode == ENTER) {
			kprint("\n");
			user_input(key_buffer); // kernel-controlled function
			key_buffer[0] = '\0';
		} else if (scancode == CAPSLOCK) {
			// Toggle caps lock
			if (CapsStatus)
				CapsStatus = 0;
			else
				CapsStatus = 1;
		} else if (scancode == LSHIFT) {
			CapsStatus = 1;
		} else if (scancode == CTRL) {
			CtrlStatus = 1;
		} else if (scancode == ALT) {
			AltStatus = 1;
		} else {
			char letter = sc_ascii[(int)scancode];
			if (CapsStatus == 0)
				letter = Lsc_ascii[(int)scancode];
			// Remember that kprint only accepts char[]
			char str[2] = {letter, '\0'};
			append(key_buffer, letter);
			kprint(str);
		}
	}
	UNUSED(regs);
}

void init_keyboard() {
   register_interrupt_handler(IRQ1, keyboard_callback); 
}
