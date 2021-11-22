include config.mk

none:
	make -f $(ARCH).mk

.PHONY: clean

clean:
	rm -rf *.bin *.dis *.o skittles.bin *.elf
	rm -rf kernel/*.o drivers/*.o cpu/*.o fs/*.o arch/i386/*.bin arch/i386/*.o libc/*.o
