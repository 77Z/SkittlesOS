#include <libc/runtime.h>
#include <drivers/screen.h>
#include <libc/stdlib.h>
#include <kernel/kernel.h>

// TODO: This doesn't print all the way
// and I really don't wanna debug it.

void bootsuccess(char* message) {
	kprint("[");
	kprint_color("***", GREEN_ON_BLACK);
	kprint("] ");
	kprint(message);
	kprint("\n");
}

void bootfailure(char* message) {
	kprint("[");
	kprint_color("***", RED_ON_BLACK);
	kprint("] ");
	kprint(message);
	kprint("\n");
}

static void printRuntimeError(char* message) {
	kprint("[");
	kprint_color("RUNTIME ERR", RED_ON_BLACK);
	kprint("] ");
	kprint(message);
	kprint("\n");
}

void runtimeError(char* message, bool systemFatal) {
	printRuntimeError(message);

	if (systemFatal) {
		printRuntimeError("FATAL, Halting CPU");
		halt_cpu();
	}
}
