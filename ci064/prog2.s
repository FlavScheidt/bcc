.section .data
	a: .int 0
	b: .int 0
.section .text
.globl _start
_start:
	movl $6, a
	movl $7, b
	movl a, %eax
	movl b, %ebx
	addl %eax, %ebx
	movl $1, %eax
	int $0x80
