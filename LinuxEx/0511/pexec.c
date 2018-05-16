#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
		printf("Running ps with eleclp\n");
		execlp("ps","ps","-ax",(char *)NULL);
		printf("Done.\n");
		exit(0);
}
