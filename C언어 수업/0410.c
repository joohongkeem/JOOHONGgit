
// compile : ctrl + F7
// linking : F7

// execute(compile) : ctrl + F5

// #include <stdio.h> // 표준 입력출력.헤더

// ctrl+k+c = 주석 만들기
// ctrl+k+u = 주석 없애기

//main() // 반드시 main 이어야함
//{
//	printf("홍길동"); // 표준출력 함수
//	printf("홍길동\n"); // newline
//	puts("홍길동");
//
//	//정수, 실수, 문자, 문자열
//	// 12   3.5  'A'   "A"
//	//           [A]  [A][\0]
//
//	// 정수 : char short int long  --> 데이터 형(Type)
//	//         1    2    4    4
//}



#define _CRT_SECURE_NO_WARNINGS // 전처리기 : _s가 있는것으로 자동 매핑
#pragma warning(disable:4996) // 경고를 못하게 만듬
// #include 위에 쓰는게 맞다 *전처리기는 순서가 가장 중요*
#include <stdio.h>

//main()
//{
	//int a=0x12345678;
	//printf("%d %o %x\n",a,a,a);
	//100(78) 101(56)....
	//Little Endian 방식

	//float b=12.5f;
	//4열방식 기준으로 00 00 48 41 cc cc cc cc 출력
	//이것도 마찬가지로 Little Endian방식?
	//[00000000 00000000 01001000 01000001] 11111111 11111111 11111111 11111111
	//#1. 왜 32비트 뒤에 모두 1?
	// >> 그냥 쓰레기값인데 값이 1111인거다.

	//#2. 왜 01001000 01000001 00000000 00000000이 아니지?
	// >> 원래 변환한 숫자가 01000001 01001000 00000000 00000000이였으므로
	//    그걸 Little Endian으로 하면[00000000 00000000 01001000 01000001]가 맞다.

	//#3. 뒤에 f붙인거 뭐더라....
	// >> float형으로 변환, 원래는 double b = 12.5f방식으로 사용하면 float형이 된다. 
//}

// F7-F10 조사식 오른쪽위, 메모리 오른쪽 아래 끌고
// 조사식에 &a입력 (a의 주소)
// 한단계씩 넘어갈때는 F10누르기
// 그리고 조사식 &a의 값을 메모리에 끌어다 놓으며면 &a의 값이 가장 위에 나온다.
// (열 4로 하면 보기 쉬움)
// 나가려면 Shift F5

// 근데 왜 12345678이 아니라 78 56 34 12 가 들어갔을까?
// 0x12345678 에서 78이라는 Low Data가 &a의 Low Address로 들어간다.
// 같은말로 High Data가 High Address로 들어간다
// 즉, Byte order가 little endian ! (반댓말은 big endian), cpu마다 다르지만 보통 little endian

// 32bit data 12345678을 64bit data에 넣으려면
// 0000000012345678으로 넣는게 정상일꺼 같지만
// 78 56 34 12 00 00 00 00 으로 들어가는게 맞다
// 그래야지 주소번지가 안바뀌니깐 좋다
// Little Endian의 최고장점은 주소번지를 바꾸지 않고 0만 채우면 되는데
// Big Endian은 12345678을 뒤로 쭉밀어서 앞에를 0으로 채워야된다 (뭐가 더 빠르단건 X)

// 정수, 실수 등 데이터 타입을 나눈 것은 데이터를 표현하는 방식이 모두 다르기 때문!



//main()
//{
//
//	int a=10; // 정수를 담는 메모리 a를 선언 (10:초기화)
//	printf("%d\n",a); // 10
//	a=123;
//	printf("%d\n",a); // 123
//
//	scanf("%d",&a);
//	printf("%d\n",a);
//
//	printf("123\n"); 
//	printf("%s\n","123");
//	printf("%d\n",123);
//	printf("%c%c%c\n",'1','2','3');
//	// 결과는 모두 똑같지만 사실 내부적으로 차이가 있다.
//}




//main() // exclusive or를 사용하여 두 수를 바꿔보자.
//{
//	int a=10, b= 11;
//	int t;
//
//	printf("%d %d\n",a,b);
//	
//	a=a^b;
//	b=a^b;
//	a=a^b;
//
//
//	printf("%d %d\n",a,b);
//
//	t=a;
//	a=b;
//	b=t;
//
//	printf("%d %d\n",a,b);
//
//	
//}


////함수 만들어보기

//int add(int a, int b)
//{
//	return a+b;
//}

//int getNum()
//{
//	int a;
//	scanf("%d",&a);
//	return a;
//}
//
//int maxNum(int a,int b)
//{
//	return a>=b ? a : b;
//}
//
//void putNum(int a)
//{
//	printf("%d\n",a);
//}
//
//main()
//{
//
//	//int a=10, b=20;
//	//int rlt;
//	//rlt = add(a,b); // rlt = a + b;
//	//printf("%d\n",rlt);
//
//
//	int a, b, max;
//	
//	a = getNum();
//	b = getNum();
//	max = maxNum(a,b);
//	putNum(max);
//
//}



// 입력된 문자가 대문자이면 "대문자"출력, 소문자라면 "소문자"출력
// 대문자면 소문자로 출력, 소문자면 대문자로 출력

//main()
//{
//
//	char a;
//	//A : 65 = 0100 0001, Z : 90  
//	//a : 97 = 0110 0001, z : 122
//
//	scanf("%c",&a);
//	if(65<=a && a<=90) 
//	{
//		printf("대문자입니다.\n");
//		printf("소문자로 변환시 %c입니다.\n",a+32);
//		
//	}
//	else if(97<=a && a<=122)
//	{
//		printf("소문자입니다.\n");
//		printf("대문자로 변환시 %c입니다.\n",a-'a'+'A'); // 이렇게 하는 방식도 있다
//
//	}
//	else
//		printf("알파벳이 아닙니다.\n");
//
//	printf("%c\n",'G'^0x20);    // ^0x20을 하면 대문자는 소문자로, 소문자는 대문자로 바뀐다!! [훨씬 좋은 방법]
//								//  0100 0001 (65)
//								// ^0010 0000 (0x20)
//								// =0110 0001 (97)
//								//  
//								//  0110 0001 (97)
//								// ^0010 0000 (0x20)
//								// =0100 0001 (65)
//
//	printf("%c\n", 'b'^(1<<5)); // 이방법이 나중에 진짜 많이 쓰인다!! (1<<5) 비트연산자 활용!! 1을 왼쪽으로 5칸 shift
//}


// Switch case문을 이용한 점수대별 학점 출력
// 드래그하고 Alt+F8 : 자동 들여쓰기
//main()
//{
//
//	int a;
//	scanf("%d",&a);
//	a = a/10;
//	switch(a)
//	{
//	case 10 : // case문은 break를 만나지 않으면 무조건 다음껄로 넘어가기 때문에 
//			  // 이렇게 코딩해놓으면 100점일때도 9로 넘어간다.
//
//	case 9 :
//		printf("A학점입니다.\n");
//		break;
//
//	case 8 :
//		printf("B학점입니다.\n");
//		break;
//
//	case 7 :
//		printf("C학점입니다.\n");
//		break;
//
//	default:
//		printf("F학점입니다.\n");
//
//
//
//
//	}
//
//}




// while문을 사용하여 각종 문제 해결해보기

//main()
//{
//	int a=0;
//	int b;
//	int sum = 0;
//	int max,min;
//	int i;
//
//	while(a!=100)   // while문을 사용하여 0~99까지 출력 
//	{
//		printf("%d ",a);
//		a++;
//	}
//
//	puts("");
//	puts("");
//
//	a=1;
//	while(a<101)   // while문을 사용하여 1~100까지 출력 
//	{
//		printf("%d ",a);
//		a++;
//	}
//
//	puts("");
//	puts("");
//
//	a=100;
//	while(a>0)   // while문을 사용하여 100~1까지 출력 
//	{
//		printf("%d ",a);
//		a--;
//	}
//
//	puts("");
//	puts("");
//
//	a=1;
//	while(a<100)   // while문을 사용하여 0~99까지 홀수만 출력 
//	{
//		printf("%d ",a);
//		a = a+2;
//	}
//
//	puts("");
//	puts("");
//
//	a=0;
//	while(a<101)   // while문을 사용하여 0~100까지 짝수의 합 출력 
//	{
//		sum += a;
//		a = a+2;
//	}
//	printf("%d ",sum);
//
//	puts("");
//	puts("");
//
//
//	scanf("%d %d", &a,&b);
//	max = (a>=b)? a : b;
//	min = (a>=b)? b : a;
//	i = max;
//	while(min<=max) // while문을 사용하여 큰수에서부터 작은수까지 모든 숫자 출력
//	{
//		printf("%d ",i--);
//		min ++;
//	}
//
//	puts("");
//	puts("");
//
//	a = 0;
//	while(a<100) //while문을 사용하여 0~99까지 8의 배수만 출력
//	{
//		if(a%8==0) printf("%d ",a);
//		a++;
//	}
//
//	puts("");
//	puts("");
//
//	a = 0;
//	while(a<100) //while문을 사용하여 0~99까지 8의 배수와 9의 배수만 출력
//	{
//		if(a%8==0 || a%9==0) printf("%d ",a);
//		a++;
//	}
//
//	puts("");
//	puts("");
//	//반복문을 사용하여 입력되는 수가 100,500,1000일 경우에만
//	//값이 누적되게 하시오, 0을 입력하면 반복문을 break 시켜 탈출하시오.
//	sum = 0;
//	while(1)
//	{
//		scanf("%d",&a);
//		if(a==100||a==500||a==1000)
//		{
//			sum+=a;    // (100==N || 500==N) 과 (100!=N && 500!=N)
//			printf("누적된 값은 %d입니다\n",sum);
//		}
//		else if (a==0) break;
//	}
//	
//	
//
//
//}



// goto 문을 사용하여 1~10까지 합을 출력하라 [강사님 추천문제]

//main()
//{
//	int a=0;
//	int sum=0;
////AAA:
////	a++;
////	sum+=a;
////	
////	if(a==10) goto BBB;
////	goto AAA;
////
////BBB:
////	printf("%d\n",sum);
//	
//AAA:
//	a++;
//	sum+=a;
//	
//	if(a<=9) goto AAA;
//
//	printf("%d\n",sum);
//	
//
//}



// 총 복습 연습문제
// 비밀번호가 1234입니다.
// 입력을 받아서 1234 이면 "통과" 입력
// 틀린번호 입력하면 3번의 기회를 차감하며 보여주다가
// 마지막까지 틀리면 "경찰"출력

//main()
//{
//	int ans = 1234;
//	int input;
//	int i;
//	int trial = 4;
//	while(trial > 0)
//	{
//		scanf("%d",&input);
//		if(input==ans) 
//		{
//			puts("통과");
//			break;
//		}
//		else
//		{
//			if(trial>1) printf("%d의 기회가 남았습니다.다시 입력하세요",trial);
//			trial--;
//			if(trial==0) puts("경찰");
//		}
//	}
//}

// 위의 문제 강사님 풀이 [함수를 채워보자]
//
//int get_passwd(void)
//{
//	int a;
//	scanf("%d",&a);
//	return a;
//};
//void chance(int cnt)
//{
//	if(cnt==0) ;
//	else printf("%d번의 기회가 남았습니다.\n    다시 입력하세요.\n",cnt);
//};
//int compare(int a, int b)
//{
//	if(a==b) return 1;
//	else return 0;
//}
//;
//void police(int cnt)
//{
//	if(cnt==0) puts("경찰");
//};
//
//main()
//{
//
//  int pwd = 1234;//기존에 정해둔 패스워드
//  int get_pwd; //받을 패스워드
//  int cnt=3; //기회는 3번 뿐
//  do{
//    get_pwd = get_passwd();//패스워드 받아 옴
//
//    if(compare(pwd, get_pwd)) //두변수 같은지 같으면 1 다르면 0을 리턴한다.
//    { 
//      puts("통과");
//      break;
//    }else{
//   chance(--cnt); //기회를 보여주는 함수
//    }
//  }while(cnt); //cnt!=0
//
//  police(cnt); //경찰을 부르는 함수 cnt가 0이면 결찰을 부르는 함수
//
//}




// a배열 내부의 값중 가장 큰 값인 5를 max에 담아 출력하시오
//main()
//{
//	int a[] = {3,4,1,5,2};
//	int max=a[0];
//	int i;
//	for(i=1;i<5;i++)
//	{
//		if(a[i]>=max) max = a[i];
//	}
//	printf("최댓값은 %d입니다.\n",max);
//}




// int형 100개짜리 배열을 만들고 1부터 시작되는 홀수만 넣으시오.
// 내부의 값이 21이 나오기 전까지만 출력 (즉, 21은 출력X)

main()
{
	int a[100];
	int num=1;
	int i;
	//for(i=0;i<100;i++)
	//{
	//	a[i]=num;
	//	num += 2;
	//	if(a[i]<21) printf("%d ",a[i]);
	//}

	// 위에방식은 for문안에 조건문이 있으므로 그것을 없애보자

	for(i=0;num!=21;i++)
	{
		a[i] = num;
		num += 2;
		printf("%d ", a[i]);
	}

	// 조건문이 하나 적으므로 이게 속도가 더 빠르다
	puts("");
}