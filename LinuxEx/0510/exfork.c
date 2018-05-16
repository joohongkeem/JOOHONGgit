#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
void pr_exit(int status);
int main(){
	pid_t pid;
	char *message;
	int n,sum=0;
	int exit_code;
	char ch;
	pid=fork();
	switch(pid){
			case 0:
					for(n=0;n<=5000;n++)sum+=n;
					break;
			default:
					for(n=5001;n<=10000;n++)sum+=n;
					break;
	}
	for(n=0;n<3;n++){
		printf("%d\n",sum);
		sleep(1);
	}
	if(pid!=0){
			int stat_val;
			pid_t child_pid;
			child_pid=wait(&stat_val);
			//pr_exit(stat_val);
			//scanf("%c",&ch);
			if(WIFEXITED(stat_val))
					//exit(-1);
					printf("정상:%d",WIFEXITED(stat_val));			
			else
					//exit(0);
					printf("비정상");
	}
	
		exit(38);

}
void pr_exit(int status){
	if(WIFEXITED(status))printf("normal %d\n",WEXITSTATUS(status));
	else if(WIFSIGNALED(status))printf("abnormal %d\n",WTERMSIG(status));
	else if(WIFSTOPPED(status))printf("child stopped %d\n",WSTOPSIG(status));
}
