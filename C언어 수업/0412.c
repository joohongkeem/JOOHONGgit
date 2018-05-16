#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 가장 STANDARD한 방법 !!
// 이거 잘 이해하고 넘어가야한다 꼭꼭꼭!!!

////2차원 배열을 2차원 답게 접근
//void arr2d(int (*p)[3])
//{
//	p[0][1]=3;
//	*(*(p+1)+2)=9;
//
//}
//
//// 2차원 배열을 1차원답게 접근
//void arr1d (int *p)
//{
//	p[2]=5;
//}
//
//main()
//{
//	int a[2][3];
//	arr2d(a);
//	printf("%d\n", a[0][1]);
//	printf("%d\n", a[1][2]);
//	arr1d(a[0]);
//	printf("%d\n",a[0][2]);
//}


// #1. connect함수 완성하기
//
// 따블포인터 잘생각해서 다시해보기
// 나는 그냥 a를 가져와서 포인터 *p에 넣었다!!

//void connect(int **p,int *a)
//{
//	*p=a;
//}
//
//main()
//{
//	int a=77;
//	int *pp;
//
//	connect(&pp,&a);//이안엔 뭐가들어가야 할까?
//	printf("%d\n", *pp);  // 77출력
//}


// #2. 콘솔창 조작하기 ★★★★★★★
//
//int main(int argc, char **argv)
//{
//	int dx;
//	for(dx=0;dx<argc;dx++)
//	{
//		printf("%d : %s\n",dx,argv[dx]);
//	}
//	return 0;
//}
//
//

// [cmd 명령어]
// d: - d로 이동
// mkdir test : test라는 디렉토리 생성
// cddir test : test라는 디렉토리로 들어감
// dir : 현재 디렉토리에 들어있는거 확인
// echo >> a.txt - 내용에 "echo가 설정되어 있습니다"라는 a.txt파일 새엉
// copy a.txt b.txt : a.txt내용을 복사하여 b.txt생성
// cls : 깔끔히 지운다.

// 0 : c:\Users\bit-user\Documents\Visual Studio 2008\Projects\0412\Debug\0412.exe 출력
// 0번째는 자기자신이고, 0이출력된걸로 봐서 argc=1이겠구나
// Alt+F7 : 프로젝트 속성 - 구성 속성 - 디버깅  - 명령인자 - a.txt b.txt 입력하면 
// 0 : c:\Users\bit-user\Documents\Visual Studio 2008\Projects\0412\Debug\0412.exe
// 1 : a.txt
// 2 : b.txt
// 출력 
// Ctrl + O - 하나 위로 - debug - .exe파일 복사에서 test폴더 안에 넣자
// dir로 파일 이름 확인하고
// 앞에 몇개치고 Tap 누르면 자동으로 파일이름 입력 (한칸띄고) a.txt b.txt aaa bbbb cccc 입력
// 0 : 0412.exe
// 1 : a.txt
// 2 : b.txt
// 3 : aaa
// 4 : bbbbb
// 5 : cccc
// 출력
// 나중에 DB를 입력할때 많이 사용한다!!!

// F5 : 중단점으로 바로 간다
// F11 : 함수내용으로 들어가기
// F10 : 한줄씩 진행

// #3. Calculate.exe 만들어서 덧셈하기
//

//int main(int argc, char **argv)
//{
//	int dx;
//	int a,b,c;
//	a=atoi(argv[2]);
//	b=atoi(argv[4]);
//
//	switch(*argv[3]) // 또는 argv[4][0];
//	{
//	case '+': 
//		printf("%d + %d = %d\n", a, b, a+b);
//		break;
//	case '-':
//		printf("%d - %d = %d\n", a, b, a-b);
//		break;
//	case '*':
//		printf("%d * %d = %d\n", a, b, a*b);
//		break;
//	case '/':
//		printf("%d / %d = %d\n", a, b, a/b);
//		break;
//	case '%':
//		printf("%", a, b, a%b);
//		break;
//	default: ;
//	}
//
//
//	for(dx=0;dx<argc;dx++)
//	{
//		printf("%d : %s\n",dx,argv[dx]);
//	}
//
//	
//
//	return 0;
//}

// 실행할땐 cmd에서 0412.exe cal 9 - 6 이런식으로 입력          




// #4. 함수 포인터 공부하기
// 

//
//int add(int a, int b){return a+b;}
//int sub(int a, int b){return a-b;}
//int mul(int a, int b){return a*b;}
//int dvd(int a, int b){return a/b;}
//
//typedef unsigned int uint;
//typedef int(*p)(int,int) mypf; // 이러면 에러방생!!!
//typedef int(*mypf)(int,int); // 이렇게 설정해야한다.★★★★★
//typedef int *mysingleP; // main문에서는 mysingleP dp;로 하면 int* dp와 같다 ★★★★★
//typedef int arr[3]; // main문에서는 arr b; 하면 int b[3]과 같아진다 ★★★★★
//main()
//{
//	//int (*p)(int, int);
//	//mypf p; 로도 사용이 가능하다
//	//p = add;
//	//printf("%d\n",p(9,2));
//
//	//p = sub;
//	//printf("%d\n",p(9,2));
//
//	//p = mul;
//	//printf("%d\n",p(9,2));
//
//	//p = dvd;
//	//printf("%d\n",p(9,2));
//
//	// 반복문을 사용하면 되겠다. 그걸 위해선 함수 포인터 배열을 만들어줘야 한다.
//	int (*fp[4])(int, int) = {add,sub,mul,dvd};
//	mypf[4] = {add,sub,mul,dve}; // 이렇게 표시하면 훨씬 간단하게 표현가능 ★★★★★
//	int i;
//
//	for(i=0;i<4;i++)
//		printf("%d\n",fp[i](9,3));  // fp[i](9,3) 을 *(fp+i)(9,3)으로 하면 안된다
//								    //              (*(fp+i))(9,3)
//	
//
//}



// #5. 함수포인터와 매개변수
//

//int add(int a,int b){return a+b;}
//int sub(int a,int b){return a-b;}
//int temp1(int(*p_func)(int , int ),int a, int b){
//	return (p_func)(a,b);
//}
//int temp2(int(**p_func)(int , int ),int a, int b){
//	return (*p_func)(a,b);
//}
//
//main()
//{
//	int a=10, b=5;
//	int (*p)(int,int);
//
//	printf("%d \n",temp1(add,a,b));
//	printf("%d \n",temp1(sub,a,b));
//
//	p=add;
//	printf("%d \n",temp1(p,a,b));
//	p=sub;
//	printf("%d \n",temp1(p,a,b));
//
//	p=add;
//	printf("%d \n",temp2(&p,a,b));
//	p=sub;
//	printf("%d \n",temp2(&p,a,b));
//  }
	// 함수 포인터 배열을 만들어서 
	// 반복문으로 한번 더 해보기!!



// #6. 캐스팅 연산자 넣어보기
//

//main()
//{
//
//	char a='A';
//	int b;
//	float c;
//	double d;
//
//	d=(double)(c=(float)(b=(int)a));  //괄호를 정확하게 넣지 않으면 컴파일되지 않는다.★★★
//	puts("");
//}



// #7. 5x2의 2차원 배열의 1열엔 함수의 주소값, 2열엔 문자열을 저장했다면
//     (★★그렇다면 5x2 배열은 사실 "5x2짜리 범용 포인터 배열!!)
//     두 수 10과 5에 대하여 사칙연산을 수행하는 계산기를 구현해보자!!

//int add(int a, int b){return a+b;}
//int sub(int a, int b){return a-b;}
//int mul(int a, int b){return a*b;}
//int dvd(int a, int b){return a/b;}
//
//main()
//{
//	int (*fp[4])(int,int) = {add,sub,mul,dvd};
//	char (*sp[4])[15] = {"Addition","Subtraction","Multiply","Divide"};
//	void* arr[5][2] = {
//		{fp[0],sp[0]},
//		{fp[1],sp[1]},
//		{fp[2],sp[2]},
//		{fp[3],sp[3]},
//	};
//
//	int whattodo;
//	int i,n;
//	puts("계산기 프로그램");
//	for(i=1;i<=4;i++)
//	{
//		printf("%d. %s\n",i,(char*)arr[i-1][1]);	
//	}
//	printf("번호를 선택하세요 : ");
//	scanf("%d",&n);
//	
//	printf("결과값 : %d \n", ((int (*)(int,int))arr[n-1][0])(10,5));
//
//
//
//}

// 강사님 풀이 ★★★★★★★★★★

//main()
//{
//
//	void *p[5][2] = {add,"addition",sub,"subtraction",mul,"multiply",dvd,"divide",0,0};
//	int dx = 0, sel ;
//
//	while(p[dx][0]!=NULL)
//	{
//		printf("%d. %s\n", dx+1, (char*)p[dx][1]);
//		dx++;
//	}
//	scanf("%d", &sel);
//
//	printf("결과값 : %d \n", ((int (*)(int,int))p[sel-1][0])(10,5));
//}

//★★★★★★★★★★★★★★★★★★★★★★★★
//값을 넣을때 괄호에 굉장희 주의해야한다
//    ((int (*) (int,int))p[sel-1][0])(값1,값2));
// 괄호 하나라도 빠지면 무저꿘 오류난다!!!!!!!!!!!!!!!!!!!!!!!!!!!
//★★★★★★★★★★★★★★★★★★★★★★★
// int형 형변환하는 방식 잘 익혀두자.
//★★★★★★★★★★★★★★★★★★★★★★★★

// #8-1. 전처리기 이해하기
//


//#define FLAG
//
//void fn1(void)
//{
//	extern int a;
//	printf("또잉%d\n",a);
//}
//extern int a=100;
//main()
//{
//#ifdef FLAGa 
//	printf("Defined");
//#else 
//	printf("NoDefined");
//#endif
//	fn1();
//}


// #8-2. 전처리기 이해하기
//

//void func1(void){ puts("func1");}
//void func2(void){ puts("func2");}
//void func3(void){ puts("func3");}
//void func4(void){ puts("func4");}
//
//#define call(x) func##x
//
//main()
//{
//	int dx;
//	for(dx=1;dx<5;dx++) call(dx)(); // 에러가 발생하는 이유?
//								    // 이럴땐 f4눌러서 파악하자
//									// funcdx가 정의되지 않았습니다!!??
//									// 컴파일 되기전에 call(dx)가 funcdx가 되버렸단것 !
//									// 전처리가 엄청 빨리 진행됐다.
//									// void funcdx(void) {puts("funcdx");} 라는 함수를 만들어놨으면 이것만 4번 호출
//}




// #9.
// #define square(x)  ????
// //25/square(5) = 1  이 되도록 square 매크로 작성
//
// #define PR(x) ????
// //PR(x)    x값을 출력하는 PR 매크로 함수 작성
//
// #define ABS(x) ????
// //절대값   을 출력해주는 매크로 작성
//
// #define THREE_MAX(a,b,c)  ?????
// //최대값 (three_max)   3개의 값중 가장 큰 값을 출력하는 매크로 작성
//
// #define SWAP(x,y) ?????

#define SQUARE(x) x*x
#define PR(x) printf("%d\n",x)
#define ABS(x) (x>=0)?x:-x
#define THREE_MAX(a,b,c) (((a>=b)?a:b) >= c ? ((a>=b)?a:b) : c)
#define SWAP(x,y) {x=x^y; y=x^y; x=x^y;}
#define FLAG 0

main()
{
	int a = 90, b = 60;
	int sq=20;

	PR(SQUARE(5));
	PR(ABS((-99)));				// -99갚에 괄호 안넣으면 연산자로 인식되기 때문에 오류발생
	PR(THREE_MAX(-30,90,60));
	//SWAP(a,b);					// SWAP을 define할때 {}안에서 만들지 않으면 선언문의 위치문제로 에러발생 !! 
									// 해결책은 define안에 {}를 넣는방법
	
	if(sq>0) SWAP(a,b);
	
	else SWAP(a,sq);	// 강사님 특별숙제★★★★★★★ 왜 에러가발생하는가?

	printf("%d %d\n",a,b);
}