#include <stdio.h>


int global = 10;

main() {
		 int i = 20; int  pid; int status;

		  if ((pid = fork()) == 0) { /* child process */
				   global = global+10; i = i + 10;
				    }
		   else {
				    /* fork() returns a pid != 0 */
				    /* parent process */
							 global = global+100; i = i + 100;

					 }
		    printf("global = %d; i = %d\n",global,i);
} 
