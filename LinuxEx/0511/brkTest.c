#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void){
	char *ptr;
	//void* a;
	printf("before end data seg addr : %10p\n",sbrk(0));//sbrk(0)현제의 endbreak주소를 반환
	ptr= malloc(0x1000);
	printf("effter end data seg addr : %10p\n",sbrk(0));
	
	if(sbrk(0x1000)==(void*)-1)
			printf("sbrk error\n");
	printf("call sbrk(0x1000) : %10p\n",sbrk(0));
	
	if(brk(sbrk(0)+0x1000)!=0)
			printf("brk erron\n");
	printf("call brk : %10p\n",sbrk(0));
	free(ptr);
	exit(0);
}
