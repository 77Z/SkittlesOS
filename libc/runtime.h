#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include <libc/stdlib.h>

void bootsuccess(char* message);
void bootfailure(char* message);
void runtimeError(char* message, bool systemFatal);

#endif /* _RUNTIME_H_ */
