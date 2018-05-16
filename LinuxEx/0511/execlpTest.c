#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(void){

	int status;
	pid_t pid;
	//자식 프로세스 생성
	pid=fork();
	switch(pid){
		case -1:
				printf("fork 생성 실패\n");
				exit(-1);
		case 0:
				execlp("./hello","hello","",(char*)NULL);
				exit(0);
		default:
				printf("parents process\n");
				printf("child pid = %d\n",pid);
				break;

	}
	pid = wait(&status);
	printf("exit process pid = %d\n",pid);

		return 0;
}
