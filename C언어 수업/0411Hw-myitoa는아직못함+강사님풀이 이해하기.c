// [과제#1]
// strcpy, strlen, strcat 함수를 직접 만들어보시오.
//
// char *mystrcpy(char *dest, const char *src)
// size_t mystrlen(const char *s)
// char *mystrcat(char *dest, const char *src)
// Myatoi함수, Myitoa함수 만들어보기
//


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char *mystrcpy(char *dest, const char *src)
{
	// 나의 풀이

	//int i;
	//for(i=0;src[i]!='\0';i++)
	//{
	//	*(dest+i)=*(src+i);
	//}
	//dest[i]='\0';

	// 강사님 풀이

	// 1번 방식
	// int dx;
	//for(dx=0;src[dx]!=0;dx++)
	//	dest[dx]=src[dx];
	//dest[dx]='\0';

	// 2번 방식
	// [혼자공부하면서 이해해보기]
	//
	//int a=1;
	while(*dest++=*src++); // NULL까지 복사된 후 그것을 거짓처리
	//if(a=0) puts("false"); // 이해를 돕기 위한 주석 [거짓이면 실행X란 소리]
							 // 왜 ==이 아니라 =를 넣었는지 잘 생각해보기
}

size_t mystrlen(const char *s)
{
	// 나의 풀이
	//

	//int i;
	//for(i=0;s[i]!='\0';)
	//{
	//	i++;
	//}
	//return i;

	// 강사님 풀이
	// [혼자 공부하면서 이해해보기]
	//
	char *wk=s;
	while(*wk) wk++;
	return wk-s;
}

char *mystrcat(char *dest, const char *src)
{
	// 나의 풀이
	//

	//int i;
	//int j=mystrlen(src)+1;
	//for(i=0;src[i]!='\0';i++)
	//{
	//	dest[j+i]=src[i];
	//}
	//dest[j+i]='\0';

	// 강사님 풀이
	char *save=dest;
	while(*dest) dest++;
	while(*dest++ = *src++);
	return save;
}

int zegob10(int a)
{
	int i=0;
	int result=1;
	if(a==0) return 1;
	for(i;i<a;i++)
	{
		result=result*10;
	}
	return result;
}
int Myatoi(char *dest)
{
	//0=48 9=57
	int sz=mystrlen(dest);
	int i;
	int result=0;
	int j=0;
	for(i=sz-1;i>=0;i--)
	{
		result += (dest[i]-48) * zegob10(j++);
	}
	return result;
}

char *Myitoa(const int a, char *dest, int radix)
{
	int i=zegob10(11);
	int j=0;
	do
	{
		dest[j++] = (a%i)+48;
	}while(i!=1);
	// 정확히 코딩하진 않았지만
	// 만약 이걸 내가 직접 코딩한다면
	// 10^n 으로 자리수를 구해서 나눈다음 ASCII로 대응시킬거같다
}
main()
{

	char a[10];
	char b[10];
	char c[10];

	//strcpy(a, "AAAAAAb");
	//puts(a);

	//strcpy(b,a);
	//puts(b);

	//strncat(b,"CC",1);
	//puts(b);
	
	//printf("%d\n",strlen(b));

	puts("주홍함수확인");
	mystrcpy(b,"잘되나?");
	puts(b);
	printf("len : %d\n",mystrlen(b));
	puts(b);
	
	mystrcpy(c,"TEST?");
	mystrcat(c,"good");
	puts(c);
	puts("");
	printf("Myatoi:%d\n",Myatoi("12353536"));
}