[bits 32]	; Run in 32-bit Protected Mode
[extern main]	; Defines the calling point, like telling assembly where the main function is in C
call main	; This actually DOES the calling of the kernal main function
jmp $		; Never be executed unless something goes horribly wrong ;)
