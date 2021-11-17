#include "serial.h"
#include "../cpu/ports.h"
#include "screen.h"

// Initialize Serial Ports for data transfer,
// Returns 1 on success, 0 on fail
int init_serial() {
	port_byte_out(PORT1 + 1, 0x00); // Disable all interrupts
	port_byte_out(PORT1 + 3, 0x80); // Set baud baud rate divisor
	port_byte_out(PORT1 + 0, 0x03); // Set divisor to 3 (lo byte) 30400
	port_byte_out(PORT1 + 1, 0x00); //                  (hi byte)
	port_byte_out(PORT1 + 3, 0x03); // 8 bits, no parity, one stop bit
	port_byte_out(PORT1 + 2, 0xC7); // Enable FIFO, clear them, with 14-byte threshold
	port_byte_out(PORT1 + 4, 0x0B); // IRQs enabled, RTS/DSR set
	port_byte_out(PORT1 + 4, 0x1E); // Set in loopback mode, test the serial chip
	port_byte_out(PORT1 + 0, 0xAE); // Test serial chip (send byte 0xAE and check if serial returns same byte)

	// Check if serial is faulty (the last check above)
	if (port_byte_in(PORT1 + 0) != 0xAE) {
		return 0;
	}

	// If serial is good to go, set normal operation mode
	// (not-loopback with IRQs enabled and OUT#1 and OUT#2 bits enabled)
	port_byte_out(PORT1 + 4, 0x0F);
	return 1;
}

// READING SERIAL
int serial_received() {
	return port_byte_in(PORT1 + 5) & 1;
}

char read_serial() {
	while (serial_received() == 0);
	return port_byte_in(PORT1);
}

// WRITING SERIAL
int is_transmit_empty() {
	return port_byte_in(PORT1 + 5) & 0x20;
}

void write_serial(char a) {
	while (is_transmit_empty() == 0);
	port_byte_out(PORT1, a);
}

void printserial(char *message) {
	int i = 0;
	while (message[i] != 0) { // Loop through message until hit NULL
		write_serial(message[i++]);
	}
}

// Prints to both the screen and serial ports
void doubleprint(char *message) {
	printserial(message);
	kprint(message);
}
