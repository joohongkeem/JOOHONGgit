#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void sigHandler(int sig){
	static int cnt =0;
	printf("OUCH! - i got signal %d\n",sig);
	cnt ++;
	if(cnt==5)
		(void)signal(SIGINT,SIG_DFL);
}

int main(void){
	if(signal(SIGQUIT,sigHandler)==SIG_ERR){
			printf("Failed call signal()\n");
			//printf("perror\n");
			//exit(-1);
	}
			while(1){
			printf("Hello World!\n");
			sleep(3);
			}
	return 0;
}
