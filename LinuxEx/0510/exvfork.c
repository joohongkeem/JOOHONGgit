#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	pid_t pid;
	char *message;
	int n,sum1=0,sum2=0;
	int exit_code;
	pid=vfork();
	switch(pid){
			case -1:
					exit(1);
			case 0:
					for(n=1;n<=5000;n++)sum1+=n;
					printf("부모 실행");
					exit(0);
			default:
					for(n=5001;n<=10000;n++)sum2+=n;
					printf("자식 실행");
					break;
	}
	if(pid!=0)
	printf("%d 	%d	%d\n",sum1,sum2,sum1+sum2);
		exit(0);
}

