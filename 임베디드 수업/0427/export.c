#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int main()
{
	char strDIR[30];
	char strNAME[10];
	char strResult[50];

	sprintf(strDIR, "%s", getenv("FILEDIR"));
	sprintf(strNAME, "%s", getenv("FILENAME"));	
 	sprintf(strResult, "gcc -o hello ");
	strcat(strResult, strDIR);
	strcat(strResult, strNAME);
	printf("%s\n", strResult);
	system(strResult);	

	return 0; 
}
