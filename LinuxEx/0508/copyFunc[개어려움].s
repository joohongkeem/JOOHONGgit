	.file	"copyFunc[\352\260\234\354\226\264\353\240\244\354\233\200].c"
	.section	.rodata
.LC0:
	.string	"Usage : copy file1 file2"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1072, %rsp
	movl	%edi, -1060(%rbp)
	movq	%rsi, -1072(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpl	$2, -1060(%rbp)
	jg	.L2
	movl	$.LC0, %edi
	call	perror
	movl	$-1, %eax
	jmp	.L8
.L2:
	movq	-1072(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open
	movl	%eax, -1052(%rbp)
	cmpl	$0, -1052(%rbp)
	jns	.L4
	movq	-1072(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	perror
	movl	$-1, %eax
	jmp	.L8
.L4:
	movq	-1072(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movl	$384, %edx
	movl	$577, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open
	movl	%eax, -1048(%rbp)
	cmpl	$0, -1048(%rbp)
	jns	.L6
	movq	-1072(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	perror
	movl	$-1, %eax
	jmp	.L8
.L7:
	movl	-1044(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-1040(%rbp), %rcx
	movl	-1048(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
.L6:
	leaq	-1040(%rbp), %rcx
	movl	-1052(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	%eax, -1044(%rbp)
	cmpl	$0, -1044(%rbp)
	jg	.L7
	movl	-1052(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	-1048(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	$0, %eax
.L8:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L9
	call	__stack_chk_fail
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
