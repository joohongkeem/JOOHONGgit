#include <stdio.h>
#include <string.h>

#define DEBUG

int main(void)
{
	int i;
	char strInput[51];
	int strSize;
	
	// 1. 문자열을 입력 받는다.(최대 50 문자 + NULL문자)
	
	scanf("%s", strInput);

#ifdef DEBUG
	printf("%s\n", strInput);
#endif
	// 2. 입력받은 문자열이 영문소문자인지 확안힌다.
	//    그 이외의 입력을 받게되면 메세지를 출력하고 종료
	
	for(i=0; i<strlen(strInput);i++)
	{
		if(strInput[i] < 'a' && strInput[i] > 'z')
		{
			puts("Error : strInput");
			return -1;
		}
	}

#ifdef DEBUG
	puts("strInput is OK");
#endif
	// 3. 팰린드롭인지 확인한다.
	strSize = strlen(strInput);
	
	if(strSize % 2)
		puts("strSize is odd");
	else
		puts("strSize is even");

	for(i = 0; i < (strSize>>1);i++)
	{
		if(strInput[i] != strInput[strSize -1 -i])
		{
			puts("strInput is not pallindrome");
			return -1;
		}
	}
	
	return 0;
}
