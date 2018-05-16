// Data Section
.data

.balign 4		//.balign 4 means int in visual studio
myvar1:
	.word 0		//.word means the initial value

.balign 4
myvar2:
	.word 0


// Code Section
.text
.balign 4
.global main

main:
	//remember this form that how we can insert value in variables
	//ldr >> mov >> str
	ldr r1, addr_of_myvar1
	mov r3, #33	//r3<-33	
	str r3, [r1]	//str r3, [r1]
			//insert the data in r3 into address of r1

	ldr r2, addr_of_myvar2
	mov r3, #44	//r4<-44
	str r3, [r2]

	// load01.s
	ldr r1, addr_of_myvar1
	ldr r1, [r1]
	ldr r2, addr_of_myvar2
	ldr r2, [r2]
	add r0, r1, r2
	bx lr


addr_of_myvar1 : .word myvar1
addr_of_myvar2 : .word myvar2
