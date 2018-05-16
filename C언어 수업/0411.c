#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #1.다음 2차원 배열에 scanf를 사용하여 값을 넣고
//	  모든 요소를 출력, 모든 요소의 합 출력, 그 중 가장 큰 요소 출력
//    모든 행의 합과 열의 합 출력. 

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



// #2. 포인터를 이용하여 변수 두개의 값을 서로 바꿔보자.
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


// #3. 포인터의 함수 호출을 이용하여 두개의 값을 서로 바꿔보자.
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


// #4. main함수에 있는 1차원 배열에 값을 넣는 함수
//    그 값을 출력하는 함수

// #5. putstring함수에서 a배열의 내용 중 'k'가 나오기 전까지 출력하기

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
//		if(b[i]!='k') printf("%c",b[i]);          // 조건문안에 if문이 있으면 좋지 못한 코딩*********
//		if (b[i]=='k') break;                     // for문의 조건안에 b[i]!=k로 합쳐버리자!!!
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


// #6. 문자열 함수 이용해보기
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

// [과제#1]
// strcpy, strlen, strcat 함수를 직접 만들어보시오.
//
// char *mystrcpy(char *dest, const char *src)
// size_t mystrlen(const char *s)
// char *mystrcat(char *dest, const char *src)
// Myatoi함수, Myitoa함수 만들어보기
//


//     ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
// #7. 숫자와 횟수를 넣으면 뒤집어서 그 횟수만큼 더하는 프로그램 만들기
//     ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★

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

//  #8. 더블포인터를 사용하여 a변수에 500을 넣으시오.
//      대입연산자 방식, scanf 사용으로도 해봐라.
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


//  #9. yz를 출력하는방법
//      z를 출력하는 방법
//

//void func(char **k)
//{
//	printf("%s\n", *(k+1));
//	printf("%s\n", k[1]);
//	//
//	// 여기서부터 내가 푸는거  
//	// 근데 혼자 못풀었다 꼭 다시 풀어보자!!!!!!!!!!!!!!!!!!!!!!!!!
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
		for(j=0;j<3;j++)	scanf("%d",&pa[i][j]);   // *(p+i)+j ★★★★★★★★★★★★★★★★★★
}

void putNum(int (*pa)[3])
{
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)	
		{
			printf("%d ",pa[i][j]); // *(*(p+i)+j)★★★★★★★★★★★★★ㅍ
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
	printf("최솟값 : %d\n",min);
	
}
