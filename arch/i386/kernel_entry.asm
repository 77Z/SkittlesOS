; SkittlesA
; Arch: i386
; File: arch/i386/kernel_entry.asm

global _start
[bits 32]	; Run in 32-bit Protected Mode

_start:
	[extern kernel_main]	; Defines the calling point, like telling assembly where the main function is in C
	;mov ecx, ebx	; Dummy register value for the kernel to pick up
	mov ebx, 5
	call kernel_main	; This actually DOES the calling of the kernal main function
	jmp $		; Never be executed unless something goes horribly wrong
