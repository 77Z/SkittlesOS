; Arch: x86_64
; Author: Vince R
; File: 32bit-bootsect.asm

; REAL MODE
[org 0x7c00] ; Real mode bootloader offset
	mov bp, 0x9000 ; set the stack
	mov sp, bp

	mov bx, REAL_MODE
	call print
	call print_nl

	call switch_to_pm
	jmp $ ; Never be executed unless something goes horribly wrong ;)

; Subroutines
%include "./bootsect/bootsect_print.asm"
%include "32bit-gdt.asm"
%include "32bit-print.asm"
%include "32bit-switch.asm"


; PROTECTED MODE
[bits 32]
BEGIN_PM: ; This is executed from the 32bit-switch.asm
	mov ebx, PROTECTED_MODE ; Written in the top left corner
	call print_string_pm
	jmp $


; DATA

REAL_MODE db "Started in 16-bit real mode", 0
PROTECTED_MODE db "Loaded 32-bit protected mode", 0

; Fill empty space
times 510-($-$$) db 0

; Magic number to tell the BIOS to boot
dw 0xaa55
