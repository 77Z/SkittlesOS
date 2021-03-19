; Arch: x86_64
; Author: Vince R
; File: bootsect.asm

; Sort of like the starting memory address
[org 0x7c00]

mov ah, 0x0e	; Enable tty mode
mov al, 'H'	; Move character into al register
int 0x10	; "Execute" print function
mov al, 'e'
int 0x10
mov al, 'l'
int 0x10
int 0x10
mov al, 'o'
int 0x10

mov al, [the_secret]
int 0x10

mov bp, 0x8000	; this is an address far away from 0x7c00 so that we don't get overwritten
mov sp, bp	; if the stack is empty then sp points to bp

push 'A'	; PUSH ADDS THINGS TO THE STACK
push 'B'

; STACK GROWS DOWNWARDS
; mov al, [0x7ffe]	; 0x8000 - 2
; int 0x10		; This shows it growing down

pop bx
mov al, bl
int 0x10 ; prints B

pop bx
mov al, bl
int 0x10 ; prints A

; Garbage collection
mov al, [0x8000]
int 0x10

jmp $

the_secret:
	db "X"

; Fill empty space
times 510-($-$$) db 0

; Magic number to tell the BIOS to boot
dw 0xaa55
