#include <libc/stdio.h>
#include <drivers/screen.h>

void putchar(char character) {
	char outstring[2];
	outstring[0] = character;
	outstring[1] = '\0';
	kprint(outstring);
}

void print(const char* format, ...) {
	int i = 0;
	while (format[i] != 0) {
		char currentChar = format[i];
		char fmtChar = 0; //Unset by default

		if (currentChar == '%') {
			fmtChar = i + 1;

			switch(fmtChar) {
				case 'i': {
						  //
					  }
			}
		} else {
			putchar(format[i]);
		}

		i++;
	}
}
