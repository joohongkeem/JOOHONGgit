#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #5. �̺а˻� �����غ���
//     by �Ϲ��Լ� / ����Լ� / bsearch()[���̺귯���Լ�]
//

//typedef int arrnum sizeof(key)/sizeof(key[0])

int binarysearching (char (*p)[9],int start, int end,char *s)
{


	int mid; 
	mid = (start+end)/2;
	if(start>end) return -1;   // �ڡڡڡڡ�[�˻������ ���� ���] �ݵ�� �Է��ؾ��Ѵ١ڡڡڡڡڡڡڡڡڡڡ�

	if(strcmp(*(p+mid),s)==0) return mid+1;
	else if(strcmp(*(p+mid),s)>0) binarysearching(p,start,mid-1,s); // �ڡڡںε�ȣ �߸����� ������ �ȳ��´� [���ĵǾ��ֱ⶧��]�ڡڡ�
	else binarysearching(p,mid+1,end,s);
}

int binarysearching2 (char (*p)[9],int start, int end,char *s)
{
	int mid;

	while(start<=end)// �ڡڡڡڡ�[�˻������ ���� ���] �ݵ�� �Է��ؾ��Ѵ١ڡڡڡڡڡڡڡڡڡڡ�
	{
		mid = (start+end)/2;

		if(strcmp(p[mid],s)==0) return mid+1;

		else if (strcmp(p[mid],s)>0) // �ڡڡںε�ȣ �߸����� ������ �ȳ��´� [���ĵǾ��ֱ⶧��]�ڡڡ�
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

	puts("����Լ�Ver");
	printf("%s�� %d��°�� �ֽ��ϴ�.\n",s,binarysearching(key,0,arrnum-1,s));

	puts("�Ϲ��Լ�Ver");
	printf("%s�� %d��°�� �ֽ��ϴ�.\n",ss,binarysearching2(key,0,arrnum-1,ss));

	puts("���̺귯��Ver");
	location = bsearch(sss,key,arrnum-1,sizeof(key[0]),strcmp);
	printf("%s�� %d��°�� �ֽ��ϴ�.\n",sss,(location-(int)key)/sizeof(key[0])+1);

	

							// �������� ������ 0 ����, �����ϸ� �ٸ��� Return!!!
							// �ڡڡڡڰ��� ��ġ�� ��� ã���� ������?????????????�ڡڡڡ�
	

}
// #4. Tree �����غ��� [������ȸ, ������ȸ, ������ȸ]
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
//	d.right = & e;    // c(a(0,b),d(0,e)) ����� Tree
//
//	pre_order(&c); // 3 1 2 4 5 ���
//	puts("");
//	in_order(&c);
//	puts("");
//	post_order(&c);
//  
//	}



// #3. Queue �����غ���
//

//int Queue[5];
//int front, rear;   //�����ͷ� �������� �ʴ� ����?  �����Ͱ� �ƴ϶� �ܼ��� Index�⶧�� �ڡڡ�
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
//	if((rear+1)%5 == front) {puts("OVERFLOW");	return;} // �̰͵� rear+1==5�� �ƴ϶� (rear+1)%5�ڡڡڡڡ�
//	//if(rear==4) rear = 0; // ��ĳ�ϸ� �ӵȴ١ڡڡڡڡڡ�
//	
//	//Queue[rear++]=data; // �ְ� ���� ���� ����
//
//	Queue[rear]=data;
//	rear = (rear+1) %5;
//	
//}
//
//int get(void)  // �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڿ�Ÿ� ���ؾߵȴ� [���� ��� & ���߾ȵż� ����� ���ظ���] �ڡڡڡڡڡڡڡڡڡڡڡ�
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



// #2. �����μ� �����ϱ�
//


////#include <stdarg.h>			 //�ڡڡ�[��� �ݵ�� �߰�]�ڡڡ� �Ʒ��� ������� �����ֽŰ� �̰� stdarg.h�� ���ԵǾ��ִ� ����
//typedef char * vva_sist;
//#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
//
//#define va_start(ap,v)  ( ap = (vva_list)&v + _INTSIZEOF(v) )
//#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
//#define va_end(ap)      ( ap = (vva_list)0 )
//float average(int num,...) // ... ���� �ƴϸ� ������ ���� �ڡڡڡڡڡڡڡڡڡڡڡڡ�
//{                          // �̶��� ...�� ���� ����!!! (��� �̰ɷ� �ްڴ�)�ڡڡڡڡڡڡڡڡڡڡ�
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
//int main(void) {   // ���������� ��Ȯ�ϰ� �̰� �� ��������!!
//   float x;
//
//   x = average(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
//
//   printf("first avg is %f\n", x);
//
//   return 0;
//}

// #1. Stack ������
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