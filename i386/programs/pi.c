#include "../libc/Skittles.h"

#define SCALE 10000
#define ARRINIT 2000

void pi_digits(int digits) {
	int carry = 0;
	int arr[digits + 1];
	for (int i = 0; i <= digits; ++i)
		arr[i] = ARRINIT;
	for (int i = digits; i > 0; i-= 14) {
		int sum = 0;
		for (int j = i; j > 0; --j) {
			sum = sum * j + SCALE * arr[j];
			arr[j] = sum % (j * 2 - 1);
			sum /= j * 2 - 1;
		}

		int finalDigit = carry + sum / SCALE;
		char digitStorage[1];
		SKIT_int_to_ascii(finalDigit, digitStorage);
		SKIT_print(digitStorage);
		carry = sum % SCALE;
	}
}

void PI_main() {
	SKIT_print("3.");
	pi_digits(100000);
}