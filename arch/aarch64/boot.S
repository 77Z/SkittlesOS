// AArch64 mode

.section ".text.boot"
 
.globl _start
 
    .org 0x80000
// Entry point for the kernel. Registers:
// x0 -> 32 bit pointer to DTB in memory (primary core only) / 0 (secondary cores)
// x1 -> 0
// x2 -> 0
// x3 -> 0
// x4 -> 32 bit kernel entry point, _start location
_start:
    // set stack before our code
    ldr     x5, =_start
    mov     sp, x5
1:
    // clear bss
    ldr     x5, =__bss_start
    ldr     w6, =__bss_size
3:  cbz     w6, 4f
    str     xzr, [x5], #8
    sub     w6, w6, #1
    cbnz    w6, 3b
 
    // jump to C code, should not return
4:  bl      kernel_main
    // for failsafe, halt this core too
    b 1b
