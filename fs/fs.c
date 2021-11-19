#include <cpu/types.h>
#include <drivers/screen.h>
#include <libc/string.h>

// The filesystem that Skittles is going to support is
// USTAR. Very simple filesystem which is a good thing for me!

// I don't think this works as it's initialized in global space
int GLOBAL_bootdrive = 0;

// PUBLIC FUNCTIONS

// Function to only be called once, and only by the kernel,
// the kernel is the one that recives the bootdrive number
// from the bootsect, so that's passed here, 1 on success, 0 on fail
int initFS(int bootdrive) {
    GLOBAL_bootdrive = bootdrive;
    return 1;
}

// Replace data in a file, file needs to exists, returns 1 on success, 0 on fail
int write_file(char *file_location, char* data) {
    char drive[32];
    int_to_ascii(GLOBAL_bootdrive, drive);
    kprint(drive);
    return 1;
}

// Create a file, returns 1 on success, 0 on fail
int create_file(char *file_location) {
    return 1;
}

//PRIVATE FUNCTIONS

void write_fs() {}
void read_fs(/* u32 offset */) {
    //asm volatile("mov %ah, 0x02");
}

// Convert ASCII octal number to binary, stolen from osdev wiki
int oct2bin(unsigned char *str, int size) {
    int n = 0;
    unsigned char *c = str;
    while (size-- > 0) {
        n *= 8;
        n += *c - '0';
        c++;
    }
    return n;
}