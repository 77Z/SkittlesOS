; Arch: x86_64
; Author: Vince R
; File: bootsect_print_hex.asm

; RECEIVING DATA IN dx
print_hex:
	pusha		; Push all registers to the stack

	mov cx, 0	; our index variable, like the i in a for loop

hex_loop:
	cmp cx, 4	; loop 4 times, the middle part of a for loop i < 4
	je end

	; Step 1, convert the last char of 'dx' to ascii
	mov ax, dx	; use 'ax' as a working area register
	and ax, 0x000f	; Mask the last byte, for example 0x1234 turns into 0x0004
	add al, 0x30	; add 0x30 to convert it to an ASCII char, example: N to ASCII "N"
	cmp al, 0x39	; if > 9, add extra 8 to represent 'A' to 'F'
	jle step2
	add al, 7	; 'A' is ASCII 65 instead of 58, so 65 - 58 = 7

step2:
	; Step 2, get the correct position of the string to place our ASCII char
	; bx <- base address + string length - index of char
	mov bx, HEX_OUT + 5	; base + length
	sub bx, cx		; our index variable
	mov [bx], al		; copy the ASCII char on 'al' to the position pointed by 'bx'
	ror dx, 4		; 0x1234 -> 0x4123 -> 0x3412 -> 0x2341 -> 0x1234

	; increment index and loop
	add cx, 1
	jmp hex_loop

end:
	; Prepare the parameter and call the function
	; remember that print receives parameters in 'bx'
	mov bx, HEX_OUT
	call print

	popa
	ret

HEX_OUT:
	db '0x0000', 0	; reserve memory for our new string
