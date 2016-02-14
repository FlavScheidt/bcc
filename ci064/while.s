.section .data
	i: .int 0
	a: .int 0
.section .text
.globl _start
_start:
	movl $0, i
	movl $0, a
	movl i, %eax
	while:
		cmpl $10, %eax
		jge fim_while
		movl a, %ebx
		addl %eax, %ebx
		movl %ebx, a
		addl $1, %eax
		movl %eax, i
		jmp while
	fim_while:
		movl $1, %eax
		int $0x80
