#ifndef _SCREEN_H_
#define _SCREEN_H_

// COLORS
#define BLACK_ON_BLACK             0x00
#define BLUE_ON_BLACK              0x01
#define GREEN_ON_BLACK             0x02
#define TEAL_ON_BLACK              0x03
#define RED_ON_BLACK               0x04
#define MAGENTA_ON_BLACK           0x05
#define BROWN_ON_BLACK             0x06
#define LIGHTGRAY_ON_BLACK         0x07
#define GRAY_ON_BLACK              0x08
#define PURPLE_ON_BLACK            0x09
#define LIGHTGREEN_ON_BLACK        0x0a
#define AQUA_ON_BLACK              0x0b
#define MORERED_ON_BLACK           0x0c
#define MOREMAGENTA_ON_BLACK       0x0d
#define YELLOW_ON_BLACK            0x0e
#define WHITE_ON_BLACK             0x0f

#define BLACK_ON_BLUE              0x10
#define BLUE_ON_BLUE               0x11
#define GREEN_ON_BLUE              0x12
#define TEAL_ON_BLUE               0x13
#define RED_ON_BLUE                0x14
#define MAGENTA_ON_BLUE            0x15
#define BROWN_ON_BLUE              0x16
#define LIGHTGRAY_ON_BLUE          0x17
#define GRAY_ON_BLUE               0x18
#define PURPLE_ON_BLUE             0x19
#define LIGHTGREEN_ON_BLUE         0x1a
#define AQUA_ON_BLUE               0x1b
#define MORERED_ON_BLUE            0x1c
#define MOREMAGENTA_ON_BLUE        0x1d
#define YELLOW_ON_BLUE             0x1e
#define WHITE_ON_BLUE              0x1f

#define BLACK_ON_GREEN             0x20
#define BLUE_ON_GREEN              0x21
#define GREEN_ON_GREEN             0x22
#define TEAL_ON_GREEN              0x23
#define RED_ON_GREEN               0x24
#define MAGENTA_ON_GREEN           0x25
#define BROWN_ON_GREEN             0x26
#define LIGHTGRAY_ON_GREEN         0x27
#define GRAY_ON_GREEN              0x28
#define PURPLE_ON_GREEN            0x29
#define LIGHTGREEN_ON_GREEN        0x2a
#define AQUA_ON_GREEN              0x2b
#define MORERED_ON_GREEN           0x2c
#define MOREMAGENTA_ON_GREEN       0x2d
#define YELLOW_ON_GREEN            0x2e
#define WHITE_ON_GREEN             0x2f

#define BLACK_ON_TEAL              0x30
#define BLUE_ON_TEAL               0x31
#define GREEN_ON_TEAL              0x32
#define TEAL_ON_TEAL               0x33
#define RED_ON_TEAL                0x34
#define MAGENTA_ON_TEAL            0x35
#define BROWN_ON_TEAL              0x36
#define LIGHTGRAY_ON_TEAL          0x37
#define GRAY_ON_TEAL               0x38
#define PURPLE_ON_TEAL             0x39
#define LIGHTGREEN_ON_TEAL         0x3a
#define AQUA_ON_TEAL               0x3b
#define MORERED_ON_TEAL            0x3c
#define MOREMAGENTA_ON_TEAL        0x3d
#define YELLOW_ON_TEAL             0x3e
#define WHITE_ON_TEAL              0x3f

#define BLACK_ON_RED               0x40
#define BLUE_ON_RED                0x41
#define GREEN_ON_RED               0x42
#define TEAL_ON_RED                0x43
#define RED_ON_RED                 0x44
#define MAGENTA_ON_RED             0x45
#define BROWN_ON_RED               0x46
#define LIGHTGRAY_ON_RED           0x47
#define GRAY_ON_RED                0x48
#define PURPLE_ON_RED              0x49
#define LIGHTGREEN_ON_RED          0x4a
#define AQUA_ON_RED                0x4b
#define MORERED_ON_RED             0x4c
#define MOREMAGENTA_ON_RED         0x4d
#define YELLOW_ON_RED              0x4e
#define WHITE_ON_RED               0x4f

#define BLACK_ON_MAGENTA           0x50
#define BLUE_ON_MAGENTA            0x51
#define GREEN_ON_MAGENTA           0x52
#define TEAL_ON_MAGENTA            0x53
#define RED_ON_MAGENTA             0x54
#define MAGENTA_ON_MAGENTA         0x55
#define BROWN_ON_MAGENTA           0x56
#define LIGHTGRAY_ON_MAGENTA       0x57
#define GRAY_ON_MAGENTA            0x58
#define PURPLE_ON_MAGENTA          0x59
#define LIGHTGREEN_ON_MAGENTA      0x5a
#define AQUA_ON_MAGENTA            0x5b
#define MORERED_ON_MAGENTA         0x5c
#define MOREMAGENTA_ON_MAGENTA     0x5d
#define YELLOW_ON_MAGENTA          0x5e
#define WHITE_ON_MAGENTA           0x5f

#define BLACK_ON_BROWN             0x60
#define BLUE_ON_BROWN              0x61
#define GREEN_ON_BROWN             0x62
#define TEAL_ON_BROWN              0x63
#define RED_ON_BROWN               0x64
#define MAGENTA_ON_BROWN           0x65
#define BROWN_ON_BROWN             0x66
#define LIGHTGRAY_ON_BROWN         0x67
#define GRAY_ON_BROWN              0x68
#define PURPLE_ON_BROWN            0x69
#define LIGHTGREEN_ON_BROWN        0x6a
#define AQUA_ON_BROWN              0x6b
#define MORERED_ON_BROWN           0x6c
#define MOREMAGENTA_ON_BROWN       0x6d
#define YELLOW_ON_BROWN            0x6e
#define WHITE_ON_BROWN             0x6f

#define BLACK_ON_LIGHTGRAY         0x70
#define BLUE_ON_LIGHTGRAY          0x71
#define GREEN_ON_LIGHTGRAY         0x72
#define TEAL_ON_LIGHTGRAY          0x73
#define RED_ON_LIGHTGRAY           0x74
#define MAGENTA_ON_LIGHTGRAY       0x75
#define BROWN_ON_LIGHTGRAY         0x76
#define LIGHTGRAY_ON_LIGHTGRAY     0x77
#define GRAY_ON_LIGHTGRAY          0x78
#define PURPLE_ON_LIGHTGRAY        0x79
#define LIGHTGREEN_ON_LIGHTGRAY    0x7a
#define AQUA_ON_LIGHTGRAY          0x7b
#define MORERED_ON_LIGHTGRAY       0x7c
#define MOREMAGENTA_ON_LIGHTGRAY   0x7d
#define YELLOW_ON_LIGHTGRAY        0x7e
#define WHITE_ON_LIGHTGRAY         0x7f

#define BLACK_ON_GRAY              0x80
#define BLUE_ON_GRAY               0x81
#define GREEN_ON_GRAY              0x82
#define TEAL_ON_GRAY               0x83
#define RED_ON_GRAY                0x84
#define MAGENTA_ON_GRAY            0x85
#define BROWN_ON_GRAY              0x86
#define LIGHTGRAY_ON_GRAY          0x87
#define GRAY_ON_GRAY               0x88
#define PURPLE_ON_GRAY             0x89
#define LIGHTGREEN_ON_GRAY         0x8a
#define AQUA_ON_GRAY               0x8b
#define MORERED_ON_GRAY            0x8c
#define MOREMAGENTA_ON_GRAY        0x8d
#define YELLOW_ON_GRAY             0x8e
#define WHITE_ON_GRAY              0x8f

#define BLACK_ON_PURPLE            0x90
#define BLUE_ON_PURPLE             0x91
#define GREEN_ON_PURPLE            0x92
#define TEAL_ON_PURPLE             0x93
#define RED_ON_PURPLE              0x94
#define MAGENTA_ON_PURPLE          0x95
#define BROWN_ON_PURPLE            0x96
#define LIGHTGRAY_ON_PURPLE        0x97
#define GRAY_ON_PURPLE             0x98
#define PURPLE_ON_PURPLE           0x99
#define LIGHTGREEN_ON_PURPLE       0x9a
#define AQUA_ON_PURPLE             0x9b
#define MORERED_ON_PURPLE          0x9c
#define MOREMAGENTA_ON_PURPLE      0x9d
#define YELLOW_ON_PURPLE           0x9e
#define WHITE_ON_PURPLE            0x9f

#define BLACK_ON_LIGHTGREEN        0xa0
#define BLUE_ON_LIGHTGREEN         0xa1
#define GREEN_ON_LIGHTGREEN        0xa2
#define TEAL_ON_LIGHTGREEN         0xa3
#define RED_ON_LIGHTGREEN          0xa4
#define MAGENTA_ON_LIGHTGREEN      0xa5
#define BROWN_ON_LIGHTGREEN        0xa6
#define LIGHTGRAY_ON_LIGHTGREEN    0xa7
#define GRAY_ON_LIGHTGREEN         0xa8
#define PURPLE_ON_LIGHTGREEN       0xa9
#define LIGHTGREEN_ON_LIGHTGREEN   0xaa
#define AQUA_ON_LIGHTGREEN         0xab
#define MORERED_ON_LIGHTGREEN      0xac
#define MOREMAGENTA_ON_LIGHTGREEN  0xad
#define YELLOW_ON_LIGHTGREEN       0xae
#define WHITE_ON_LIGHTGREEN        0xaf

#define BLACK_ON_AQUA              0xb0
#define BLUE_ON_AQUA               0xb1
#define GREEN_ON_AQUA              0xb2
#define TEAL_ON_AQUA               0xb3
#define RED_ON_AQUA                0xb4
#define MAGENTA_ON_AQUA            0xb5
#define BROWN_ON_AQUA              0xb6
#define LIGHTGRAY_ON_AQUA          0xb7
#define GRAY_ON_AQUA               0xb8
#define PURPLE_ON_AQUA             0xb9
#define LIGHTGREEN_ON_AQUA         0xba
#define AQUA_ON_AQUA               0xbb
#define MORERED_ON_AQUA            0xbc
#define MOREMAGENTA_ON_AQUA        0xbd
#define YELLOW_ON_AQUA             0xbe
#define WHITE_ON_AQUA              0xbf

#define BLACK_ON_MORERED           0xc0
#define BLUE_ON_MORERED            0xc1
#define GREEN_ON_MORERED           0xc2
#define TEAL_ON_MORERED            0xc3
#define RED_ON_MORERED             0xc4
#define MAGENTA_ON_MORERED         0xc5
#define BROWN_ON_MORERED           0xc6
#define LIGHTGRAY_ON_MORERED       0xc7
#define GRAY_ON_MORERED            0xc8
#define PURPLE_ON_MORERED          0xc9
#define LIGHTGREEN_ON_MORERED      0xca
#define AQUA_ON_MORERED            0xcb
#define MORERED_ON_MORERED         0xcc
#define MOREMAGENTA_ON_MORERED     0xcd
#define YELLOW_ON_MORERED          0xce
#define WHITE_ON_MORERED           0xcf

#define BLACK_ON_MOREMAGENTA       0xd0
#define BLUE_ON_MOREMAGENTA        0xd1
#define GREEN_ON_MOREMAGENTA       0xd2
#define TEAL_ON_MOREMAGENTA        0xd3
#define RED_ON_MOREMAGENTA         0xd4
#define MAGENTA_ON_MOREMAGENTA     0xd5
#define BROWN_ON_MOREMAGENTA       0xd6
#define LIGHTGRAY_ON_MOREMAGENTA   0xd7
#define GRAY_ON_MOREMAGENTA        0xd8
#define PURPLE_ON_MOREMAGENTA      0xd9
#define LIGHTGREEN_ON_MOREMAGENTA  0xda
#define AQUA_ON_MOREMAGENTA        0xdb
#define MORERED_ON_MOREMAGENTA     0xdc
#define MOREMAGENTA_ON_MOREMAGENTA 0xdd
#define YELLOW_ON_MOREMAGENTA      0xde
#define WHITE_ON_MOREMAGENTA       0xdf

#define BLACK_ON_YELLOW            0xe0
#define BLUE_ON_YELLOW             0xe1
#define GREEN_ON_YELLOW            0xe2
#define TEAL_ON_YELLOW             0xe3
#define RED_ON_YELLOW              0xe4
#define MAGENTA_ON_YELLOW          0xe5
#define BROWN_ON_YELLOW            0xe6
#define LIGHTGRAY_ON_YELLOW        0xe7
#define GRAY_ON_YELLOW             0xe8
#define PURPLE_ON_YELLOW           0xe9
#define LIGHTGREEN_ON_YELLOW       0xea
#define AQUA_ON_YELLOW             0xeb
#define MORERED_ON_YELLOW          0xec
#define MOREMAGENTA_ON_YELLOW      0xed
#define YELLOW_ON_YELLOW           0xee
#define WHITE_ON_YELLOW            0xef

#define BLUE_ON_WHITE              0xf1
#define GREEN_ON_WHITE             0xf2
#define TEAL_ON_WHITE              0xf3
#define RED_ON_WHITE               0xf4
#define MAGENTA_ON_WHITE           0xf5
#define BROWN_ON_WHITE             0xf6
#define LIGHTGRAY_ON_WHITE         0xf7
#define GRAY_ON_WHITE              0xf8
#define PURPLE_ON_WHITE            0xf9
#define LIGHTGREEN_ON_WHITE        0xfa
#define AQUA_ON_WHITE              0xfb
#define MORERED_ON_WHITE           0xfc
#define MOREMAGENTA_ON_WHITE       0xfd
#define YELLOW_ON_WHITE            0xfe
#define WHITE_ON_WHITE             0xff

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

// Screen I/O Ports
#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

// Public Kernel API
void clear_screen();
void kprint_at(char *message, int col, int row);
void kprint(char *message);
void kprint_at_color(char *message, int col, int row, char attr);
void kprint_color(char *message, char attr);
void kprint_backspace();

#endif /* _SCREEN_H_ */