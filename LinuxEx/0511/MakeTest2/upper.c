#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int ch;
	while((ch=getchar())!=EOF){
		putchar(toupper(ch));
	}
	sleep(10);
	return 0;
}

