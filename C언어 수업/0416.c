#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

// #7. MovetoFront, TransposeMethod 만들어보기
//
// 화면 지우기 system("cls");
// 대기시간 : sleep(1000); >>> 1초대기 (#include <windows.h>)
//

struct _node{
	int data;
	struct _node* next; //_node* next가 아니라 _node *next이다★★★★
};
typedef struct _node Node;
Node *head, *tail;   //Node* head가 아니라 Node *head이다.★★★★★

void initialize(void)
{
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	tail->next = tail;
}
int checkingFull(void) // 뭐가잘못됐나 한번 해보기!!!
{
	int count = 0;
	Node *nw;
	nw=head->next;
	while(nw!=tail)
	{
		count ++;
		nw = nw->next;
	}
	printf("count의 값은 %d\n", count);
	return count;
}

Node* finding(int num)
{
	//값이 있으면 1, 앖이 없으면 0 return
	Node *prend, *nextnd;
	prend = head;
	nextnd = head->next;
	while(nextnd!=tail && nextnd->data != num)
	{
		prend = prend->next;
		nextnd = prend->next;
	}

	if(nextnd!=tail) // nextnd->data 와 새로 들어온 num이 같다?!
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

	printf("\n출력 : ");
	while(pt!=tail)
	{
		printf("%d ", pt->data);
		pt = pt->next;
	}
	puts("");
}
// MovetoFront, TransposeMethod함수 만들기
void MovetoFront(int Rnum)
{
	Node *prend, *findnd;

	if(finding(Rnum)==NULL) puts("존재하지 않는 데이터입니다.");
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

	if(finding(Rnum)==NULL) puts("존재하지 않는 데이터입니다.");
	else if(finding(Rnum)==head) puts("이미 맨 앞 데이터입니다.");
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
	initialize(); // 리스트 초기화
	srand(time(NULL));
	while(count!=10/*checkingFull()!=10*/) // 이거 뭐가 잘못됐나 한번 고쳐보기 >>> checkingFull()을 해야되는데 checkingFull로하면 XXXXXXXXXXXX  ★★★★★★
	{	
		system("cls");
		Rnum = rand()%10+1;
		printf("%d\n", Rnum);
		if(finding(Rnum)==NULL) {insertlist(Rnum); count++;}
		showlist();
		Sleep(200);
	}
	puts("완성되었습니다");
	puts("");
	while(Rnum!=0){
		printf("맨 앞쪽으로 옮겨야 하는 정보를 입력하시오(0: 종료 ) : ");
	scanf("%d",&Rnum);
	MovetoFront(Rnum);
	showlist();
	}
	Rnum=-1;
	while(Rnum!=0){
	printf("앞노드와 바꿔야 하는 정보를 입력하시오(0: 종료 ) : ");
	scanf("%d",&Rnum);
	TransposeMethod(Rnum);
	showlist();
	}
}





// #6. List 기본 개념 익히기
//

//struct _node{
//	int key;
//	struct _node *next;
//};
//typedef struct _node Node;
//Node *head, *tail; // 양 끝 빨래기둥
//
//// 모든 자료구조는 초기화가 있다.
//void init_Node(void)
//{
//	head = (Node*) malloc(sizeof(Node));  // 땅에 기둥박음
//	tail = (Node*) malloc(sizeof(Node));  // 땅에 기둥박음
//	head->next = tail; // 빨래줄 연결
//	tail->next = tail; // 끝에 남는줄을 기둥에 묶어둠 
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
//	while(find->key != data && find!=tail) // 찾았을경우는 너무 쉬우므로 뒤로 else로 빼고 못찾았을 경우를 정의 : 뒤로 한칸씩 간다.
//	{									   // Or find와 tail이 같으면 난 빠져나간다. [나는 ||로 했는데 정답은 &&이다★★★★★★★★]
//		link = link->next;
//		find = find->next; // find = link->next; 로 쓰는게 더 좋다. (같이 뒤로 한칸씩 이란 의미)
//	}
////	else // 찾았을 경우, but 위에 while문 있으므로 else 안해도된다
////	{
//		// link->next = find->next; 이거는 링크를 삭제하는 과정 
////	}
//
//	if(find!=tail)	// 만약 find가 끝기둥이 아니라면 성공적으로 찾은것이다!!
//		puts("찾았다");
//	else puts("못찾았다"); // find가 끝기둥이라면 데이터를 찾지 못한 것이다.
//
//	return link; // 내가 실제 찾은것이 find지만 그 앞주소인 link를 return하는것이 훨씬 좋다 ★★★★★★★★★★★★★★
//				 // 이것을 이용해서 find를 제거해보자.
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
//void view_Node(void) // head와 tail을 제외한 빨래만 보기
//{
//	//printf("[%d]\n",head->next->key);
//	//printf("[%d]\n",head->next->next->key);  // next를 여러번쳐야해서 귀찮다
//	
//	Node *wk = head->next; // 첫번째 노드 주소를 wk에게 준다
//	//printf("[%d]\n", wk->key);
//	//wk = wk->next;
//	//printf("[%d]\n", wk->key); // 반복되므로 반복문을 사용하면
//
//	while(wk!=tail) // 끝기둥을 만나면  출력하지 마시오 ★★★[wk!=tail]★★★
//	{
//		printf("[%d]\n",wk->key);
//		wk=wk->next;
//	}
//
//}
//
//void ordered_insert_Node(int data)  // 정렬하여 삽입하기 	★★★
//{
//	Node* prevnd;
//	Node* nextnd;
//	Node* newnd;
//
//	prevnd=head;
//	nextnd = prevnd->next;
//
//	while(nextnd!=tail && data < nextnd->key) // data가 다음 노드보다 작으면 정렬 X == data가 다음 노드보다 크거나 같으면 삽입!!
//											  //                                           즉, 내림차순 정렬!!
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
//void Movetofront(Node* nd) // 찾은 노드를 맨 앞으로 보내기 [윈도우의 최근작업]
//{
//}
//
//void transposeMethod(Node* nd) // 찾은 노드를 앞으로 한칸 보내기
//{
//}
//
//void FrequencyCount(Node* nd) // 어떤 노드를 몇번 찾았냐를 카운트하여 그 것을 기준으로 정렬하기
//{
//}
//main()
//{
//	Node *temp;
//
//	init_Node(); // Linked List의 초기화
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
//	//insert_Node(3); // 첫번째 빨래
//	//insert_Node(2); // 두번째 빨래
//
//	//view_Node(); // 빨래 잘걸렸나 확인하기
//
//	//find_Node(3);
//	//find_Node(4);
//
//	//temp = find_Node(2);
//	//if(temp->next!=tail) deleting(temp); // 넘겨준 노드의 뒷노드를 삭제하는 함수
//
//	//view_Node();
//
//}


// #5. 행 버퍼의 값을 스택에 두었다가 역으로 출력하는 재귀함수 구현
//     ★★★★★★★★[쉬워보이는데 엄청 어렵다]★★★★★★★★★★
//

//void backprint(void)  // [생각해보기] 만약 한글을 이렇게 backprint하려면 어떡해야할까?
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


// #4[과제]. 1) 소문자를 입력받아 그 문자부터 'z'까지 출력하는 재귀함수
//            2) 대문자를 입력받아 'A'로부터 그 문자까지 출력하는 재귀함수
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
//	printf("소문자 입력 : ");
//	scanf("%c",&c);
//	prtuntilz(c);
//	puts("");
//	getchar();
//
//	printf("대문자 입력 : ");
//	scanf("%c",&c);
//	prtfromA(c);
//	puts("");
//}



// #3. 최대공약수 구하기 프로그램
//

//int gcd(int a, int b)
//{
//	int temp;
//
//	while(a){
//		if(b>a)                // a>=b? a : b 이걸로 했을때 왜 안되는지 생각해보기★★★★★★
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




// #2. A la russe 함수를 만들어서 곱셈을 계산해보기
//     1. %2, / * 이용 ★[2. 1번기호 이용X]★

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
//		if(a&0x1==1)    // AND연산자를 이용하여 홀수짝수인지 더 빨리 확인가능 ★★★★★ ( 어차피 4byte이므로 0x1? 1도 상관 X)  
//			sum += b;
//		a = a>>1;      // *2는 >>1 과 같고 /2는 <<1과 같다는 아이디어★★★★
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





// #1. srand함수 사용해보기

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