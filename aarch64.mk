all:
	aarch64-elf-as -c arch/aarch64/boot.S -o arch/aarch64/boot.o

CC = aarch64-elf-gcc
LD = i386-elf-ld
NASM = aarch64-elf-as

include config.mk

C_SOURCES = $(wildcard kernel/*.c drivers/*.c cpu/*.c libc/*.c fs/*.c)
HEADERS   = $(wildcard kernel/*.h drivers/*.h cpu/*.h libc/*.h fs/*.h)

OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o}

CFLAGS = -D${ARCH} -DVERSION=\"${FULLVER}\" -I. -ffreestanding -Wall -Wextra -fno-exceptions -m32

#skittles-aarch64.bin: arch/aarch64/boot.o kernel.bin

%.o: %.c ${HEADERS}
	@echo [BUILD] $<
	@${CC} ${CFLAGS} -c $< -o $@