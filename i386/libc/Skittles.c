/* USER ABSTRACTION LAYER */
// Makes it easier for programs to do command things
// like printing and modifying ram, sorta like Windows.h

#include "Skittles.h"

// Shell Management
void SKIT_print(char *input)                     { kprint(input);               }
void SKIT_printLn(char *input)                   { kprint(input); kprint("\n"); }
void SKIT_clearTerminal()                        { clear_screen();              }
void SKIT_printAt(char *input, int col, int row) { kprint_at(input, col, row);  }

// Memory Management
void SKIT_memory_copy(u8 *source, u8 *dest, int nbytes) { memory_copy(source, dest, nbytes);      }
void SKIT_memory_set(u8 *dest, u8 val, u32 len)         { memory_set(dest, val, len);             }
u32 SKIT_kmalloc(u32 size, int align, u32 *phys_addr)        { return kmalloc(size, align, phys_addr); }

// String Manipulation
void SKIT_int_to_ascii(int n, char str[]) { int_to_ascii(n, str);  }
void SKIT_reverse(char s[])               { reverse(s);            }
int  SKIT_strlen(char s[])                { return strlen(s);      }
void SKIT_backspace(char s[])             { backspace(s);          }
void SKIT_append(char s[], char n)        { append(s, n);          }
int  SKIT_strcmp(char s1[], char s2[])    { return strcmp(s1, s2); }

// Application Registration
