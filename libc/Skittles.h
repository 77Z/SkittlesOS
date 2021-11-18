/* USER ABSTRACTION LAYER */
// Makes it easier for programs to do command things
// like printing and modifying ram, sorta like Windows.h

#ifndef _SKITTLES_H_
#define _SKITTLES_H_

#include "../cpu/types.h"
#include "mem.h"
#include "string.h"
#include "../drivers/screen.h"

// Shell Management
void SKIT_print(char *input);
void SKIT_printLn(char *input);
void SKIT_printColor(char *input, char color);
void SKIT_printLnColor(char *input, char color);
void SKIT_clearTerminal();
void SKIT_printAt(char *input, int col, int row);
void SKIT_printAtColor(char *input, int col, int row, char color);

// Memory Management
void SKIT_memory_copy(u8 *source, u8 *dest, int nbytes);
void SKIT_memory_set(u8 *dest, u8 val, u32 len);
u32 SKIT_kmalloc(u32 size, int align, u32 *phys_addr);

// String Manipulation
void SKIT_int_to_ascii(int n, char str[]);
void SKIT_reverse(char s[]);
int  SKIT_strlen(char s[]);
void SKIT_backspace(char s[]);
void SKIT_append(char s[], char n);
int  SKIT_strcmp(char s1[], char s2[]);

#ifndef SKITTLES_LEAN_AND_MEAN // Don't include uncommon libs
#endif /* SKITTLES_LEAN_AND_MEAN */

// Screen Properties
#define SKIT_MAX_ROWS 25
#define SKIT_MAX_COLS 80

// COLORS
#define SKIT_BLACK_ON_BLACK             0x00
#define SKIT_BLUE_ON_BLACK              0x01
#define SKIT_GREEN_ON_BLACK             0x02
#define SKIT_TEAL_ON_BLACK              0x03
#define SKIT_RED_ON_BLACK               0x04
#define SKIT_MAGENTA_ON_BLACK           0x05
#define SKIT_BROWN_ON_BLACK             0x06
#define SKIT_LIGHTGRAY_ON_BLACK         0x07
#define SKIT_GRAY_ON_BLACK              0x08
#define SKIT_PURPLE_ON_BLACK            0x09
#define SKIT_LIGHTGREEN_ON_BLACK        0x0a
#define SKIT_AQUA_ON_BLACK              0x0b
#define SKIT_MORERED_ON_BLACK           0x0c
#define SKIT_MOREMAGENTA_ON_BLACK       0x0d
#define SKIT_YELLOW_ON_BLACK            0x0e
#define SKIT_WHITE_ON_BLACK             0x0f

#define SKIT_BLACK_ON_BLUE              0x10
#define SKIT_BLUE_ON_BLUE               0x11
#define SKIT_GREEN_ON_BLUE              0x12
#define SKIT_TEAL_ON_BLUE               0x13
#define SKIT_RED_ON_BLUE                0x14
#define SKIT_MAGENTA_ON_BLUE            0x15
#define SKIT_BROWN_ON_BLUE              0x16
#define SKIT_LIGHTGRAY_ON_BLUE          0x17
#define SKIT_GRAY_ON_BLUE               0x18
#define SKIT_PURPLE_ON_BLUE             0x19
#define SKIT_LIGHTGREEN_ON_BLUE         0x1a
#define SKIT_AQUA_ON_BLUE               0x1b
#define SKIT_MORERED_ON_BLUE            0x1c
#define SKIT_MOREMAGENTA_ON_BLUE        0x1d
#define SKIT_YELLOW_ON_BLUE             0x1e
#define SKIT_WHITE_ON_BLUE              0x1f

#define SKIT_BLACK_ON_GREEN             0x20
#define SKIT_BLUE_ON_GREEN              0x21
#define SKIT_GREEN_ON_GREEN             0x22
#define SKIT_TEAL_ON_GREEN              0x23
#define SKIT_RED_ON_GREEN               0x24
#define SKIT_MAGENTA_ON_GREEN           0x25
#define SKIT_BROWN_ON_GREEN             0x26
#define SKIT_LIGHTGRAY_ON_GREEN         0x27
#define SKIT_GRAY_ON_GREEN              0x28
#define SKIT_PURPLE_ON_GREEN            0x29
#define SKIT_LIGHTGREEN_ON_GREEN        0x2a
#define SKIT_AQUA_ON_GREEN              0x2b
#define SKIT_MORERED_ON_GREEN           0x2c
#define SKIT_MOREMAGENTA_ON_GREEN       0x2d
#define SKIT_YELLOW_ON_GREEN            0x2e
#define SKIT_WHITE_ON_GREEN             0x2f

#define SKIT_BLACK_ON_TEAL              0x30
#define SKIT_BLUE_ON_TEAL               0x31
#define SKIT_GREEN_ON_TEAL              0x32
#define SKIT_TEAL_ON_TEAL               0x33
#define SKIT_RED_ON_TEAL                0x34
#define SKIT_MAGENTA_ON_TEAL            0x35
#define SKIT_BROWN_ON_TEAL              0x36
#define SKIT_LIGHTGRAY_ON_TEAL          0x37
#define SKIT_GRAY_ON_TEAL               0x38
#define SKIT_PURPLE_ON_TEAL             0x39
#define SKIT_LIGHTGREEN_ON_TEAL         0x3a
#define SKIT_AQUA_ON_TEAL               0x3b
#define SKIT_MORERED_ON_TEAL            0x3c
#define SKIT_MOREMAGENTA_ON_TEAL        0x3d
#define SKIT_YELLOW_ON_TEAL             0x3e
#define SKIT_WHITE_ON_TEAL              0x3f

#define SKIT_BLACK_ON_RED               0x40
#define SKIT_BLUE_ON_RED                0x41
#define SKIT_GREEN_ON_RED               0x42
#define SKIT_TEAL_ON_RED                0x43
#define SKIT_RED_ON_RED                 0x44
#define SKIT_MAGENTA_ON_RED             0x45
#define SKIT_BROWN_ON_RED               0x46
#define SKIT_LIGHTGRAY_ON_RED           0x47
#define SKIT_GRAY_ON_RED                0x48
#define SKIT_PURPLE_ON_RED              0x49
#define SKIT_LIGHTGREEN_ON_RED          0x4a
#define SKIT_AQUA_ON_RED                0x4b
#define SKIT_MORERED_ON_RED             0x4c
#define SKIT_MOREMAGENTA_ON_RED         0x4d
#define SKIT_YELLOW_ON_RED              0x4e
#define SKIT_WHITE_ON_RED               0x4f

#define SKIT_BLACK_ON_MAGENTA           0x50
#define SKIT_BLUE_ON_MAGENTA            0x51
#define SKIT_GREEN_ON_MAGENTA           0x52
#define SKIT_TEAL_ON_MAGENTA            0x53
#define SKIT_RED_ON_MAGENTA             0x54
#define SKIT_MAGENTA_ON_MAGENTA         0x55
#define SKIT_BROWN_ON_MAGENTA           0x56
#define SKIT_LIGHTGRAY_ON_MAGENTA       0x57
#define SKIT_GRAY_ON_MAGENTA            0x58
#define SKIT_PURPLE_ON_MAGENTA          0x59
#define SKIT_LIGHTGREEN_ON_MAGENTA      0x5a
#define SKIT_AQUA_ON_MAGENTA            0x5b
#define SKIT_MORERED_ON_MAGENTA         0x5c
#define SKIT_MOREMAGENTA_ON_MAGENTA     0x5d
#define SKIT_YELLOW_ON_MAGENTA          0x5e
#define SKIT_WHITE_ON_MAGENTA           0x5f

#define SKIT_BLACK_ON_BROWN             0x60
#define SKIT_BLUE_ON_BROWN              0x61
#define SKIT_GREEN_ON_BROWN             0x62
#define SKIT_TEAL_ON_BROWN              0x63
#define SKIT_RED_ON_BROWN               0x64
#define SKIT_MAGENTA_ON_BROWN           0x65
#define SKIT_BROWN_ON_BROWN             0x66
#define SKIT_LIGHTGRAY_ON_BROWN         0x67
#define SKIT_GRAY_ON_BROWN              0x68
#define SKIT_PURPLE_ON_BROWN            0x69
#define SKIT_LIGHTGREEN_ON_BROWN        0x6a
#define SKIT_AQUA_ON_BROWN              0x6b
#define SKIT_MORERED_ON_BROWN           0x6c
#define SKIT_MOREMAGENTA_ON_BROWN       0x6d
#define SKIT_YELLOW_ON_BROWN            0x6e
#define SKIT_WHITE_ON_BROWN             0x6f

#define SKIT_BLACK_ON_LIGHTGRAY         0x70
#define SKIT_BLUE_ON_LIGHTGRAY          0x71
#define SKIT_GREEN_ON_LIGHTGRAY         0x72
#define SKIT_TEAL_ON_LIGHTGRAY          0x73
#define SKIT_RED_ON_LIGHTGRAY           0x74
#define SKIT_MAGENTA_ON_LIGHTGRAY       0x75
#define SKIT_BROWN_ON_LIGHTGRAY         0x76
#define SKIT_LIGHTGRAY_ON_LIGHTGRAY     0x77
#define SKIT_GRAY_ON_LIGHTGRAY          0x78
#define SKIT_PURPLE_ON_LIGHTGRAY        0x79
#define SKIT_LIGHTGREEN_ON_LIGHTGRAY    0x7a
#define SKIT_AQUA_ON_LIGHTGRAY          0x7b
#define SKIT_MORERED_ON_LIGHTGRAY       0x7c
#define SKIT_MOREMAGENTA_ON_LIGHTGRAY   0x7d
#define SKIT_YELLOW_ON_LIGHTGRAY        0x7e
#define SKIT_WHITE_ON_LIGHTGRAY         0x7f

#define SKIT_BLACK_ON_GRAY              0x80
#define SKIT_BLUE_ON_GRAY               0x81
#define SKIT_GREEN_ON_GRAY              0x82
#define SKIT_TEAL_ON_GRAY               0x83
#define SKIT_RED_ON_GRAY                0x84
#define SKIT_MAGENTA_ON_GRAY            0x85
#define SKIT_BROWN_ON_GRAY              0x86
#define SKIT_LIGHTGRAY_ON_GRAY          0x87
#define SKIT_GRAY_ON_GRAY               0x88
#define SKIT_PURPLE_ON_GRAY             0x89
#define SKIT_LIGHTGREEN_ON_GRAY         0x8a
#define SKIT_AQUA_ON_GRAY               0x8b
#define SKIT_MORERED_ON_GRAY            0x8c
#define SKIT_MOREMAGENTA_ON_GRAY        0x8d
#define SKIT_YELLOW_ON_GRAY             0x8e
#define SKIT_WHITE_ON_GRAY              0x8f

#define SKIT_BLACK_ON_PURPLE            0x90
#define SKIT_BLUE_ON_PURPLE             0x91
#define SKIT_GREEN_ON_PURPLE            0x92
#define SKIT_TEAL_ON_PURPLE             0x93
#define SKIT_RED_ON_PURPLE              0x94
#define SKIT_MAGENTA_ON_PURPLE          0x95
#define SKIT_BROWN_ON_PURPLE            0x96
#define SKIT_LIGHTGRAY_ON_PURPLE        0x97
#define SKIT_GRAY_ON_PURPLE             0x98
#define SKIT_PURPLE_ON_PURPLE           0x99
#define SKIT_LIGHTGREEN_ON_PURPLE       0x9a
#define SKIT_AQUA_ON_PURPLE             0x9b
#define SKIT_MORERED_ON_PURPLE          0x9c
#define SKIT_MOREMAGENTA_ON_PURPLE      0x9d
#define SKIT_YELLOW_ON_PURPLE           0x9e
#define SKIT_WHITE_ON_PURPLE            0x9f

#define SKIT_BLACK_ON_LIGHTGREEN        0xa0
#define SKIT_BLUE_ON_LIGHTGREEN         0xa1
#define SKIT_GREEN_ON_LIGHTGREEN        0xa2
#define SKIT_TEAL_ON_LIGHTGREEN         0xa3
#define SKIT_RED_ON_LIGHTGREEN          0xa4
#define SKIT_MAGENTA_ON_LIGHTGREEN      0xa5
#define SKIT_BROWN_ON_LIGHTGREEN        0xa6
#define SKIT_LIGHTGRAY_ON_LIGHTGREEN    0xa7
#define SKIT_GRAY_ON_LIGHTGREEN         0xa8
#define SKIT_PURPLE_ON_LIGHTGREEN       0xa9
#define SKIT_LIGHTGREEN_ON_LIGHTGREEN   0xaa
#define SKIT_AQUA_ON_LIGHTGREEN         0xab
#define SKIT_MORERED_ON_LIGHTGREEN      0xac
#define SKIT_MOREMAGENTA_ON_LIGHTGREEN  0xad
#define SKIT_YELLOW_ON_LIGHTGREEN       0xae
#define SKIT_WHITE_ON_LIGHTGREEN        0xaf

#define SKIT_BLACK_ON_AQUA              0xb0
#define SKIT_BLUE_ON_AQUA               0xb1
#define SKIT_GREEN_ON_AQUA              0xb2
#define SKIT_TEAL_ON_AQUA               0xb3
#define SKIT_RED_ON_AQUA                0xb4
#define SKIT_MAGENTA_ON_AQUA            0xb5
#define SKIT_BROWN_ON_AQUA              0xb6
#define SKIT_LIGHTGRAY_ON_AQUA          0xb7
#define SKIT_GRAY_ON_AQUA               0xb8
#define SKIT_PURPLE_ON_AQUA             0xb9
#define SKIT_LIGHTGREEN_ON_AQUA         0xba
#define SKIT_AQUA_ON_AQUA               0xbb
#define SKIT_MORERED_ON_AQUA            0xbc
#define SKIT_MOREMAGENTA_ON_AQUA        0xbd
#define SKIT_YELLOW_ON_AQUA             0xbe
#define SKIT_WHITE_ON_AQUA              0xbf

#define SKIT_BLACK_ON_MORERED           0xc0
#define SKIT_BLUE_ON_MORERED            0xc1
#define SKIT_GREEN_ON_MORERED           0xc2
#define SKIT_TEAL_ON_MORERED            0xc3
#define SKIT_RED_ON_MORERED             0xc4
#define SKIT_MAGENTA_ON_MORERED         0xc5
#define SKIT_BROWN_ON_MORERED           0xc6
#define SKIT_LIGHTGRAY_ON_MORERED       0xc7
#define SKIT_GRAY_ON_MORERED            0xc8
#define SKIT_PURPLE_ON_MORERED          0xc9
#define SKIT_LIGHTGREEN_ON_MORERED      0xca
#define SKIT_AQUA_ON_MORERED            0xcb
#define SKIT_MORERED_ON_MORERED         0xcc
#define SKIT_MOREMAGENTA_ON_MORERED     0xcd
#define SKIT_YELLOW_ON_MORERED          0xce
#define SKIT_WHITE_ON_MORERED           0xcf

#define SKIT_BLACK_ON_MOREMAGENTA       0xd0
#define SKIT_BLUE_ON_MOREMAGENTA        0xd1
#define SKIT_GREEN_ON_MOREMAGENTA       0xd2
#define SKIT_TEAL_ON_MOREMAGENTA        0xd3
#define SKIT_RED_ON_MOREMAGENTA         0xd4
#define SKIT_MAGENTA_ON_MOREMAGENTA     0xd5
#define SKIT_BROWN_ON_MOREMAGENTA       0xd6
#define SKIT_LIGHTGRAY_ON_MOREMAGENTA   0xd7
#define SKIT_GRAY_ON_MOREMAGENTA        0xd8
#define SKIT_PURPLE_ON_MOREMAGENTA      0xd9
#define SKIT_LIGHTGREEN_ON_MOREMAGENTA  0xda
#define SKIT_AQUA_ON_MOREMAGENTA        0xdb
#define SKIT_MORERED_ON_MOREMAGENTA     0xdc
#define SKIT_MOREMAGENTA_ON_MOREMAGENTA 0xdd
#define SKIT_YELLOW_ON_MOREMAGENTA      0xde
#define SKIT_WHITE_ON_MOREMAGENTA       0xdf

#define SKIT_BLACK_ON_YELLOW            0xe0
#define SKIT_BLUE_ON_YELLOW             0xe1
#define SKIT_GREEN_ON_YELLOW            0xe2
#define SKIT_TEAL_ON_YELLOW             0xe3
#define SKIT_RED_ON_YELLOW              0xe4
#define SKIT_MAGENTA_ON_YELLOW          0xe5
#define SKIT_BROWN_ON_YELLOW            0xe6
#define SKIT_LIGHTGRAY_ON_YELLOW        0xe7
#define SKIT_GRAY_ON_YELLOW             0xe8
#define SKIT_PURPLE_ON_YELLOW           0xe9
#define SKIT_LIGHTGREEN_ON_YELLOW       0xea
#define SKIT_AQUA_ON_YELLOW             0xeb
#define SKIT_MORERED_ON_YELLOW          0xec
#define SKIT_MOREMAGENTA_ON_YELLOW      0xed
#define SKIT_YELLOW_ON_YELLOW           0xee
#define SKIT_WHITE_ON_YELLOW            0xef

#define SKIT_BLUE_ON_WHITE              0xf1
#define SKIT_GREEN_ON_WHITE             0xf2
#define SKIT_TEAL_ON_WHITE              0xf3
#define SKIT_RED_ON_WHITE               0xf4
#define SKIT_MAGENTA_ON_WHITE           0xf5
#define SKIT_BROWN_ON_WHITE             0xf6
#define SKIT_LIGHTGRAY_ON_WHITE         0xf7
#define SKIT_GRAY_ON_WHITE              0xf8
#define SKIT_PURPLE_ON_WHITE            0xf9
#define SKIT_LIGHTGREEN_ON_WHITE        0xfa
#define SKIT_AQUA_ON_WHITE              0xfb
#define SKIT_MORERED_ON_WHITE           0xfc
#define SKIT_MOREMAGENTA_ON_WHITE       0xfd
#define SKIT_YELLOW_ON_WHITE            0xfe
#define SKIT_WHITE_ON_WHITE             0xff

#endif /* _SKITTLES_H_ */