# $@ = target file
# # $< = first dependency
# # $^ = all dependencies

include config.mk

C_SOURCES = $(wildcard kernel/*.c drivers/*.c cpu/*.c libc/*.c programs/*.c filesystem/*.c)
HEADERS   = $(wildcard kernel/*.h drivers/*.h cpu/*.h libc/*.h programs/*.h filesystem/*.h)
# File extension replacement
OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o}

CFLAGS = -ffreestanding -Wall -Wextra -fno-exceptions -m32 -DVERSION=\"${VERSION}\"

# First rule is run by default
os-image.bin: boot/bootsect.bin kernel.bin
	cat $^ > os-image.bin

# '--oformat binary' deletes all symbols as a collateral.
kernel.bin: boot/kernel_entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^ --oformat binary

run: os-image.bin
	qemu-system-i386 -fda format=raw,file=./$< -serial file:serial.log

runalt: os-image.bin
	qemu-system-i386 -fda $< -serial stdio

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin *.dis *.o os-image.bin *.elf
	rm -rf kernel/*.o boot/*.bin drivers/*.o boot/*.o cpu/*.o programs/*.o filesystem/*.o

