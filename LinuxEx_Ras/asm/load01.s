// Data Section (segment)
.data
// Ensure Variable is 4-byte aligned
.balign 4
// Define storage for myvar1
myvar1:
// myvar1 is just 4bytes containing value '3'
	.word 3	


.balign 4
myvar2:
	.word 4





// Code Section (segment)
.text

.balign 4
.global main

main:
	ldr r1, addr_of_myvar1	//ldr is more good than mov if 32bit
				//address is in r1
	ldr r1, [r1]		//so, we should access the data in r1 by [r1]
	ldr r2, addr_of_myvar2
	ldr r2, [r2]
	add r0, r1, r2
	bx lr
	
// Lables needed to access data [similar to Pointer]
addr_of_myvar1 : .word myvar1
addr_of_myvar2 : .word myvar2	
