#ifndef _SCREEN_H_
#define _SCREEN_H_

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

// COLORS
#define WHITE_ON_BLACK 0x0f
#define RED_ON_WHITE   0xf4

// Screen I/O Ports
#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

// Public Kernel API
void clear_screen();
void kprint_at(char *message, int col, int row);
void kprint(char *message);
void kprint_backspace();

#endif /* _SCREEN_H_ */