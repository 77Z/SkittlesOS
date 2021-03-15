.PHONY: all bootsect boot

all:
	@echo Options:
	@echo "    bootsect"
	@echo "    boot"

bootsect:
	nasm -f bin ./bootsect/bootsect.asm -o ./bin/bootsect.bin

boot:
	qemu-system-x86_64 ./bin/bootsect.bin
