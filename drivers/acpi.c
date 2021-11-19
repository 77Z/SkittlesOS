#include "acpi.h"

#include "screen.h"
#include <cpu/ports.h>

void shutdown() {
	// QEMU Specific Shutdown
	port_word_out(0x604, 0x2000);
}
