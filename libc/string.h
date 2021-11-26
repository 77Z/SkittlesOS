#ifndef _STRING_H_
#define _STRING_H_

void int_to_ascii(int n, char str[]);
void reverse(char s[]);
int strlen(char s[]);
void backspace(char s[]);
void append(char s[], char n);
int strcmp(char s1[], char s2[]);
int splitstring(char* base, char target[128][1024], char splitChar);

#endif /* _STRING_H_ */
