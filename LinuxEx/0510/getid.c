#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	pid_t pid;

	sleep(5);
	printf("\nProcess Id	= %d\n",pid=getpid());
	printf("{Parent process ID	= %d\n",getppid());
	printf("Real User Id	%d\n",getuid());
	printf("Effective User ID	= %d\n",geteuid());
	printf("Real group ID	= %d\n",getgid());
	printf("Effective group ID = %d\n",getegid());
}
