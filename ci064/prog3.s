.section .text
.globl _start
_start:
	movl $0, %eax
	movl $10, %ebx
	loop:
		cmpl %ebx, %eax
		jg fim_loop
		add $1, %eax
		jmp loop
	fim_loop:
		movl $1, %eax
		int $0x80
