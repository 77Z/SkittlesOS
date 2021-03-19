; Arch: i386
; File: print.asm

print:
	pusha ; Push all registers to the stack

; Our string is stored like a C character array,
; so keep this code in mind:
; while (string[i] != 0) { print string[i]; i++ }

; RECEIVING DATA IN dx
start:
	mov al, [bx]	; bx is the base address for the string, like where it starts
	; cmp is an if statement, checking if it's null terminated, thats how it knows to stop
	; it means "Compare"
	cmp al, 0
	je done		; If it's null terminated, call "done"

	; Print the string with the bios's help
	mov ah, 0x0e
	int 0x10	; 'al' already contains the char

	; increment pointer and do next loop, like a for loop
	add bx, 1	; REMEMBER BX FROM THE START?
	jmp start	; Loop back to "start"

; Go back to previous code
done:
	popa
	ret

; Print_nl is easier because it's just fixed characters
; no getting strings and looping through them
print_nl:
	pusha

	mov ah, 0x0e
	mov al, 0x0a ; newline char \n
	int 0x10
	mov al, 0x0d ; carriage return \r
	int 0x10

	; Equivelent to the done subroutine
	popa
	ret
