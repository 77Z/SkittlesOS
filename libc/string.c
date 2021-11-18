#include "string.h"

void int_to_ascii(int n, char str[]) {
	int i, sign;
	if ((sign = n) < 0) n = -n;
	i = 0;
	do {
		str[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0) str[i++] = '-';
	str[i] = '\0';

	/* TODO: implement "reverse" */
}

void reverse(char s[]) {
	int c, i, j;
	// Some... Interesting math
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int strlen(char s[]) {
	int i = 0;
	while (s[i] != '\0') ++i;
	return i;
}

void append(char s[], char n) {
	int len = strlen(s);
	s[len] = n;
	s[len+1] = '\0';
}

void backspace(char s[]) {
	int len = strlen(s);
	s[len-1] = '\0';
}

// Returns <0 if s1<s2, 0 if s1==s2, >0 if s1>s2
int strcmp(char s1[], char s2[]) {
	int i;
	for (i = 0; s1[i] == s2[i]; i++) {
		if (s1[i] == '\0') return 0;
	}
	return s1[i] - s2[i];
}

//supports up to 128 arguments and 1024 characters per argument
/*char* splitstr(char string[], char separator) {
	char array[128][1024] = {
		"test",
		"test",
		"test"
	};

	return array;
}*/
