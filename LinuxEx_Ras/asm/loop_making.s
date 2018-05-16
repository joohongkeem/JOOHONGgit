// for(i=1; i<100; i++) a[i] = i;
//


.data
	.balign 4;
a:	.skip 400		//memory allocation 4*100=400;

.text
.global main
main:
	ldr r1, addr_of_a	// r1<-&a
	mov r2, #0		// r2<-0

loop:
	cmp r2, #100		// have we reached 100 yet?
	beq end			// if so, leave the loop
	add r3, r1, r2, LSL #2 	// r3 <- r1 + (r2*4)
	
	//add r4, r2, #1	// if you wants a[i]=i+1;
	//str r4, [r3]          // type this instead of str r2,[r3]

	// this is for a[i] = 3*i+1;
	// mov r4, r2, LSL #1	// r4 = r2 * 2
	// add r4, r4, r2	// r4 = r4+r2
	// add r4, r4, #1
	// str r4, [r3]		// a[i] = i;
	// add r2, r2, #1	// r2 = r2+1
	// b loop		// loop

	str r2, [r3]		// *r3 <- r2
	add r2, r2, #1		// r2 <- r2 + 1
	b loop			// go to the beginning of loop
	
end:
	bx lr

addr_of_a: .word a
