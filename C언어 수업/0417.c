#define _CRT_NO_SECURE_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #9. [�������� ����] 
//		10���� num�� ���� n��Ʈ���� w��° ��Ʈ���� ���� �����Ͽ� 10������ ��Ÿ���ÿ�
//		ex) 
// #10. [������]
//      ������ 4�ǹ�� ����ϱ� 0-0, 1~4-4,5~8-8...

main()
{
	int num,n,k;
	int N,i=0;
	printf("num�� n, k�� �� �Է� : ");
	scanf("%d %d %d",&num,&n,&k);

	printf("%d\n",(num>>n-1) &~  (0xFFFFFFFF<<k)); // ���� �¿� ����ߴµ� Ʋ�ȵ�
												   // ����� ���� (num>>n-1)&~((~0)<<3)
	puts("");
	printf("N�� �Է� : ");
	scanf("%d",&N);
	while(i<=N)
	{
		printf("%d\n",(i+0x3)&~(0x3));		// 3(2���� 11)�����ϰ� �ٽ� ���� ���ڸ��� clear
		i++;
	}
}



// #8. ���� little endian�� big endian���� �ٲ��ִ� ���α׷��� �ۼ� by) ��Ʈ������
//		short int a �� b�� �����ϼ���(unsigned, signed���X)
//
// #8-2. int�� �����غ��ÿ�

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
//	//printf("%X",b);    // ���� ��Ǯ��
//
//	printf("%X\n",a);
//	a = ((a&0xff)<<8)|((a>>8)&0xff);  // ���� �����Ǯ�� �ڡڡڡڡ�
//	printf("%X\n",a);
//
//	printf("%X\n",b);
//	b = ((b&0xff)<<24)|(((b>>8)&0xff)<<16) | (((b>>16)&0xff)<<8) | (((b>>24)&0xff)) ; // ��� �����Ǯ�̡ڡڡڡڡ�
//	printf("%X\n",b);
//
//}



// #7. ��Ʈ������ (bit check, bit mask, bit set, bit clear, bit xor)								
//     ���� int a=0xA5�� ���� �ִ�. int *p�� �̿��Ͽ� a�� ������� �����ϰ� ����ϼ���		
//	   (��Ʈ�� �������� 0���� �����Ѵ�)
//     1. 6����Ʈ�� 0���� 1�̸� true, 0�̸� false�� ���
//     2. 3����Ʈ�� 1����Ʈ�� 1�� set�ϰ� ���
//	   3. 1����Ʈ�� 2����Ʈ�� 0���� clear�ϰ� ���
//     4. 5,6,7�� ��Ʈ�� �����Ͽ� ���� ����ϼ���
//

//main()
//{
//	int a = 0xA5;
//	int* p = &a;
//
//	if( (*p & 1<<6/*0x40*/)) puts("True"); // ���� ��ü�� 
//	else puts("False");
//
//	//*p = *p | 0x0A;     //��Ǯ��
//	*p |= (1<<3)+(1<<1);  //�����Ǯ�� [�̷������ �ξ� ���̾��δ� �ڡڡڡڡڡڡ�]
//	printf("%X\n",*p);
//
//	//*p = *p &~ 0x06;
//	*p &= ~((1<<2) + (1<<1));	//�����Ǯ�� [�̷������ �ξ� ���̾��δ� �ڡڡڡڡڡڡ�]
//	printf("%X\n",*p);
//	 
//	*p = *p & 0xE0;			//�����Ǯ�� [�̰Ǳ��� �̷�������]
//	printf("%X\n",*p);			
//}




// #6. [10�и��� Ǯ�� �ڵ� - ��¦�ʰ�(�����5��)]�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
//     double linked list�� ������.
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
//	//if(finding==tail)                   // �̰� �ϴ��ּ�ó���ص� ���� ������� !! �����������ؼ�¥�ڡڡڡڡڡڡڡ�
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
//	init_dnode(); // DLL�� �ʱ�ȭ (������ո����)
//
//	order_insert_dnode(3);
//	order_insert_dnode(4);
//	order_insert_dnode(1);
//	order_insert_dnode(5);
//	order_insert_dnode(2);
//
//	print_node_next(); // head -> tail �� ���
//	puts("");
//	print_node_prev(); // tail -> head �� ���
//	puts("");
//}




// #5. ���̺귯���� ���� qsort����ϱ� �ڡڡ�Hard�ڡڡ�
//
//1. ���̺귯�� �����ϴ� qsort�� ���� comp_d �Լ� �ϼ�
//2. ���̺귯�� �����ϴ� qsort�� ���� comp_s �Լ� �ϼ�
//3. ���̺귯�� qsort�� �̿��Ͽ� 2�����迭�� �ִ� ���ڿ��� �����սô�.
//

// void printInt(int *arr, int size);
// void printDbl(double *arr, int size);
// void printstr(char (*arr)[7], int size);
//
//int comp_i(const void* a, const void* b) {   // comp_i, comp_d, comp_s�� �ݵ�� ���� ����������Ѵ١ڡڡڡڡڡڡڡڡڡڡڡ�                            
//											 // �� ��, �ʼ� ���Ѿ��ϴ� ������, return���� int, �Լ��� ���ڰ� void������ 2�� �ڡڡڡڡڡڡڡڡڡڡ�
//  return (*(int*)a - *(int*)b);
// }
//
////���̺귯�� �����ϴ� qsort�� ���� comp_d �Լ� �ϼ� �ڡڡڡڡڡڡڡڡ�[return *(double*)a-*(double*)b;�ϸ� x]
//int comp_d(const void* a, const void* b) {
//
//	if((*(double*)a>*(double*)b)) return 1;
//	else if(*(double*)a==*(double*)b) return 0;
//	else return -1;
//
// }
//
////���̺귯�� �����ϴ� qsort�� ���� comp_s �Լ� �ϼ�  �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� �߻����غ���
//int comp_s(const void* a, const void* b) {
//
//	return strcmp( (char*)a, (char*)b);  // �ڡڡڡڡڡڡڡڡڡڡڡڰ����ټ� ���� // �տ� -�� ���̸� �ٳ�������¡ڡڡڡڡڡڡڡڡ�
//
//}
//
// 
//
//
// int main(void) {
//  int arri[]= { 3,4,1,5,2,8,9,6,10,7 };
//  double arrd[] = { 3.2, 5.6, 4.3, 8.7, 2.3, 4.5, 2.1, 2.3, 4.6, 4.5};
// char name[][7]={"�赵ȯ","����ȫ","���߱�","������","���½�",
//    "���½�","����ȿ","����","������","������",
//    "������","�̹���","��뼮","���ȯ","���ȸ",
//    "������"};
//
//
// qsort(arri, sizeof(arri)/sizeof(arri[0]), sizeof(int), comp_i);
//  printInt(arri, sizeof(arri)/sizeof(arri[0]));
//
// qsort(arrd, sizeof(arrd)/sizeof(arrd[0]), sizeof(double), comp_d);
//  printDbl(arrd, sizeof(arrd)/sizeof(arrd[0]));
//
// //���̺귯�� qsort�� �̿��Ͽ� 2�����迭�� �ִ� ���ڿ��� �����սô�.
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


// #4. qsort�� �츮�� �����ϱ�
//

//#define swap(a,b) do{int t;\  // define�� �ٹٲ��Ϸ��� \�� ����ؾ��Ѵ� �ڡڡڡڡڡڡڡڡڡڡ�
//					 t=a;\
//					 a=b;\
//					 b=t;}while(0)
//int partition(char (*arr)[7], int s, int e) //����
// { 
//  int i, j; 
//  char buffer[7]; //�߰�
//  char pivot[7]; // �߰�
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
// void mystrqsort(char (*arr)[7], int s, int e) //����
// { 
//  int mid; 
//  if(s < e){ 
//   mid = partition(arr, s, e); 
//   mystrqsort(arr, s, mid - 1); 
//   mystrqsort(arr, mid + 1, e); 
//  } 
// }
//
//void print_sort_name(char (*p)[7], int cnt) //����
// {
//  int dx;
//  for(dx=0;dx<cnt;dx++)
//   printf("%s ", p[dx]);
// }
// main()
// {
// char name[][7]={"�赵ȯ","����ȫ","���߱�","������","���½�",
//    "���½�","����ȿ","����","������","������",
//    "������","�̹���","��뼮","���ȯ","���ȸ",
//    "������"};
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


// #3. myqsort�ϼ��ϱ�
//

//#define swap(a,b) do{int t; t=a;a=b;b=t;}while(0) // �̷��� �����ϴ°� ����α�!! �������־���!!!!
//int partition(int arr[], int s, int e) 
//{ 
// int big, small, pivot; 
// big = s; 
// small = e+1;   // �� e+1�� ������ �����غ��� �ڡڡڡڡڡڡڡ�
// pivot = arr[big]; 
// while(big < small){
//	
//	//pivot���� ū���� ã�� ���� �ڡڡڡڡڡڡڡڡڡڡڡڡڡ�
//	while(pivot>=arr[++big]); // ++big�� �������� big�� pivot�� ���� ��ġ���� �����߰�
//
//  //pivot ���� �۰ų� ���� ���� ã�� �����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
//	while(pivot<arr[--small]); // --small�� �������� small�� end + 1���� �����ߴ�
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


// #2. �̸��� 2���� �迭�� �ְ� ���� ������ �̿��Ͽ� ���� �Ͻÿ�.
//    [�������� �Լ��� �־����� �����Ͽ� �̸��� �����ϵ���]
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
//void sortstring(char (*c)[7], int n)   // ���ڿ� ������ strcpy, ���ڿ� �񱳴� srtcmp
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
//	char a[][7]={"�赵ȯ","���½�","���ȯ","����ȫ","���߱�",
//		"���½�","�̹���","������","������","������",
//		"������","����ȿ","����","��뼮","���ȸ",
//		"������"};
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




// 1. ü������ �����ϱ�
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
//	struct engine *p= man->sedan; // chaing���� ����
//	//man->sedan = (struct engine*)malloc(sizeof(int)*3); // ����ٰ� �־�ȴ� but ü�����Ÿ� ���ؼ� �Ʒ����ٰ�
//	p->piston=50;
//	p->fan=30;
//	p->pipe=20;
//}
//void main()
//{
//	struct car hi;
//	hi.sedan = (struct engine*)malloc(sizeof(struct engine)); // �Ĳ��� ���о��!!!
//	hyundai(&hi);
//	printf("%d %d %d \n", hi.sedan->piston, hi.sedan->fan,hi.sedan->pipe);
//}
