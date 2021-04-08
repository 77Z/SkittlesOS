#include "../cpu/types.h"

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