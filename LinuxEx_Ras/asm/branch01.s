

.text
.global main

main:

	mov r1, #2
	mov r2, #30-28		//This case is also r2=30-28
	cmp r1, r2		//return the result of compare
	beq end
				//b means 'unconditional branch'
	mov r0, #20		//not be excuted (why? b end)
	bx lr
/* Branch condition
	EQ:Equal
	NE:Not Equal
	CS/HS:Unsigned higher or same
	CC/LO:unsigned lower
	MI:Minus
	PL:Positive or Zero
	....
*/ 


end :
	mov r0, #10
	bx lr
