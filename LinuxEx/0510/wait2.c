#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
void pr_exit(int* status);
int main(){
	
	pid_t pid;
	char *message;
	int n;
	int exit_code;
	FILE *a;
	printf("fork program starting\n");
	if((a=fopen("test.txt","w"))==NULL){
	printf("errorfile");
	return 0;
	}
	pid=fork();

	switch(pid){
		case -1:
				fputs("fork failed\n",a);
				perror("fork failed");
				exit(1);
		case 0:
				message="This is the child\n";
				//fputs(message,a);
				n=5;
				exit_code=37;
				break;
		default:
				message = "This is the parent\n";
				//fputs(message,a);
				n=3;
				exit_code=0;
						break;
	}
	for(;n>0;n--){
		fputs(message,a);
			puts(message);
		//fputs(message,a);
		sleep(1);
	}

	if(pid !=0){
		int stat_val;
		pid_t child_pid;
		
		child_pid=wait(&stat_val);
		printf("Child has finished: PID=%d\n",child_pid);
		pr_exit(&stat_val);
		//if(WIFEXITED(stat_val))printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
		//else printf("Child terminated abnormally\n");
	}
	fclose(a);

	exit(exit_code);
}
void pr_exit(int* status){
	if(WIFEXITED(status))
			printf("normal termination,exit status = %d\n",WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
			printf("abnormal termination, signal number = %d%s\n",WTERMSIG(status),
							WCOREDUMP(status)?"(core file generated)":"");
	else if(WIFSTOPPED(status))
			printf("child stopped, signal number = %d\n",WSTOPSIG(status));
}
