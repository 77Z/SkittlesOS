# SkittlesOS i386 Makefile

CC = i386-elf-gcc
# CC = i386-tcc
LD = i386-elf-ld
ASM = nasm
BIN = bin/i386

include config.mk

# $@ = target file
# $< = first dependency
# $^ = all dependencies

C_SOURCES = $(wildcard kernel/*.c drivers/*.c cpu/*.c libc/*.c fs/*.c)
HEADERS   = $(wildcard kernel/*.h drivers/*.h cpu/*.h libc/*.h fs/*.h)

# File extension replacement
OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o}

CFLAGS = -D${ARCH} -DVERSION=\"${FULLVER}\" -I. -ffreestanding -Wall -Wextra -fno-exceptions -m32

dirs:
	mkdir -p $(BIN)

skittles.bin: dirs arch/i386/bootsect.bin kernel.bin
	@echo [CAT  ] $@
	cat $^ > $(BIN)/$@

# '--oformat binary' deletes all symbols as a collateral.
kernel.bin: dirs arch/i386/kernel_entry.o ${OBJ}
	@echo [LINK ] $^
	@${LD} -o $@ -Ttext 0x1000 $^ --oformat binary

run: skittles.bin
	@echo [RUN  ] $<
	@qemu-system-i386 -fda $< -serial stdio



%.o: %.c ${HEADERS}
	@echo [BUILD] $<
	@${CC} ${CFLAGS} -c $< -o $@

%.o: %.asm
	@echo [ASM  ] $<
	@${ASM} $< -f elf32 -o $@

%.bin: %.asm
	@echo [ASM  ] $<
	@${ASM} $< -f bin -o $@
