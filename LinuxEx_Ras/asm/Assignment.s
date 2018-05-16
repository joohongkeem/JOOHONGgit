.data

starting: 
	.asciz "JooHong's Assembly Language Assignment"

.balign 4
message1:
	.asciz "Input Num1 : "

.balign 4
message2:
	.asciz "Input Num2 : "

.balign 4
addresult:
	.asciz "[%d] + [%d] = [%d]\n"

.balign 4
subresult:
	.asciz "[%d] - [%d] = [%d]\n"

.balign 4
mulresult:
	.asciz "[%d] * [%d] = [%d]\n"

.balign 4
divresult:
	.asciz "[%d] / [%d] = [%d]\n"

.balign 4
diverror:
	.asciz "(Error)Can't divide by 0\n"

.balign 4
unvalidinput:
	.asciz "(Error)Invalid Input \n"

.balign 4
scan_pattern : 
	.asciz "%d"

.balign 4
number1_read :
	.word 0
.balign 4
number2_read :
	.word 0

.balign 4
return:
	.word 0

.balign 4
return2:
	.word 0

.balign 4
return3:
	.word 0

.balign 4
return4:
	.word 0

.balign 4
return5:
	.word 0

.text
// add_func
add_func:
	ldr r4, address_of_return2
	str lr, [r4]
	
	add r3, r1, r2
	
	// backup on StackMemory
	stmfd sp!,{r1,r2}

	// printf("%d + %d = %d", r1,r2,r3);
	// printf is r0
	ldr r0, address_of_addresult
	bl printf

	ldr lr, address_of_return2
	ldr lr, [lr]
	bx lr

address_of_return2: .word return2

sub_func:
	ldr r4, address_of_return3
	str lr, [r4]

	sub r3, r1, r2

	// backup on StackMemory
	stmfd sp!,{r1,r2}

	// printf("%d - %d = %d",r1,r2,r3);
	// printf is r0
	ldr r0, address_of_subresult
	bl printf

	ldr lr, address_of_return3
	ldr lr, [lr]
	bx lr

address_of_return3: .word return3

mul_func:
	ldr r4, address_of_return4
	str lr, [r4]
	
	mul r3, r1, r2

	// backup on StackMemory
	stmfd sp!,{r1,r2}

	// printf("%d * %d = %d",r1,r2,r3);
	// printf is r0
	ldr r0, address_of_mulresult
	bl printf
	
	ldr lr, address_of_return4
	ldr lr, [lr]
	bx lr

address_of_return4: .word return4

div_func:
	ldr r4, address_of_return5
	str lr, [r4]

	stmfd sp!,{r1,r2}
	
	cmp r2, #0
	beq error

	cmp r1, #0
	bge r1plus
	add r5, r1, r1
	sub r1, r1, r5

r1plus:
	cmp r2, #0
	bge r2plus
	add r5, r2, r2
	sub r2, r2, r5

r2plus:
	mov r3, #0 // r3 means the div-result
	
Loop:
	sub r1, r1, r2
	cmp r1, #0
	addge r3, r3, #1
	ble normal
	b Loop
normal:	
	ldmia sp!,{r1,r2}
	stmfd sp!,{r1,r2}
	mul r4, r1,r2
	cmp r4, #0
	bge printing
	add r5, r3, r3
	sub r3, r3, r5
	
printing:
	ldmia sp!,{r1,r2}	
	ldr r0, address_of_divresult
	bl printf
	b end
	
error:	ldr r0, address_of_diverror
	bl puts
	b end

end:
	ldr lr, address_of_return5
	ldr lr, [lr]
	bx lr
	
address_of_return5: .word return5
	
.global main
main:
	// Printing Starting Message
	ldr r1, address_of_return
	str lr, [r1]

	ldr r0, address_of_starting
	bl puts
	
	// Printing "Input Num1" Message

	ldr r0, address_of_message1
	bl printf

	

	// Scanning "Num1"
	ldr r0, address_of_scan_pattern
	ldr r1, address_of_number1_read
	bl scanf
	
	//ldr r1, address_of_number1_read
	//ldr r1, [r1]	

	cmp r0, #1
	bne ERROR
	
	// Printing "Input Num2: Message
	ldr r0, address_of_message2
	bl printf


	// Scanning "Num2"
	ldr r0, address_of_scan_pattern
	ldr r1, address_of_number2_read
	bl scanf

	
	//ldr r1, address_of_number2_read
	//ldr r1, [r1]
	
	cmp r0, #1
	bne ERROR

	// r1 <- Num1, r2<- Num2	
	ldr r1, address_of_number1_read
	ldr r1, [r1]
	ldr r2, address_of_number2_read
	ldr r2, [r2]


	// "r1 + r2 = r3"
	bl add_func

	// recall from stack memory for Sub
	ldmia sp!,{r1,r2}
 
	// "r1 - r2 = r3" 
	bl sub_func
	
	// recall from stack memory for Mul
	ldmia sp!,{r1,r2}

	// "r1 * r2 = r3"
	bl mul_func

	// recall from stack memory for Div
	ldmia sp!,{r1,r2}

	bl div_func
	

	mov r0, #0
realend:
	ldr lr, address_of_return
	ldr lr, [lr]
	bx lr

ERROR:
	ldr r0, address_of_unvalidinput
	bl puts
	

//	ldr r0, address_of_return
	mov r0, #1
	MVN r0, r0
	ADD r0, r0, #1
	
	
//	
	ldr lr, address_of_return
	ldr lr, [lr]
	bx lr
	//b realend
	
	
	
	
	



address_of_starting : .word starting
address_of_message1 : .word message1
address_of_message2 : .word message2
address_of_scan_pattern : .word scan_pattern
address_of_number1_read : .word number1_read
address_of_number2_read : .word number2_read
address_of_return : .word return
address_of_addresult : .word addresult
address_of_subresult : .word subresult
address_of_mulresult : .word mulresult
address_of_divresult : .word divresult
address_of_diverror : .word diverror
address_of_unvalidinput : .word unvalidinput

//External
.global puts
.global scanf
.global printf