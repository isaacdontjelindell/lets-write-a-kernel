#### Let's Write A Kernel

The code for this came from [this](http://arjunsreedharan.org/post/82710718100/kernel-101-lets-write-a-kernel) tutorial.

##### To Build and Run

`$ nasm -f elf32 kernel.asm -o kasm.o`
`$ gcc -m32 -c kernel.c -o kc.o`
`$ ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o`

Will generate a kernel called `kernel`.

Can be run in QEMU:

`$ qemu-system-i386 -kernel kernel`
