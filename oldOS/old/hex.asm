[org 0x7c00]


mov dx, 0x10
call print_hex


jmp $

%include "../i386/boot/print.asm"
%include "../i386/boot/print_hex.asm"

times 510-($-$$) db 0

dw 0xaa55