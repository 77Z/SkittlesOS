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
void SKIT_clearTerminal();
void SKIT_printAt(char *input, int col, int row);

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

#endif /* _SKITTLES_H_ */