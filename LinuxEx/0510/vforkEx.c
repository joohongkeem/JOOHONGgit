#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int glob = 6;
int main(void)
{
		 int var;
		 pid_t pid;
		 var = 88;
		 printf("before vfork\n");
		 if((pid=vfork())<0) perror("vfork error");
		 else if(pid==0)
		 {
			 glob++;
			 var++;
			 exit(0);	// vfork는 중간에 종료해줘야 함 & else가 없다
			 			// wait X
		 }
		 exit(0);
		 
}
