; Arch: x86_64
; Author: Vince R
; File: bootsect.asm

[org 0x7c00] ; Offset

; Main

;mov bx, HELLO
;call print ; THIS ONLY PRINTS THE STRING

;call print_nl ; THis makes the newline and carriage return

;mov bx, VINCE
;call print

;call print_nl

;mov dx, 0x12fe
;call print_hex

;jmp $

mov bp, 0x8000	; set the stack away from us
mov sp, bp

mov bx, 0x9000	; es:bx = 0x0000:0x9000 = 0x09000
mov dh, 2	; read 2 sectors
; the bios sets 'dl' for our boot disk number
; if you have trouble, use the '-fda' flag: 'qemu -fda file.bin'
call disk_load	; defined in bootsect_disk.asm

mov dx, [0x9000] ; retrieve the first loaded word, 0xdada
call print_hex

call print_nl

mov dx, [0x9000 + 512] ; first word from second sector, 0xface
call print_hex

jmp $

; Subroutines

%include "bootsect/bootsect_print.asm"
%include "bootsect/bootsect_print_hex.asm"
%include "bootsect/bootsect_disk.asm"

; Data

;HELLO:
;	db 'Hello, World', 0 ; Remember the null terminating char

;VINCE:
;	db 'Vince likes low level programming', 0

; Fill empty space
times 510-($-$$) db 0

; Magic number to tell the BIOS to boot
dw 0xaa55


; Writing to the disk
times 256 dw 0x6675 ; sector 2 = 512 bytes
times 256 dw 0xface ; sector 3 = 512 bytes
