//if even, divide by 2
//if odd, multiply 3 and plus 1
//how many operations are needed to make r1 into 1?
.text
.global main

main:
	mov r1,#123			// r1 <- 123
	mov r2,#0			// r2 <- 0

loop:
	cmp r1, #1			// r1 == 1?
	beq end				// if(r1==1) branch to end

	and r3, r1, #0			// r3 <- r1&0
	cmp r3, #0			// r3 == 0?
					// if true, r1 is even num
					// if false,r1 is odd num
	bne odd				// if r1 is odd, branch to odd

even:
	mov r1, r1, ASR #1		// r1 <-(r1>>1)
					// thus, r1 = r1/2
	b end_loop			// branch to end_loop

odd:
	add r1, r1, r1, LSL #1		// r1 <- r1 + (r1<<1)
					// r1 = r1+ 2*r1 = 3*r1
	add r1, r1, #1			// r1 = r1+1 , so r1 = 3*r1 + 1

end_loop:
	add r2, r2, #1			// r2 <- r2+1
	b loop				// branch to loop

end:
	mov r0, r2			// return r0
	bx lr		
