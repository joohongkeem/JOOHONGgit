#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #1.���� 2���� �迭�� scanf�� ����Ͽ� ���� �ְ�
//	  ��� ��Ҹ� ���, ��� ����� �� ���, �� �� ���� ū ��� ���
//    ��� ���� �հ� ���� �� ���. 

//main()
//{
//	int a[2][3];
//	int i,j;
//	int sum=0, max;
//	int hangsum[2]={0};
//	int yulsum[3]={0};
//	for(i=0;i<2;i++)
//	{
//		for(j=0;j<3;j++)
//		{
//			scanf("%d",&a[i][j]);
//			sum += a[i][j];
//			hangsum[i] += a[i][j];
//		}
//	}
//	max = a[0][0];
//	for(i=0;i<3;i++)
//	{
//		for(j=0;j<2;j++)
//		{
//			if(a[j][i]>max) max = a[j][i];
//			
//		yulsum[i] += a[j][i];
//
//		}
//	}
//
//	for(i=0;i<2;i++)
//	{
//		for(j=0;j<3;j++)
//		{
//			printf("[%d]",a[i][j]);
//		}
//		printf("  | %d\n", hangsum[i]);
//	}
//	puts("-----------");
//	for(i=0;i<3;i++)
//		printf(" %d ", yulsum[i]);
//	puts("");
//	printf("MAX : %d , SUM : %d \n",max,sum);
//
//}



// #2. �����͸� �̿��Ͽ� ���� �ΰ��� ���� ���� �ٲ㺸��.
//

//main()
//{
//	int a=50;
//	int b=90;
//	int temp;
//
//	int *pa = &a;
//	int *pb = &b;
//
//	printf("BEFORE : a=%d  b=%d \n",a,b);
//
//	temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//	
//	printf(" AFTER : a=%d  b=%d \n",a,b);
//}


// #3. �������� �Լ� ȣ���� �̿��Ͽ� �ΰ��� ���� ���� �ٲ㺸��.
//
//void change(int *a, int*b)
//{
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//main()
//{
//	int a=50;
//	int b=90;
//
//	printf("BEFORE : a=%d  b=%d \n",a,b);
//
//	change(&a,&b);
//	printf(" AFTER : a=%d  b=%d \n",a,b);
//}


// #4. main�Լ��� �ִ� 1���� �迭�� ���� �ִ� �Լ�
//    �� ���� ����ϴ� �Լ�

// #5. putstring�Լ����� a�迭�� ���� �� 'k'�� ������ ������ ����ϱ�

//void getNum(int a[])
//{
//	int i=0;
//	for(i;i<5;i++) scanf("%d",&*(a+i));
//}
//
//void putNum(int *a)
//{
//	int i=0;
//	for(i;i<5;i++) printf("a[%d]=%d \n",i,a[i]);
//}
//
//void putstring(char *b)
//{
//	int i=0;
//	for(i;;i++)
//	{
//		if(b[i]!='k') printf("%c",b[i]);          // ���ǹ��ȿ� if���� ������ ���� ���� �ڵ�*********
//		if (b[i]=='k') break;                     // for���� ���Ǿȿ� b[i]!=k�� ���Ĺ�����!!!
//	}
//	putchar('\n');
//}
//main()
//{
//	int a[5];
//	
//	char b[]="abcdefghijklmnopqrstuvwxyz";
//	getNum(a);
//	putNum(a);
//
//	putstring(b);
//	puts(b);
//}


// #6. ���ڿ� �Լ� �̿��غ���
//
//main()
//{
//
//	char a[10];
//	char b[10];
//	char c[10];
//
//	strcpy(a, "AA");
//	puts(a);
//
//	strcpy(b,a);
//	puts(b);
//
//	strncat(b,"CC",1);
//	puts(b);
//	
//	printf("%d\n",strlen(b));
//}

// [����#1]
// strcpy, strlen, strcat �Լ��� ���� �����ÿ�.
//
// char *mystrcpy(char *dest, const char *src)
// size_t mystrlen(const char *s)
// char *mystrcat(char *dest, const char *src)
// Myatoi�Լ�, Myitoa�Լ� ������
//


//     �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
// #7. ���ڿ� Ƚ���� ������ ����� �� Ƚ����ŭ ���ϴ� ���α׷� �����
//     �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�

//main()
//{
//	int a;
//	int b;
//	int n;
//	int i;
//	char cc[10];
//
//	scanf("%d %d", &a,&n);
//	
//	for(i=0;i<n;i++)
//	{
//		
//		printf("%10d\n",a);
//		itoa(a,cc,10);
//		strrev(cc);
//		b= atoi(cc);
//		printf("+%9d\n",b);
//		puts("-----------");
//		a = a+b;
//
//		printf("%10d\n",a);
//		puts("");
//	}
//	
//
//
//

//  #8. ���������͸� ����Ͽ� a������ 500�� �����ÿ�.
//      ���Կ����� ���, scanf ������ε� �غ���.
//
//
//main()
//{
//	int a;
//	int *p;
//	int **k;
//	p= &a;
//	k= &p;
//
//	**k=500;
//	printf("a = %d\n",a);
//
//	scanf("%d",(*k));
//	printf("a = %d\n",a);
//
//
//
//
//}


//  #9. yz�� ����ϴ¹��
//      z�� ����ϴ� ���
//

//void func(char **k)
//{
//	printf("%s\n", *(k+1));
//	printf("%s\n", k[1]);
//	//
//	// ���⼭���� ���� Ǫ�°�  
//	// �ٵ� ȥ�� ��Ǯ���� �� �ٽ� Ǯ���!!!!!!!!!!!!!!!!!!!!!!!!!
//	//
//	printf("%s\n", *(k+0)+1);   // = k[0]+1 = &k[0][1] = &(*k)[1]
//	printf("%c\n", *(*(k+0)+2)); // =k[0][2] = (*k)[2] = *(k[0]+2)
//}
//
//main()
//{
//	char *p[3]={"xyz","bbbb","ccccc"};
//	func(p);
//	printf("%s\n", *(p+1));
//	printf("%s\n", p[1]);
//}


// #10.
//

void getNum(int (*pa)[3])
{
	int i,j;
	for(i=0;i<2;i++)
		for(j=0;j<3;j++)	scanf("%d",&pa[i][j]);   // *(p+i)+j �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
}

void putNum(int (*pa)[3])
{
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)	
		{
			printf("%d ",pa[i][j]); // *(*(p+i)+j)�ڡڡڡڡڡڡڡڡڡڡڡڡڤ�
		}
		puts("");
	}
}

int minNum(int (*pa)[3])
{
	int min = pa[0][0];
	int i, j;
	for(i=0;i<2;i++) 
		for(j=0;j<3;j++)
			if(min>pa[i][j]) min=pa[i][j];

	return min;
}
main()
{
	int a[2][3];
	int min;

	int (*pa)[3];
	pa=a;
	

	getNum(a);
	putNum(a);
	min = minNum(a);
	printf("�ּڰ� : %d\n",min);
	
}
