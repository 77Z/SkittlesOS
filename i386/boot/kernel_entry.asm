; Arch: i386
; File: kernel_entry.asm

global _start
[bits 32]	; Run in 32-bit Protected Mode

_start:
    [extern kernel_main]	; Defines the calling point, like telling assembly where the main function is in C
    call kernel_main	; This actually DOES the calling of the kernal main function
    jmp $		; Never be executed unless something goes horribly wrong ;)
