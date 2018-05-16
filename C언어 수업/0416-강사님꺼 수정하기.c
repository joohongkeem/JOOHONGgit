#include <stdio.h>
#include <time.h>
#include <windows.h>

#define SLEEP(a) {int t = clock(); while((clock()-t)<a);}
typedef struct _list  List;
struct _list{
 int key;
 struct _list *next;

};


List *head, *tail;
int link_size;

void init_List()
{
 head = ( List*)malloc(sizeof( List));
 tail = ( List*)malloc(sizeof( List));
 head->next = tail;
 tail->next = tail;
 link_size = 0;
}

void print_List()
{
 List *cur;

 cur = head->next;
 printf("\n출력 : ");
 while(cur!=tail)
 {
  printf("%d ", cur->key);
  cur=cur->next;
 }
}

void rand_insert_sort()
{
 List *nw,*cur;

 while(link_size < 10)
 {
  system("cls");

  nw = ( List*)malloc(sizeof( List));
  nw->key = rand()%10 + 1;
  printf("\n%d",nw->key);

  cur = head;
  while((cur->next != tail) && (cur->next->key < nw->key))
  {
   cur = cur->next;
  }  
  if(cur->next->key == nw->key)
  {
   puts("중복입니다.");
   free(nw);
  }  
  else
  {
   nw->next = cur->next;
   cur->next = nw;
   link_size++;
  }

  print_List();
  SLEEP(100);
 }
 printf("\n 완성되었습니다.");
 SLEEP(500);

}

void movetofront(void)
{ 
 List  *fwk, *swk;
 int node_info;
 printf("\n맨앞쪽으로 옮겨야하는 정보를 입력하시오 : ");
 scanf("%d", &node_info);

 swk=head;
 fwk=swk->next; //fwk=head->next;

 while(fwk->key!=node_info && fwk!=tail)
 {//찾는 값이 없거나 찾고있는 노드가 tail이 아니라면
  swk=swk->next;
  fwk=swk->next; //fwk=fwk->next;  //코드의 안정성
 }
 if(fwk!=tail && swk!=head) //찾았을 경우 swk!=head
 {
  List *move;
  move= fwk;
  swk->next = fwk->next;

  move->next = head->next;
  head->next = move;
 }
}


void transpose_method()
{
 List *CCC, *BBB;

 int node_info;
 printf("\n앞노드와  바꿔야 하는 정보를 입력하시오 : ");
 scanf("%d", &node_info);

 BBB=head;
 CCC=BBB->next; //CCC=head->next;

 while(CCC->key!=node_info && CCC!=tail)
 {//찾는 값이 없거나 찾고있는 노드가 tail이 아니라면

  BBB=BBB->next;
  CCC=BBB->next; //CCC=CCC->next;  //코드의 안정성
 }
 if(CCC!=tail && BBB!=head) //찾았을 경우 앞쪽의 AAA가 필요하다.
 {
  List *move;
  List *AAA;//AAA뒤에 move를 넣어야 한다.AAA위치를 찾자
  move= CCC;
  BBB->next = CCC->next;


  AAA=head;
  //move=head->next; //삭제(불필요)
  //while(BBB != CCC && BBB!=tail)
  //{
  // AAA=AAA->next;
  // BBB=AAA->next;
  //}
  while(move != BBB && move!=tail)
  {
   AAA=AAA->next;
   move=AAA->next;
  }
  AAA->next=CCC;
  CCC->next=BBB;
  //BBB->next=CCC;
  //move->next = head->next;
  //head->next = move;


 }

}
void main()
{

 srand(time(NULL));
 getchar();
 init_List();
 rand_insert_sort();

 while(1)
 {

  movetofront();
  print_List();

  transpose_method();
  print_List();
 }

}