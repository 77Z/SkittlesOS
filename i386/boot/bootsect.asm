; Arch: i386
; File: bootsect.asm

[org 0x7c00]
KERNEL_OFFSET equ 0x1000	; The same number used when linking(check the Makefile)

	mov [BOOT_DRIVE], dl	; BIOS sets the boot drive in dl on boot, (So copy the bits!)
	mov bp, 0x9000
	mov sp, bp

	; Real mode printing
	mov bx, MSG_REAL_MODE
	call print
	call print_nl

	call load_kernel	; Read kernel from disk (See [bits 16])
	call switch_to_pm	; disable interrupts(int), load GDT, and all else, jumps to BEGIN_PM. See ./bootsect/32bit-switch.asm
	jmp $			; Never be executed unless something goes horribly wrong ;)

; Subroutines
%include "boot/print.asm"				; 16-bit
%include "boot/print_hex.asm"
%include "boot/disk.asm"

%include "boot/gdt.asm"					; 32-bit
%include "boot/32bit-print.asm"
%include "boot/switch_pm.asm"

[bits 16]
load_kernel:	; Called from real mode
	mov bx, MSG_LOAD_KERNEL
	call print
	call print_nl

	mov bx, KERNEL_OFFSET	; Read from disk and store in 0x1000
	mov dh, 16
	mov dl, [BOOT_DRIVE]	; BIOS gives us this drive "number"
	call disk_load
	ret


[bits 32]
BEGIN_PM:	; Called from ./bootsect/32bit-switch.asm
	mov ebx, MSG_PROTECTED_MODE
	call print_string_pm
	call KERNEL_OFFSET	; Give all control to the kernel
	jmp $			; Stay here if the kernel return control to us (not gaurenteed)

; DATA

; Constants (Null terminate them so the bios doesn't just start reading out bytes)
BOOT_DRIVE db 0
MSG_REAL_MODE db "Started in 16-bit Real Mode", 0
MSG_PROTECTED_MODE db "Landed in 32-bit Protected Mode", 0
MSG_LOAD_KERNEL db "Loading kernel into RAM", 0

; Fill empty space
times 510-($-$$) db 0

; Magic number to tell the BIOS to boot
dw 0xaa55
