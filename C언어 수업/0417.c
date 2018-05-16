#define _CRT_NO_SECURE_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #9. [본격적인 문제] 
//		10진수 num의 우측 n비트에서 w번째 비트까지 값을 추출하여 10진수로 나타내시오
//		ex) 
// #10. [어려운문제]
//      무조건 4의배수 출력하기 0-0, 1~4-4,5~8-8...

main()
{
	int num,n,k;
	int N,i=0;
	printf("num과 n, k의 값 입력 : ");
	scanf("%d %d %d",&num,&n,&k);

	printf("%d\n",(num>>n-1) &~  (0xFFFFFFFF<<k)); // 나는 좌우 쇽쇽했는데 틀렸따
												   // 강사님 답은 (num>>n-1)&~((~0)<<3)
	puts("");
	printf("N값 입력 : ");
	scanf("%d",&N);
	while(i<=N)
	{
		printf("%d\n",(i+0x3)&~(0x3));		// 3(2진수 11)을더하고 다시 뒤의 두자리를 clear
		i++;
	}
}



// #8. 위의 little endian을 big endian으로 바꿔주는 프로그램을 작성 by) 비트연산자
//		short int a 를 b에 저장하세요(unsigned, signed상관X)
//
// #8-2. int를 변경해보시오

//main()
//{
//	short int a = 0x1234;
//	//short int b = 0x0000;
//	//short int temp;
//
//	int b = 0x12345678;
//
//	//temp = a&(0x00FF);
//	//b = b|(temp<<8);
//	//temp = a&0xFF00;
//	//b = b|(temp>>8);
//	//printf("%X",b);    // 요고는 내풀이
//
//	printf("%X\n",a);
//	a = ((a&0xff)<<8)|((a>>8)&0xff);  // 요고는 강사님풀이 ★★★★★
//	printf("%X\n",a);
//
//	printf("%X\n",b);
//	b = ((b&0xff)<<24)|(((b>>8)&0xff)<<16) | (((b>>16)&0xff)<<8) | (((b>>24)&0xff)) ; // 요게 강사님풀이★★★★★
//	printf("%X\n",b);
//
//}



// #7. 비트연산자 (bit check, bit mask, bit set, bit clear, bit xor)								
//     다음 int a=0xA5의 값이 있다. int *p를 이용하여 a의 내용들을 변경하고 출력하세요		
//	   (비트는 우측에서 0부터 시작한다)
//     1. 6번비트가 0인지 1이면 true, 0이면 false를 출력
//     2. 3번비트와 1번비트를 1로 set하고 출력
//	   3. 1번비트와 2번비트를 0으로 clear하고 출력
//     4. 5,6,7번 비트를 추출하여 값을 출력하세요
//

//main()
//{
//	int a = 0xA5;
//	int* p = &a;
//
//	if( (*p & 1<<6/*0x40*/)) puts("True"); // 저거 자체에 
//	else puts("False");
//
//	//*p = *p | 0x0A;     //내풀이
//	*p |= (1<<3)+(1<<1);  //강사님풀이 [이런방식이 훨씬 많이쓰인다 ★★★★★★★]
//	printf("%X\n",*p);
//
//	//*p = *p &~ 0x06;
//	*p &= ~((1<<2) + (1<<1));	//강사님풀이 [이런방식이 훨씬 많이쓰인다 ★★★★★★★]
//	printf("%X\n",*p);
//	 
//	*p = *p & 0xE0;			//강사님풀이 [이건구냥 이렇게하자]
//	printf("%X\n",*p);			
//}




// #6. [10분만에 풀기 코드 - 살짝초과(강사님5분)]★★★★★★★★★★★★★★★
//     double linked list를 만들자.
//

//struct _dnode{
//	int key;
//	struct _dnode *prev;
//	struct _dnode *next;
//};
//typedef struct _dnode Dnode;
//Dnode *head, *tail;
//
//void init_dnode(void)
//{
//	head = (Dnode*) malloc(sizeof(Dnode));
//	tail = (Dnode*) malloc(sizeof(Dnode));
//
//	head->prev = head;
//	head->next = tail;
//	tail->prev = head;
//	tail->next = tail;
//}
//
//void order_insert_dnode(int data)
//{
//	Dnode *newnode = (Dnode*)malloc(sizeof(Dnode));
//	Dnode *finding ;
//	newnode->key = data;
//	
//	finding = head->next;
//
//	while(finding!=tail && data < finding->key) 
//	{ finding = finding->next;}
//
//	//if(finding==tail)                   // 이거 싹다주석처리해도 전혀 지장없다 !! 좀만더생각해서짜자★★★★★★★
//	//{
//	//	newnode->prev = tail->prev;
//	//	tail->prev->next = newnode;
//	//	tail->prev = newnode;
//	//	//head->next = newnode;
//	//	newnode->next = tail;
//	//	//newnode->prev = head;
//	//}
//
//	//else 
//	//{
//		newnode -> prev = finding -> prev;
//		finding -> prev -> next = newnode;
//		newnode -> next = finding;
//		finding -> prev = newnode;
//	//}
//}
//
//void print_node_next(void)
//{
//	Dnode *temp;
//	temp = head->next;
//	while(temp!=tail)
//	{ printf("%d ",temp->key); temp=temp->next;}
//
//}
//
//void print_node_prev(void)
//{	
//	Dnode *temp;
//	temp = tail->prev;
//	while(temp!=head)
//	{ printf("%d ",temp->key); temp=temp->prev;}
//}
//main()
//{
//	init_dnode(); // DLL의 초기화 (빨래기둥만들기)
//
//	order_insert_dnode(3);
//	order_insert_dnode(4);
//	order_insert_dnode(1);
//	order_insert_dnode(5);
//	order_insert_dnode(2);
//
//	print_node_next(); // head -> tail 로 출력
//	puts("");
//	print_node_prev(); // tail -> head 로 출력
//	puts("");
//}




// #5. 라이브러리를 통해 qsort사용하기 ★★★Hard★★★
//
//1. 라이브러리 제공하는 qsort를 위한 comp_d 함수 완성
//2. 라이브러리 제공하는 qsort를 위한 comp_s 함수 완성
//3. 라이브러리 qsort를 이용하여 2차원배열에 있는 문자열을 정렬합시다.
//

// void printInt(int *arr, int size);
// void printDbl(double *arr, int size);
// void printstr(char (*arr)[7], int size);
//
//int comp_i(const void* a, const void* b) {   // comp_i, comp_d, comp_s는 반드시 내가 정의해줘야한다★★★★★★★★★★★★                            
//											 // 이 때, 필수 지켜야하는 조건이, return형이 int, 함수의 인자가 void포인터 2개 ★★★★★★★★★★★
//  return (*(int*)a - *(int*)b);
// }
//
////라이브러리 제공하는 qsort를 위한 comp_d 함수 완성 ★★★★★★★★★[return *(double*)a-*(double*)b;하면 x]
//int comp_d(const void* a, const void* b) {
//
//	if((*(double*)a>*(double*)b)) return 1;
//	else if(*(double*)a==*(double*)b) return 0;
//	else return -1;
//
// }
//
////라이브러리 제공하는 qsort를 위한 comp_s 함수 완성  ★★★★★★★★★★★★★★★★★★ 잘생각해보기
//int comp_s(const void* a, const void* b) {
//
//	return strcmp( (char*)a, (char*)b);  // ★★★★★★★★★★★★가나다순 정리 // 앞에 -를 붙이면 다나가순출력★★★★★★★★★
//
//}
//
// 
//
//
// int main(void) {
//  int arri[]= { 3,4,1,5,2,8,9,6,10,7 };
//  double arrd[] = { 3.2, 5.6, 4.3, 8.7, 2.3, 4.5, 2.1, 2.3, 4.6, 4.5};
// char name[][7]={"김도환","김주홍","김중근","정지윤","한태승",
//    "문태승","박정효","백경규","서재학","송은아",
//    "오유준","이무원","김용석","김용환","허승회",
//    "유승훈"};
//
//
// qsort(arri, sizeof(arri)/sizeof(arri[0]), sizeof(int), comp_i);
//  printInt(arri, sizeof(arri)/sizeof(arri[0]));
//
// qsort(arrd, sizeof(arrd)/sizeof(arrd[0]), sizeof(double), comp_d);
//  printDbl(arrd, sizeof(arrd)/sizeof(arrd[0]));
//
// //라이브러리 qsort를 이용하여 2차원배열에 있는 문자열을 정렬합시다.
//
// qsort(name, sizeof(name)/sizeof(name[0]), sizeof(name[0]), comp_s);
//  printstr(name, sizeof(name)/sizeof(name[0]));
//
// return 0;
// }
//
//
// void printInt(int *arr, int size) {
//  int dx=0;
//  for (dx=0; dx< size; ++dx) {
//   printf("%d ", arr[dx]);
//  }
//  printf("\n");
// }
//
//void printDbl(double *arr, int size) {
//  int dx=0;
//  for (dx=0; dx< size; ++dx) {
//   printf("%.1f  ", arr[dx]);
//  }
//  printf("\n");
// }
//
//void printstr(char (*arr)[7], int size) {
//  int dx=0;
//  for (dx=0; dx< size; ++dx) {
//   printf("%s ", arr[dx]);
//  }
//  printf("\n");
// }


// #4. qsort로 우리반 정렬하기
//

//#define swap(a,b) do{int t;\  // define때 줄바꿈하려면 \를 사용해야한다 ★★★★★★★★★★★
//					 t=a;\
//					 a=b;\
//					 b=t;}while(0)
//int partition(char (*arr)[7], int s, int e) //수정
// { 
//  int i, j; 
//  char buffer[7]; //추가
//  char pivot[7]; // 추가
//  i = s; 
//  j = e + 1; 
//
// // pivot = arr[i];
//  strcpy(pivot,arr[i]);
//
//  while(i < j){ 
//
//   //while(arr[++i]<=pivot);
//   while(strcmp(arr[++i],pivot)<=0);
//
//   //while(arr[--j]>pivot);
//   while(strcmp(arr[--j],pivot)>0);
//   if(i < j){ 
//	//swap(arr[i], arr[j]);
//	strcpy(buffer,arr[i]);
//	strcpy(arr[i],arr[j]);
//	strcpy(arr[j],buffer);
//   } 
//  } 
//  //swap(arr[s], arr[j]);
//	strcpy(buffer,arr[s]);
//	strcpy(arr[s],arr[j]);
//	strcpy(arr[j],buffer);
//  return j; 
// } 
// void mystrqsort(char (*arr)[7], int s, int e) //수정
// { 
//  int mid; 
//  if(s < e){ 
//   mid = partition(arr, s, e); 
//   mystrqsort(arr, s, mid - 1); 
//   mystrqsort(arr, mid + 1, e); 
//  } 
// }
//
//void print_sort_name(char (*p)[7], int cnt) //수정
// {
//  int dx;
//  for(dx=0;dx<cnt;dx++)
//   printf("%s ", p[dx]);
// }
// main()
// {
// char name[][7]={"김도환","김주홍","김중근","정지윤","한태승",
//    "문태승","박정효","백경규","서재학","송은아",
//    "오유준","이무원","김용석","김용환","허승회",
//    "유승훈"};
//
// print_sort_name(name, 16);
// puts("");
//
// mystrqsort(name,0,15);
// print_sort_name(name, 16);
// puts("");
//
// 
//
//}


// #3. myqsort완성하기
//

//#define swap(a,b) do{int t; t=a;a=b;b=t;}while(0) // 이렇게 스왑하는거 적어두기!! 과제에있었따!!!!
//int partition(int arr[], int s, int e) 
//{ 
// int big, small, pivot; 
// big = s; 
// small = e+1;   // 왜 e+1이 들어가는지 생각해보자 ★★★★★★★★
// pivot = arr[big]; 
// while(big < small){
//	
//	//pivot보다 큰값을 찾는 구문 ★★★★★★★★★★★★★★
//	while(pivot>=arr[++big]); // ++big을 쓰기위해 big을 pivot과 같은 위치부터 시작했고
//
//  //pivot 보다 작거나 같은 값을 찾는 구문★★★★★★★★★★★★★★★
//	while(pivot<arr[--small]); // --small을 쓰기위해 small을 end + 1부터 시작했다
//
//  if(big < small){ 
//   swap(arr[big], arr[small]); 
//  } 
// } 
// swap(arr[s], arr[small]);
// return small; 
//} 
//void myqsort(int arr[], int s, int e) 
//{ 
// int mid; 
// if(s < e){ 
//  mid = partition(arr, s, e); 
//  myqsort(arr, s, mid - 1); 
//  myqsort(arr, mid + 1, e); 
// } 
//}
//
//main()
//{
// int arri[]= { 3,4,1,5,2,8,9,6,10,7 };
// int dx;
// myqsort(arri,0,9);
//
// for(dx=0;dx<10;dx++) printf("%d ",arri[dx]);
//
// puts("");
//}


// #2. 이름을 2차원 배열에 넣고 다음 정렬을 이용하여 정렬 하시오.
//    [정수정렬 함수가 주어진걸 수정하여 이름을 정렬하도록]
//

//
//void sort(int a[], int n)
//{
//	int i, j, t;
//	for (i = 1; i < n; i++)
//	{
//		t = a[i];
//		j = i;
//		while (a[j-1] > t && j > 0)
//		{
//			a[j] = a[j-1];
//			j--;
//		}
//		a[j] = t;
//	}
//}
//void sortstring(char (*c)[7], int n)   // 문자열 대입은 strcpy, 문자열 비교는 srtcmp
//{
//	int i, j;
//	char t[7];
//	for (i = 1; i < n; i++)
//	{
//		strcpy(t,c[i]);
//		j = i;
//		while (strcmp(c[j-1],t)>0 && j > 0)
//		{
//			strcpy(c[j],c[j-1]);
//			j--;
//		}
//		strcpy(c[j],t);
//	}
//}
//main()
//{
//	int i;
//	char a[][7]={"김도환","한태승","김용환","김주홍","김중근",
//		"문태승","이무원","정지윤","서재학","송은아",
//		"오유준","박정효","백경규","김용석","허승회",
//		"유승훈"};
//	int b[]={3,4,1,5,2};
//	int dx;
//
//	for (i=0;i<5;i++) printf("%d ",b[i]);
//	puts("");
//	sort(b,sizeof(b)/sizeof(int));
//	for (i=0;i<5;i++) printf("%d ",b[i]);
//	puts("");
//
//	sortstring(a,(sizeof(a))/(sizeof(a[0])));
//
//	for(i=0;i<(sizeof(a))/(sizeof(a[0]));i++) printf("%s ",a[i]);
//	puts("");
//}




// 1. 체인제거 공부하기
//

//struct engine{
//	int piston;
//	int fan;
//	int pipe;
//};
//struct car{
//	struct engine *sedan, *sports;
//};
//void hyundai(struct car *man)
//{
//	struct engine *p= man->sedan; // chaing제거 과정
//	//man->sedan = (struct engine*)malloc(sizeof(int)*3); // 여기다가 넣어도된다 but 체인제거를 위해선 아래에다가
//	p->piston=50;
//	p->fan=30;
//	p->pipe=20;
//}
//void main()
//{
//	struct car hi;
//	hi.sedan = (struct engine*)malloc(sizeof(struct engine)); // 꼼꼼히 잘읽어보기!!!
//	hyundai(&hi);
//	printf("%d %d %d \n", hi.sedan->piston, hi.sedan->fan,hi.sedan->pipe);
//}
