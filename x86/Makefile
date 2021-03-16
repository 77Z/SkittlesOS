# $@ = target file
# # $< = first dependency
# # $^ = all dependencies
.PHONY: all bootsect boot

all: run

build:
	bootsect.bin
	kernel_entry.o
	kernel.o

# Layed out like this so you can compile individual files as needed

# C

kernel.o: kernel.c
	gcc -ffreestanding -c $< -o $@

# Assembly

kernel_entry.o: kernel_entry.asm
	nasm $< -f elf -o $@

bootsect.bin: 32bit-bootsect.asm
	nasm -f bin $< -o $@

# "Executables"

# The full kernel includes the kernel_entry.o and kernel.o
kernel.bin: kernel_entry.o kernel.o
	ld -o $@ -Ttext 0x1000 $^ --oformat binary

os-image.bin: bootsect.bin kernel.bin
	cat $^ > $@

# Running

run: os-image.bin
	qemu-system-x86_64 $<


#bootsect:
#	nasm -f bin ./bootsect/bootsect.asm -o ./bin/bootsect.bin

#boot:
#	qemu-system-x86_64 ./bin/bootsect.bin
