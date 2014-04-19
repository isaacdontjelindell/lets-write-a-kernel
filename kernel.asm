;;kernel.asm
bits 32         ;nasm directive - 32 bit
section .text

global start
extern kmain    ;kmain is defined in the c file

start:
    cli         ;block interrupts
    call kmain
    hlt         ;halt the cpu
