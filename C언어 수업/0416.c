#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

// #7. MovetoFront, TransposeMethod ������
//
// ȭ�� ����� system("cls");
// ���ð� : sleep(1000); >>> 1�ʴ�� (#include <windows.h>)
//

struct _node{
	int data;
	struct _node* next; //_node* next�� �ƴ϶� _node *next�̴١ڡڡڡ�
};
typedef struct _node Node;
Node *head, *tail;   //Node* head�� �ƴ϶� Node *head�̴�.�ڡڡڡڡ�

void initialize(void)
{
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	tail->next = tail;
}
int checkingFull(void) // �����߸��Ƴ� �ѹ� �غ���!!!
{
	int count = 0;
	Node *nw;
	nw=head->next;
	while(nw!=tail)
	{
		count ++;
		nw = nw->next;
	}
	printf("count�� ���� %d\n", count);
	return count;
}

Node* finding(int num)
{
	//���� ������ 1, ���� ������ 0 return
	Node *prend, *nextnd;
	prend = head;
	nextnd = head->next;
	while(nextnd!=tail && nextnd->data != num)
	{
		prend = prend->next;
		nextnd = prend->next;
	}

	if(nextnd!=tail) // nextnd->data �� ���� ���� num�� ����?!
		return prend;
	
	else return NULL;
}

void insertlist(int data)
{
	Node *prend, *nextnd, *newnd;

	prend = head;
	nextnd = prend->next;

	while(nextnd!=tail && data > nextnd->data)
	{
		if(nextnd->data == data) return;
		prend = prend->next;
		nextnd = prend->next;
	}

	newnd = (Node*) malloc(sizeof(Node));
	newnd->data = data;
	newnd->next = nextnd;
	prend->next = newnd;
}

void showlist(void)
{
	Node *pt;
	pt = head->next;

	printf("\n��� : ");
	while(pt!=tail)
	{
		printf("%d ", pt->data);
		pt = pt->next;
	}
	puts("");
}
// MovetoFront, TransposeMethod�Լ� �����
void MovetoFront(int Rnum)
{
	Node *prend, *findnd;

	if(finding(Rnum)==NULL) puts("�������� �ʴ� �������Դϴ�.");
	else{
	prend = finding(Rnum);
	findnd = prend->next;
	
	prend->next = findnd->next;
	findnd->next = head->next;
	head->next = findnd;
		
	}
	return;
}

void TransposeMethod(int Rnum)
{
	Node *tmp, *prend, *findnd;

	if(finding(Rnum)==NULL) puts("�������� �ʴ� �������Դϴ�.");
	else if(finding(Rnum)==head) puts("�̹� �� �� �������Դϴ�.");
	else
	{
		tmp = finding(finding(Rnum)->data);
		prend = finding(Rnum);
		findnd = prend->next;

		prend->next = findnd->next;
		findnd->next = prend;
		tmp->next = findnd;
	}
}
main()
{
	int Rnum;
	int count = 0;
	initialize(); // ����Ʈ �ʱ�ȭ
	srand(time(NULL));
	while(count!=10/*checkingFull()!=10*/) // �̰� ���� �߸��Ƴ� �ѹ� ���ĺ��� >>> checkingFull()�� �ؾߵǴµ� checkingFull���ϸ� XXXXXXXXXXXX  �ڡڡڡڡڡ�
	{	
		system("cls");
		Rnum = rand()%10+1;
		printf("%d\n", Rnum);
		if(finding(Rnum)==NULL) {insertlist(Rnum); count++;}
		showlist();
		Sleep(200);
	}
	puts("�ϼ��Ǿ����ϴ�");
	puts("");
	while(Rnum!=0){
		printf("�� �������� �Űܾ� �ϴ� ������ �Է��Ͻÿ�(0: ���� ) : ");
	scanf("%d",&Rnum);
	MovetoFront(Rnum);
	showlist();
	}
	Rnum=-1;
	while(Rnum!=0){
	printf("�ճ��� �ٲ�� �ϴ� ������ �Է��Ͻÿ�(0: ���� ) : ");
	scanf("%d",&Rnum);
	TransposeMethod(Rnum);
	showlist();
	}
}





// #6. List �⺻ ���� ������
//

//struct _node{
//	int key;
//	struct _node *next;
//};
//typedef struct _node Node;
//Node *head, *tail; // �� �� �������
//
//// ��� �ڷᱸ���� �ʱ�ȭ�� �ִ�.
//void init_Node(void)
//{
//	head = (Node*) malloc(sizeof(Node));  // ���� ��չ���
//	tail = (Node*) malloc(sizeof(Node));  // ���� ��չ���
//	head->next = tail; // ������ ����
//	tail->next = tail; // ���� �������� ��տ� ����� 
//}
//
//
//void insert_Node(int data)
//{
//	Node *nw = (Node*)malloc (sizeof(Node));
//	nw->key = data;
//	nw->next = head -> next;
//	head -> next = nw;
//}
//
//
//Node* find_Node(int data)
//{
//	Node *link, *find;
//	link = head;
//	find = link->next;
//
//	while(find->key != data && find!=tail) // ã�������� �ʹ� ����Ƿ� �ڷ� else�� ���� ��ã���� ��츦 ���� : �ڷ� ��ĭ�� ����.
//	{									   // Or find�� tail�� ������ �� ����������. [���� ||�� �ߴµ� ������ &&�̴١ڡڡڡڡڡڡڡ�]
//		link = link->next;
//		find = find->next; // find = link->next; �� ���°� �� ����. (���� �ڷ� ��ĭ�� �̶� �ǹ�)
//	}
////	else // ã���� ���, but ���� while�� �����Ƿ� else ���ص��ȴ�
////	{
//		// link->next = find->next; �̰Ŵ� ��ũ�� �����ϴ� ���� 
////	}
//
//	if(find!=tail)	// ���� find�� ������� �ƴ϶�� ���������� ã�����̴�!!
//		puts("ã�Ҵ�");
//	else puts("��ã�Ҵ�"); // find�� ������̶�� �����͸� ã�� ���� ���̴�.
//
//	return link; // ���� ���� ã������ find���� �� ���ּ��� link�� return�ϴ°��� �ξ� ���� �ڡڡڡڡڡڡڡڡڡڡڡڡڡ�
//				 // �̰��� �̿��ؼ� find�� �����غ���.
//}
//
//void deleting(Node * nd)
//{
//	Node *kill = nd -> next;
//	nd -> next = kill -> next; // nd->next = nd->next->next;
//	free(kill);
//	
//}
//
//void view_Node(void) // head�� tail�� ������ ������ ����
//{
//	//printf("[%d]\n",head->next->key);
//	//printf("[%d]\n",head->next->next->key);  // next�� �������ľ��ؼ� ������
//	
//	Node *wk = head->next; // ù��° ��� �ּҸ� wk���� �ش�
//	//printf("[%d]\n", wk->key);
//	//wk = wk->next;
//	//printf("[%d]\n", wk->key); // �ݺ��ǹǷ� �ݺ����� ����ϸ�
//
//	while(wk!=tail) // ������� ������  ������� ���ÿ� �ڡڡ�[wk!=tail]�ڡڡ�
//	{
//		printf("[%d]\n",wk->key);
//		wk=wk->next;
//	}
//
//}
//
//void ordered_insert_Node(int data)  // �����Ͽ� �����ϱ� 	�ڡڡ�
//{
//	Node* prevnd;
//	Node* nextnd;
//	Node* newnd;
//
//	prevnd=head;
//	nextnd = prevnd->next;
//
//	while(nextnd!=tail && data < nextnd->key) // data�� ���� ��庸�� ������ ���� X == data�� ���� ��庸�� ũ�ų� ������ ����!!
//											  //                                           ��, �������� ����!!
//	{
//		prevnd = prevnd->next;
//		nextnd = prevnd->next;
//	}
//		newnd = (Node*) malloc(sizeof(Node));
//		newnd->key = data;
//		newnd->next = nextnd;
//		prevnd->next = newnd;
//}
//
//void Movetofront(Node* nd) // ã�� ��带 �� ������ ������ [�������� �ֱ��۾�]
//{
//}
//
//void transposeMethod(Node* nd) // ã�� ��带 ������ ��ĭ ������
//{
//}
//
//void FrequencyCount(Node* nd) // � ��带 ��� ã�ҳĸ� ī��Ʈ�Ͽ� �� ���� �������� �����ϱ�
//{
//}
//main()
//{
//	Node *temp;
//
//	init_Node(); // Linked List�� �ʱ�ȭ
//
//
//	ordered_insert_Node(4);
//	ordered_insert_Node(1);
//	ordered_insert_Node(7);
//	ordered_insert_Node(13);
//	ordered_insert_Node(5);
//	ordered_insert_Node(6);
//
//	view_Node();
//
//	//insert_Node(3); // ù��° ����
//	//insert_Node(2); // �ι�° ����
//
//	//view_Node(); // ���� �߰ɷȳ� Ȯ���ϱ�
//
//	//find_Node(3);
//	//find_Node(4);
//
//	//temp = find_Node(2);
//	//if(temp->next!=tail) deleting(temp); // �Ѱ��� ����� �޳�带 �����ϴ� �Լ�
//
//	//view_Node();
//
//}


// #5. �� ������ ���� ���ÿ� �ξ��ٰ� ������ ����ϴ� ����Լ� ����
//     �ڡڡڡڡڡڡڡ�[�������̴µ� ��û ��ƴ�]�ڡڡڡڡڡڡڡڡڡ�
//

//void backprint(void)  // [�����غ���] ���� �ѱ��� �̷��� backprint�Ϸ��� ��ؾ��ұ�?
//{
//	char c;
//	if((c=getchar()) != '\n') backprint();
//	putchar(c);
//}
//
//main()
//{
//	backprint();
//}


// #4[����]. 1) �ҹ��ڸ� �Է¹޾� �� ���ں��� 'z'���� ����ϴ� ����Լ�
//            2) �빮�ڸ� �Է¹޾� 'A'�κ��� �� ���ڱ��� ����ϴ� ����Լ�
//

//void prtuntilz(char end)
//{
//	if(end<97 || end>122) return;
//	else{
//		
//			printf("%c",end);
//			prtuntilz(end+1);
//		
//	}
//	return;
//}
//
//void prtfromA(char start)
//{
//	if(start<65 || start>90) return;
//
//	else {
//			prtfromA(start-1);
//			printf("%c",start);
//		}
//			
//		
//
//	return;
//}
//
//main()
//{
//	char c;
//
//	printf("�ҹ��� �Է� : ");
//	scanf("%c",&c);
//	prtuntilz(c);
//	puts("");
//	getchar();
//
//	printf("�빮�� �Է� : ");
//	scanf("%c",&c);
//	prtfromA(c);
//	puts("");
//}



// #3. �ִ����� ���ϱ� ���α׷�
//

//int gcd(int a, int b)
//{
//	int temp;
//
//	while(a){
//		if(b>a)                // a>=b? a : b �̰ɷ� ������ �� �ȵǴ��� �����غ���ڡڡڡڡڡ�
//		{
//			temp=a;    
//			a=b;
//			b=temp;
//		}
//
//		a = a-b;
//	}
//	return b;
//
//
//}
//
//int gcd2(int a, int b)
//{
//	int temp;
//
//	while(a){
//		if(b>a)
//		{
//			temp=a;
//			a=b;
//			b=temp;
//		}
//		a = a%b;
//	}
//	return b;
//
//
//}
//
//main()
//{
//	printf("%d \n", gcd(220,30));
//	printf("%d \n", gcd2(220,80));
//}




// #2. A la russe �Լ��� ���� ������ ����غ���
//     1. %2, / * �̿� ��[2. 1����ȣ �̿�X]��

//int Alarusse1(int a, int b)
//{
//	int sum = 0;
//	
//	while(a!=0){
//		if(a%2==1) 
//			sum += b;
//		a = a/2;
//		b = b*2;
//		
//	}
//	return sum;
//}
//
//int Alarusse2(int a, int b)
//{
//	int sum = 0;
//	
//			
//	while(a!=0){
//		if(a&0x1==1)    // AND�����ڸ� �̿��Ͽ� Ȧ��¦������ �� ���� Ȯ�ΰ��� �ڡڡڡڡ� ( ������ 4byte�̹Ƿ� 0x1? 1�� ��� X)  
//			sum += b;
//		a = a>>1;      // *2�� >>1 �� ���� /2�� <<1�� ���ٴ� ���̵��ڡڡڡ�
//		b = b<<1;
//	}
//
//	return sum;
//}
//
//
//main ()
//{
//
//	printf("%d\n", Alarusse1(27,65));
//	printf("%d\n", Alarusse2(27,65));
//
//}





// #1. srand�Լ� ����غ���

//main()
//{
//	int i, rand_num;
//	srand(time(NULL));
//	for(i=0;i<10;i++)
//	{
//		rand_num=rand();
//		printf("[%d] ", rand_num);
//
//
//	}
//
//}