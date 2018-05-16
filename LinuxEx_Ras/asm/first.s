/* first.s */
/* This is a comment */

.global main /* 'main' is our entry point and must be global */

main:
	mov r0, #23	// put a 23 inside the register r0
	bx lr		// return from main : r0

			// compile ?
			// as -o first.o first.s
			// gcc -o first first.o
			// ./first
			// checking return value?
			// ./first;echo $?

