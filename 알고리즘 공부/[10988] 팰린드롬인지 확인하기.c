#include <stdio.h>
#include <string.h>

char arr[21];

int main()
{
	int i;
	int max,len;
	scanf("%s",arr);
	len = strlen(arr);
	max = (len)/2-1;
	for(i=0;i<=max;i++) if(arr[0+i]!=arr[len-1-i]) {puts("0"); return 0;}
	puts("1");
	
	return 0;
}