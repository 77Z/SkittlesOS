#include "screen.h"
#include <cpu/ports.h>
#include <libc/mem.h>

/* Declaration of private functions */
int get_cursor_offset();
void set_cursor_offset(int offset);
int print_char(char c, int col, int row, char attr);
int get_offset(int col, int row);
int get_offset_row(int offset);
int get_offset_col(int offset);

// PUBLIC KERNEL API FUNCTIONS

// Print a message on the specified location
// If col, row, are negative, we will use the current offset
void kprint_at_color(char *message, int col, int row, char attr) {
	// Set cursor if col/row are negative
	int offset;
	if (col >= 0 && row >= 0)
		offset = get_offset(col, row);
	else {
		offset = get_cursor_offset();
		row = get_offset_row(offset);
		col = get_offset_col(offset);
	}

	// Loop through message
	int i = 0;
	while (message[i] != 0) {
		offset = print_char(message[i++], col, row, attr);
		// Compute row/col for next iteration
		row = get_offset_row(offset);
		col = get_offset_col(offset);
	}
}
void kprint_at(char *message, int col, int row) {
	kprint_at_color(message, col, row, WHITE_ON_BLACK);
}

// Useful if you just need to print something without
// caring where on the screen it will go
void kprint(char *message) {
	kprint_at_color(message, -1, -1, WHITE_ON_BLACK);
}
void kprint_color(char *message, char attr) {
	kprint_at_color(message, -1, -1, attr);
}

void kprint_backspace(char key_buffer[256]) {
	if (strlen(key_buffer) > 0) {
		int offset = get_cursor_offset()-2;
		int row = get_offset_row(offset);
		int col = get_offset_col(offset);
		print_char(0x08, col, row, WHITE_ON_BLACK);
	}
}

/* void kprint_hex(int hexCode) {
		asm volatile(
			"print_hex:\n"
			"pusha\n"
			"mov %cx, 0\n"
			"hex_loop:\n"
			"cmp %cx, 4\n"
			"je end\n"
			//"mov %dx, %[hex]\n" : [hex] "=r" (hexCode)
			//"mov %ax, %dx\n"
			"mov %ax, $[hex]\n" : [hex] "=r" (hexCode) :
			"and %ax, 0x000f\n"
			"add %al, 0x30\n"
			"cmp %al, 0x39\n"
			"jle step2\n"
			"add %al, 7\n"
			"step2:\n"
			"mov %bx, HEX_OUT\n"
			"sub %bx, %cx\n"
			"mov [bx], %al\n"
			"ror %dx, 4\n"
			"add cx, 1\n"
			"jmp hex_loop\n"
			"end:\n"
			"mov %bx, HEX_OUT\n"
			"mov %eax, %bx\n"
			"push %eax\n"
			"call kprint\n"
			"pop %ebx\n"
			"HEX_OUT:\n"
			"db '0x0000', 0\n"
		);
	//END
	//kprint();
} */

// PRIVATE KERNEL FUNCTIONS


// Innermost print function reserved for the kernel only
// If 'col' and 'row' are negative, we will print at current cursor location
// If 'attr' is zero it will use 'white on black' as default
// Returns the offset of the next character
// Sets the video cursor to the returned offset
int print_char(char c, int col, int row, char attr) {
	u8 *vidmem = (u8*) VIDEO_ADDRESS;
	if (!attr) attr = WHITE_ON_BLACK;

	/* Error control: print a red 'E' if the coords aren't right */
	if (col >= MAX_COLS || row >= MAX_ROWS) {
		vidmem[2*(MAX_COLS)*(MAX_ROWS)-2] = 'E';
		vidmem[2*(MAX_COLS)*(MAX_ROWS)-1] = RED_ON_WHITE;
		return get_offset(col, row);
	}

	int offset;
	if (col >= 0 && row >= 0) offset = get_offset(col, row);
	else offset = get_cursor_offset();

	if (c == '\n') {
		row = get_offset_row(offset);
		offset = get_offset(0, row+1);
	} else if (c == 0x08) { /* Backspace */
		vidmem[offset] = ' ';
		vidmem[offset+1] = attr;
	} else {
		vidmem[offset] = c;
		vidmem[offset+1] = attr;
		offset += 2;
	}

	/* Check if the offset is over screen size and scroll */
	if (offset >= MAX_ROWS * MAX_COLS * 2) {
		int i;
		for (i = 1; i < MAX_ROWS; i++) 
			memory_copy((u8*)(get_offset(0, i) + VIDEO_ADDRESS),
						(u8*)(get_offset(0, i-1) + VIDEO_ADDRESS),
						MAX_COLS * 2);

		/* Blank last line */
		char *last_line = (char*) (get_offset(0, MAX_ROWS-1) + (u8*) VIDEO_ADDRESS);
		for (i = 0; i < MAX_COLS * 2; i++) last_line[i] = 0;

		offset -= 2 * MAX_COLS;
	}

	set_cursor_offset(offset);
	return offset;
}

int get_cursor_offset() {
	// Use the VGA ports to get the current cursor position
	// 1. Ask for high byte of the cursor offset (data 14)
	// 2. Ask for low byte (data 15)
	port_byte_out(REG_SCREEN_CTRL, 14);
	int offset = port_byte_in(REG_SCREEN_DATA) << 8; // High byte: << 8
	port_byte_out(REG_SCREEN_CTRL, 15);
	offset += port_byte_in(REG_SCREEN_DATA);
	return offset * 2; // Position * size of character cell
}

void set_cursor_offset(int offset) {
	// Similar to get_cursor_offset, but instead of reading we write data
	offset /= 2;
	port_byte_out(REG_SCREEN_CTRL, 14);
	port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset >> 8));
	port_byte_out(REG_SCREEN_CTRL, 15);
	port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset & 0xff));
}

void clear_screen() {
	int screen_size = MAX_COLS * MAX_ROWS;
	int i;
	char *screen = VIDEO_ADDRESS;

	for (i = 0; i < screen_size; i++) {
		screen[i*2] = ' ';
		screen[i*2+1] = WHITE_ON_BLACK;
	}
	set_cursor_offset(get_offset(0, 0));
}


int get_offset(int col, int row) { return 2 * (row * MAX_COLS + col); }
int get_offset_row(int offset) { return offset / (2 * MAX_COLS); }
int get_offset_col(int offset) { return (offset - (get_offset_row(offset)*2*MAX_COLS))/2; }
