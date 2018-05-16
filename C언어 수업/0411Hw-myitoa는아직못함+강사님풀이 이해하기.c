// [����#1]
// strcpy, strlen, strcat �Լ��� ���� �����ÿ�.
//
// char *mystrcpy(char *dest, const char *src)
// size_t mystrlen(const char *s)
// char *mystrcat(char *dest, const char *src)
// Myatoi�Լ�, Myitoa�Լ� ������
//


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char *mystrcpy(char *dest, const char *src)
{
	// ���� Ǯ��

	//int i;
	//for(i=0;src[i]!='\0';i++)
	//{
	//	*(dest+i)=*(src+i);
	//}
	//dest[i]='\0';

	// ����� Ǯ��

	// 1�� ���
	// int dx;
	//for(dx=0;src[dx]!=0;dx++)
	//	dest[dx]=src[dx];
	//dest[dx]='\0';

	// 2�� ���
	// [ȥ�ڰ����ϸ鼭 �����غ���]
	//
	//int a=1;
	while(*dest++=*src++); // NULL���� ����� �� �װ��� ����ó��
	//if(a=0) puts("false"); // ���ظ� ���� ���� �ּ� [�����̸� ����X�� �Ҹ�]
							 // �� ==�� �ƴ϶� =�� �־����� �� �����غ���
}

size_t mystrlen(const char *s)
{
	// ���� Ǯ��
	//

	//int i;
	//for(i=0;s[i]!='\0';)
	//{
	//	i++;
	//}
	//return i;

	// ����� Ǯ��
	// [ȥ�� �����ϸ鼭 �����غ���]
	//
	char *wk=s;
	while(*wk) wk++;
	return wk-s;
}

char *mystrcat(char *dest, const char *src)
{
	// ���� Ǯ��
	//

	//int i;
	//int j=mystrlen(src)+1;
	//for(i=0;src[i]!='\0';i++)
	//{
	//	dest[j+i]=src[i];
	//}
	//dest[j+i]='\0';

	// ����� Ǯ��
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
	// ��Ȯ�� �ڵ����� �ʾ�����
	// ���� �̰� ���� ���� �ڵ��Ѵٸ�
	// 10^n ���� �ڸ����� ���ؼ� �������� ASCII�� ������ų�Ű���
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

	puts("��ȫ�Լ�Ȯ��");
	mystrcpy(b,"�ߵǳ�?");
	puts(b);
	printf("len : %d\n",mystrlen(b));
	puts(b);
	
	mystrcpy(c,"TEST?");
	mystrcat(c,"good");
	puts(c);
	puts("");
	printf("Myatoi:%d\n",Myatoi("12353536"));
}