#include<stdio.h>

/*
 main.c
 printf.c
 input.c
 */

extern void print(char* str);
extern char* input();

int main(void){

	char* str = input();
	print(str);
	print("\n");
	return 0;
}
