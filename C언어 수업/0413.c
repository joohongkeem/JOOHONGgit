#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

// #0. 전날 마지막에 내준 과제문제
//
//#define SWAP(x,y) {int t; t=a; a=b; b=t;}
//
//
//main()
//{
//	int a = 90, b = 60;
//	int sq=20;
//
//	//SWAP(a,b);					// SWAP을 define할때 {}안에서 만들지 않으면 선언문의 위치문제로 에러발생 !! 
//									// 해결책은 define안에 {}를 넣는방법
//	
//	if(sq>0) SWAP(a,b);
//	
//	else SWAP(a,sq);				// 강사님 특별숙제★★★★★★★ 왜 에러가발생하는가?
//									// if문 뒤의 SWAP(a,b) 뒤에 세미콜론(;)이 있으므로 문제발생
//									// #define SWAP(x,y) do{ int t; t=a; a=b; b=t;}while(0) 으로 함수 만들면 된다
//
//	printf("%d %d\n",a,b);
//}




// #1. 동적할당
//     자신의 집 주소를 입력받아서 주소 길이만큼 동적할당 하고
//     해당영역에 주소를 넣어 출력해보기

//main()
//{
//	char *a;
//	int i;
//
//	// 주소입력 받을 공간 만들기
//	char buffer[1000];
//	// 주소를 입력 후 길이를 구하기
//	gets(buffer);
//	i = strlen(buffer);
//
//	// 구한길이만큼 동적 할당하기
//	a = (char *) malloc(i*sizeof(char)+1);  // +1을 넣지 않으면 free(a)했을때 에러발생
//									        // Why? NULL문자까지 넣어주지않으면
//										    // 할당하지 않은 부분까지 free하려하기때문??? ★★★★ 
//									        // [그림 그려서잘 생각해보기]★★★★★★★★ 
//
//	// 할당된 영역에 집주소 넣기
//	strcpy(a,buffer);
//	// 출력하기
//	puts(a);
//	free(a);
//
//}




// #2. char**p 를 이용하여 2차원 동적배열을 할당해서
//     원하는 문장의 개수를 입력하고, 그만큼의 문장을 입력받는 프로그램을 짜보자.
//

//main()
//{
//	char** p;
//	char buffer[100];
//	int n,i=0;
//	
//	printf("원하는 문장의 갯수 : ");
//	scanf("%d",&n);
//	p = (char**) malloc((sizeof(char*))*n);
//
//	fflush(stdin); // 또는 getchar();
//	if(p==NULL) {printf("NOT ALLOCATED\n");}
//	else
//	{
//		
//		
//		for(i=0;i<n;i++)
//		{
//			printf("%d번째 문장입력 : ",i+1);
//			gets(buffer);
//			p[i]=(char*) malloc(strlen(buffer)*sizeof(char) + 1);
//			strcpy(p[i],buffer);
//
//		}
//		puts("[입력된 문장 확인]");
//
//		for(i=0;i<n;i++)
//		{
//			printf("%d번째 문장 : %s\n",i+1,p[i]);
//		}
//		for(i=0;i<n;i++)
//		{
//			free(p[i]);
//		}
//	}
//}


// #3. 함수 3개 구현하기
//     구조체 멤버 각각 던져서 합, 구조체 변수주소 던져서 곱, 구조체 배열주소 던져서 합 구하기
//

//struct num{
//	int fir;
//	int sec;
//};
//typedef struct num NUM;
//
//void func1(int a, int b)
//{
//	printf("함수 1) %d + %d = %d \n",a,b,a+b);
//}
//void func2(NUM *a)
//{
//	printf("함수 2) 구조체의 두 수 곱 : %d\n", (*a).fir * (*a).sec);
//	printf("함수 2) 구조체의 두 수 곱 : %d\n", a->fir * a->sec);
//}
//void func3(NUM a[])
//{
//	
//	printf("함수 3) 배열의 총 합 : %d\n",(*a).fir + (*a).sec + (*(a+1)).fir + (*(a+1)).sec);
//	printf("함수 3) 배열의 총 합 : %d\n", a[0].fir + a[0].sec + a[1].fir + a[1].sec) ;
//	printf("함수 3) 배열이 총 합 : %d\n", a->fir + a->sec + (a+1)->fir + (a+1)->sec);
//}
//
//main()
//{
//	NUM a={1,2}, b={3,4}, c[2]={5,6,7,8};
//
//	func1(a.fir,a.sec);
//	func2(&b);
//	func3(c);
//}


// #4. 공용체 이해하기
//     >> 메모리를 공유한다.

//union num{
//	int a;
//	char b[4];
//};
//main()
//{
//	union num zz;
//	zz.a=0x12345678;
//
//	printf("%x\n",zz.a);
//	printf("%x\n",zz.b[0]);
//	zz.b[0]=0x99;
//	printf("%x\n",zz.a);
//	printf("%x\n",zz.b[0]);
//
//}



// #5. 국어점수, 수학점수, 영어점수, 총점, 랭킹(순위) 를 먹이고 출력하쎄용~~~
//


//struct subject{
//	int subname[5]; // 국어 수학 영어 총점  랭킹
//};
//typedef struct subject SB;
//
//struct sung{
//	char name[10];
//	float avg;
//	SB sub;
//};
//typedef struct sung S;
//
//float avg(int (*p))
//{
//	return (p[0]+p[1]+p[2])/3.0;
//}
//
//int sum(int (*p))
//{
//	return p[0]+p[1]+p[2];
//}
//
//	// ★★★[랭킹함수꿀팁]★★★
//	// 처음에 1로잡고 모두랑 비교하면서
//	// 자기보다 작은거 있으면 ++
//	// ★★★★★★★★★★★★★
//int ranking(S *p,int n)
//{
//	int rank = 1;
//	int i;
//	for(i=0;i<3;i++)
//		if(p[n].avg<p[i].avg) rank++;
//	return rank;
//} 
//
//main()
//{
//	int i;
//	S man[3];
//	int n;
//
//	
//	for(i=0;i<3;i++)
//	{
//		printf("%d번째 사람 이름 : ", i+1);
//		scanf("%s",man[i].name);
//
//		printf("국어점수 : ");
//		scanf("%d",& man[i].sub.subname[0]);
//		printf("수학점수 : ");
//		scanf("%d",& man[i].sub.subname[1]);
//		printf("영어점수 : ");
//		scanf("%d",& man[i].sub.subname[2]);
//
//		// 강사님은 이 윗부분 Printf를 직접 입력하지않고
//		// char *sz[]={"국어","수학","영어"}; 해두고
//		// printf("%s점수 : ",sz[i])
//		// scanf("%d", & man[i].sub.subname[i]); 
//		// 이렇게해서 깔끔하게 정리하셨다.
//
//		man[i].sub.subname[3]=sum(man[i].sub.subname);
//		man[i].avg=avg(man[i].sub.subname);
//
//	}
//
//	printf("---------------------------------------------------------------\n");
//	printf(" 성명    국어    수학    영어    합계    평균    순위\n");
//	printf("---------------------------------------------------------------\n");
//	for(i=0;i<3;i++)
//	{
//		int j= 0;
//		printf("%-9s",man[i].name);
//		for(j=0;j<4;j++)
//			printf("%-8d",man[i].sub.subname[j]);
//		
//		printf("%-8.2f",man[i].avg);
//		printf("  %d",ranking(man,i));
//		puts("");
//	}
//	printf("---------------------------------------------------------------\n");
//}



// #6. 파일스트림 만들어보기
//

//main()
//{
//	FILE *fwp;
//	int a;
//	char b;
//	char name[10];
//
//	fwp = fopen("a.txt","w"); // fwp는 출력스트림
//	fprintf(fwp,"%d %c %s\n", 10, 'A', "OMG");
//	fclose(fwp); // 정확하게 써지는 것을 보장??!!!!
//
//
//	fwp = fopen("a.txt","r"); // fwp는 변수이기때문에 이렇게 다시 바꿔줄 수 있다.
//							  // 입력스트림으로 변경
//	fscanf(fwp, "%d %c %s", &a, &b, name);
//	fclose(fwp);
//
//	fwp = fopen("a.txt","r+"); // 변수단위가 아닌 바이트단위로 지워가며 진행한다.
//	fprintf(fwp,"%d",99000);
//	fclose(fwp);
//
//	fprintf(stdout,"%d %c %s\n", a,b,name);
//}



// #7.그림파일을 COPY(backup)해보자!!
// ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
// ★★★★★★★★★이정도는 안보고도 손쉽게짤수있을정도로 익숙해야한다 [10번]★★★★★★★★★★★★★
// ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
// 
// 그림을 조금씩 buffer에 옮겨서 가져오다보면 파일이 깨져서 읽다가 그만 읽어올 수있는데
// 이때 feof함수를 사용하면 이게 끝난건지, 파일이 깨진건지 정확하게 파악할 수 있다.
//

//main()
//{
//	char buff[100]; // buffer의 크기는 사실 2^n으로 해야 좋다 (너무커도 낭비때매 느려질때가있다)
//	int count;
//	FILE *frp,*fwp;
//	int sizeff=0;
//
//	frp = fopen("1.jpg","rb"); 
//	fwp = fopen("backup.jpg", "wb"); // txt파일이 아닌 binary파일이므로 w가아니라 wb로 입력★★★★★★★★★★★★★★★
//
//	while(1){
//		count = fread(buff,1,100,frp); // 100개짜리 비어있는 buff바가지에다가 1byte짜리 100개를 넣는다
//						   // 1,100을 넣는이유는 1개짜리 100개이기 때문
//						   // 만약 fread(buff,sizeof(struct num), 5,frp); 이라면
//						   // 구조체 5개짜리를 읽어들여서 buff에 집어넣겠다 (buffer도 struct num꼴이여야겠죠!?)
//						   // fread는 제대로 읽어들였으면 100을 return하다가 아니면 다른값[몇인지는 잘모르겠다 검색해보기★★★]
//						   // 그값을 받아주는게 count라는 변수
//						   // fread 반환값 : 읽은 데이터 개수를 반환, 정상적으로 size*count만큼 읽었으면 count반환
//						   // 에러 발생시 EOF or count보다 작은값 반환한다.
//		if(count<100)
//		{ //파일이 끝 OR 파일의 깨짐
//			
//			if(feof(frp)!=0) // 파일의 끝에 도달했다 (eof는 끝이 아니면 0 끝이면 다른값 return)
//			{
//				fwrite(buff,1,count,fwp);
//				puts("복사완료");
//				sizeff+=count;
//			}
//			else puts("복사실패");
//			break;
//		}
//		fwrite(buff,1,100,fwp);
//		sizeff += count;
//	}
//	printf("파일의 크기는 %dbyte입니다.\n",sizeff);
//	
//}




// #8. [메일 과제] item.txt(제조사)와 sales.txt(하이마트)를 읽어 온라인 매출 현황 프로그램을 완성하세요
//     ★strcmp string을 compare한다.
//
struct item{
	char name[15];
	int price;
	int count;
	int total;
};
typedef struct item ITEM;

main()
{
	
	ITEM tem[19];
	char buffer[15];
	int pri,cnt,tot;
	int sum=0;
	int i,j;
	FILE *fwp, *frp;


	
	fwp = fopen("item.txt","r"); //read가 대표적인 입력스트림
	for(i=0;i<19;i++)
	{
		fscanf(fwp,"%s%d", tem[i].name,&tem[i].price);

	}
	
	fwp = fopen("sales.txt","r"); //read가 대표적인 입력스트림
	for(i=0;i<19;i++)
	{
		fscanf(fwp,"%s",buffer);
		for(j=0;j<19;j++)
		{
			if(strcmp(buffer,tem[j].name)==0) 
			{
				fscanf(fwp,"%d",&tem[j].count);
			
			}
	
		}
	}

	fclose(fwp);


	printf("=================================================\n");
	printf("=========== 삼성전자 온라인 매출 현황 ===========\n");
	printf("=================================================\n");
	printf("            상품명     단가     개수     금액\n");
	printf("-------------------------------------------------\n");
	for(i=0;i<19;i++)
	{
		printf("%2d %15s %8d %8d %8d\n",i+1,tem[i].name,tem[i].price,tem[i].count,tem[i].price*tem[i].count);
		sum +=tem[i].price*tem[i].count;
	}
	printf("-------------------------------------------------\n");
	printf("                          매출 합계 %9d\n",sum);
	printf("=================================================\n");

}