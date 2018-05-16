#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #5. 이분검색 구현해보기
//     by 일반함수 / 재귀함수 / bsearch()[라이브러리함수]
//

//typedef int arrnum sizeof(key)/sizeof(key[0])

int binarysearching (char (*p)[9],int start, int end,char *s)
{


	int mid; 
	mid = (start+end)/2;
	if(start>end) return -1;   // ★★★★★[검색결과가 없는 경우] 반드시 입력해야한다★★★★★★★★★★★

	if(strcmp(*(p+mid),s)==0) return mid+1;
	else if(strcmp(*(p+mid),s)>0) binarysearching(p,start,mid-1,s); // ★★★부등호 잘못쓰면 무조건 안나온다 [정렬되어있기때문]★★★
	else binarysearching(p,mid+1,end,s);
}

int binarysearching2 (char (*p)[9],int start, int end,char *s)
{
	int mid;

	while(start<=end)// ★★★★★[검색결과가 없는 경우] 반드시 입력해야한다★★★★★★★★★★★
	{
		mid = (start+end)/2;

		if(strcmp(p[mid],s)==0) return mid+1;

		else if (strcmp(p[mid],s)>0) // ★★★부등호 잘못쓰면 무조건 안나온다 [정렬되어있기때문]★★★
		{
			end = mid - 1;
		
		}

		else
		{
			start = mid+1;
		
		}
	}

	return -1;
}

main()
{
	
	char key[][9] = {"Alice", "Bill", "Carol", "David", "Elvis", "Fred", "Gabriel",
		"Helen", "Isabel", "Jane", "Kuper", "Louic", "Mathilda", "Nadia", "Olive",
		"Pablo", "Queen", "Rambo", "Scarlet", "Trisha", "Umberto", "Vincent", 
		"Wily", "Xxx", "Yuki", "Zorro"};
	int arrnum = sizeof(key)/sizeof(key[0]);
	int start=0;
	int location;
	char *s = "Pablo";
	char *ss = "Umberto";
	char *sss = "Queen";

	puts("재귀함수Ver");
	printf("%s는 %d번째에 있습니다.\n",s,binarysearching(key,0,arrnum-1,s));

	puts("일반함수Ver");
	printf("%s는 %d번째에 있습니다.\n",ss,binarysearching2(key,0,arrnum-1,ss));

	puts("라이브러리Ver");
	location = bsearch(sss,key,arrnum-1,sizeof(key[0]),strcmp);
	printf("%s는 %d번째에 있습니다.\n",sss,(location-(int)key)/sizeof(key[0])+1);

	

							// 존재하지 않으면 0 리턴, 존재하면 다른값 Return!!!
							// ★★★★과연 위치를 어떻게 찾을수 있을까?????????????★★★★
	

}
// #4. Tree 공부해보기 [전위순회, 중위순회, 후위순회]
//

//typedef struct _tree{
//	int key;
//	struct _tree *left;
//	struct _tree *right;
//}Tree;
//
//void pre_order(Tree *p)
//{
//	if(p!=NULL) 
//	{
//		printf("%d",p->key);
//		pre_order(p->left);
//		pre_order(p->right);
//	}
//
//}
//void in_order(Tree *p)
//{
//	if(p!=NULL) 
//	{
//		pre_order(p->left);
//		printf("%d",p->key);
//		pre_order(p->right);
//	}
//
//}
//void post_order(Tree *p)
//{
//	if(p!=NULL) 
//	{
//		pre_order(p->left);
//		pre_order(p->right);
//		printf("%d",p->key);
//	}
//
//}
//main()
//{
//	Tree a={1,NULL,NULL},
//		 b={2,NULL,NULL},
//		 c={3,NULL,NULL},
//		 d={4,NULL,NULL},
//		 e={5,NULL,NULL};
//
//	c.right = &d;
//	c.left=&a;
//	a.right=&b;
//	d.right = & e;    // c(a(0,b),d(0,e)) 모양의 Tree
//
//	pre_order(&c); // 3 1 2 4 5 출력
//	puts("");
//	in_order(&c);
//	puts("");
//	post_order(&c);
//  
//	}



// #3. Queue 공부해보기
//

//int Queue[5];
//int front, rear;   //포인터로 선언하지 않는 이유?  포인터가 아니라 단순한 Index기때문 ★★★
//
//void init_Queue(void)
//{
//	front = rear = 0;
//
//}
//
//void put(int data)
//{
//	
//	if((rear+1)%5 == front) {puts("OVERFLOW");	return;} // 이것도 rear+1==5가 아니라 (rear+1)%5★★★★★
//	//if(rear==4) rear = 0; // 일캐하면 앙된다★★★★★★
//	
//	//Queue[rear++]=data; // 넣고 증가 개념 유지
//
//	Queue[rear]=data;
//	rear = (rear+1) %5;
//	
//}
//
//int get(void)  // ★★★★★★★★★★★★★★★요거를 잘해야된다 [많이 헷깔림 & 집중안돼서 제대로 이해못함] ★★★★★★★★★★★★
//{
//	int save;
//	if(front==rear) 
//	{ 
//		puts("EMPTY");
//		return -999;
//	}
//	save = Queue[front];
//	front = (front+1)%5;
//	return save;
//}
//main()
//{
//	init_Queue();
//	put(3);
//	put(5);
//	put(1);
//	put(4);
//	put(2);		// Overflow
//	printf("%d\n",get());
//	printf("%d\n",get());
//	printf("%d\n",get());
//	printf("%d\n",get());
//	printf("%d\n",get());
//
//	put(1);
//	put(2);
//	put(3);
//	printf("%d\n",get());
//	
//	printf("%d\n",get());
//	printf("%d\n",get());
//	printf("%d\n",get());
//}



// #2. 가변인수 공부하기
//


////#include <stdarg.h>			 //★★★[헤더 반드시 추가]★★★ 아래께 강사님이 보내주신거 이게 stdarg.h에 포함되어있는 내용
//typedef char * vva_sist;
//#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
//
//#define va_start(ap,v)  ( ap = (vva_list)&v + _INTSIZEOF(v) )
//#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
//#define va_end(ap)      ( ap = (vva_list)0 )
//float average(int num,...) // ... 세개 아니면 무조건 오류 ★★★★★★★★★★★★★
//{                          // 이때의 ...이 가변 인자!!! (몇개던 이걸로 받겠다)★★★★★★★★★★★
//
//	vva_list arg_ptr;
//	int cnt,total=0;
//
//	va_start(arg_ptr,num);
//	
//	for(cnt=0;cnt<num;cnt++)
//		total += va_arg(arg_ptr,int);
//
//	va_end(arg_ptr);
//	return((float)total/num);
//}
//
//int main(void) {   // 리눅스에선 정확하게 이거 다 적어주자!!
//   float x;
//
//   x = average(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
//
//   printf("first avg is %f\n", x);
//
//   return 0;
//}

// #1. Stack 만들어보기
//


//#define STACK_SIZE 5
//int Stack[STACK_SIZE];
//int top;
//
//void init_Stack(void)
//{
//	top=-1;
//}
//
//void push(int data)
//{
//	if(top >= STACK_SIZE-1) {
//		puts("Overflow");
//		return;
//	}
//	Stack[++top] = data;
//}
//
//int pop(void)
//{
//	if(top < 0){
//		puts("Underflow");
//		return -99;
//	}
//	
//	return Stack[top--];
//
//}
//
//
//main()
//{
//	init_Stack();
//	push(3);
//	push(4);
//	push(1);
//	push(5);
//	push(2);
//	push(6);
//
//	printf("%d\n",pop());
//	printf("%d\n",pop());
//	printf("%d\n",pop());
//	printf("%d\n",pop());
//	printf("%d\n",pop());
//	printf("%d\n",pop());
//	
//	printf("%d\n",pop());
//}