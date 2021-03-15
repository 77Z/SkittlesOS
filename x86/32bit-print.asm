[bits 32]	; Use 32-bit protected mode
		; It's useful for virtual memory, paging and safe multi-tasking

; Defining constants, like C++'s #define
; it just replaces the values on assemble.
VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f	; The colr byte for each character

print_string_pm:
	pusha			; Push all addresses to stack
	mov edx, VIDEO_MEMORY	; REMEMBER THE CONSTANTS

print_string_pm_loop:
	mov al, [ebx]	; [ebx] is the address of our character
	mov ah, WHITE_ON_BLACK

	cmp al, 0		; if end of string
	je print_string_pm_done	; Stop printing

	mov [edx], ax	; store char and attribute in video memory
	add ebx, 1	; next char
	add edx, 2	; new video memory position

	jmp print_string_pm_loop

print_string_pm_done:
	popa
	ret
