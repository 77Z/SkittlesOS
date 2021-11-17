#ifndef _SERIAL_H_
#define _SERIAL_H_

#define PORT1 0x3F8	// COM1
#define PORT2 0x2F8	// COM2
#define PORT3 0x3E8	// COM3
#define PORT4 0x2E8	// COM4

int init_serial();
char read_serial();
void write_serial(char a);
void printserial(char *message);
void doubleprint(char *message);

#endif /* _SERIAL_H_ */
