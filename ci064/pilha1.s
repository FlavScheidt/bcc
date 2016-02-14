.section .data 
	a: .int 0
	b: .int 0
.section .text
.globl _start
soma:
	push (%ebp)
	movl %esp, %ebp
	movl a, %eax
	movl b, %ebx
	addl %eax, %ebx
	movl %ebx, %eax
	pop (%ebp)
	ret
_start: 
	movl $4, a
	movl $5, b
	call soma
	movl %eax, %ebx
	movl $1, %eax
	int $0x80
