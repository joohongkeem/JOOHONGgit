#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

// #0. ���� �������� ���� ��������
//
//#define SWAP(x,y) {int t; t=a; a=b; b=t;}
//
//
//main()
//{
//	int a = 90, b = 60;
//	int sq=20;
//
//	//SWAP(a,b);					// SWAP�� define�Ҷ� {}�ȿ��� ������ ������ ������ ��ġ������ �����߻� !! 
//									// �ذ�å�� define�ȿ� {}�� �ִ¹��
//	
//	if(sq>0) SWAP(a,b);
//	
//	else SWAP(a,sq);				// ����� Ư�������ڡڡڡڡڡڡ� �� �������߻��ϴ°�?
//									// if�� ���� SWAP(a,b) �ڿ� �����ݷ�(;)�� �����Ƿ� �����߻�
//									// #define SWAP(x,y) do{ int t; t=a; a=b; b=t;}while(0) ���� �Լ� ����� �ȴ�
//
//	printf("%d %d\n",a,b);
//}




// #1. �����Ҵ�
//     �ڽ��� �� �ּҸ� �Է¹޾Ƽ� �ּ� ���̸�ŭ �����Ҵ� �ϰ�
//     �ش翵���� �ּҸ� �־� ����غ���

//main()
//{
//	char *a;
//	int i;
//
//	// �ּ��Է� ���� ���� �����
//	char buffer[1000];
//	// �ּҸ� �Է� �� ���̸� ���ϱ�
//	gets(buffer);
//	i = strlen(buffer);
//
//	// ���ѱ��̸�ŭ ���� �Ҵ��ϱ�
//	a = (char *) malloc(i*sizeof(char)+1);  // +1�� ���� ������ free(a)������ �����߻�
//									        // Why? NULL���ڱ��� �־�����������
//										    // �Ҵ����� ���� �κб��� free�Ϸ��ϱ⶧��??? �ڡڡڡ� 
//									        // [�׸� �׷����� �����غ���]�ڡڡڡڡڡڡڡ� 
//
//	// �Ҵ�� ������ ���ּ� �ֱ�
//	strcpy(a,buffer);
//	// ����ϱ�
//	puts(a);
//	free(a);
//
//}




// #2. char**p �� �̿��Ͽ� 2���� �����迭�� �Ҵ��ؼ�
//     ���ϴ� ������ ������ �Է��ϰ�, �׸�ŭ�� ������ �Է¹޴� ���α׷��� ¥����.
//

//main()
//{
//	char** p;
//	char buffer[100];
//	int n,i=0;
//	
//	printf("���ϴ� ������ ���� : ");
//	scanf("%d",&n);
//	p = (char**) malloc((sizeof(char*))*n);
//
//	fflush(stdin); // �Ǵ� getchar();
//	if(p==NULL) {printf("NOT ALLOCATED\n");}
//	else
//	{
//		
//		
//		for(i=0;i<n;i++)
//		{
//			printf("%d��° �����Է� : ",i+1);
//			gets(buffer);
//			p[i]=(char*) malloc(strlen(buffer)*sizeof(char) + 1);
//			strcpy(p[i],buffer);
//
//		}
//		puts("[�Էµ� ���� Ȯ��]");
//
//		for(i=0;i<n;i++)
//		{
//			printf("%d��° ���� : %s\n",i+1,p[i]);
//		}
//		for(i=0;i<n;i++)
//		{
//			free(p[i]);
//		}
//	}
//}


// #3. �Լ� 3�� �����ϱ�
//     ����ü ��� ���� ������ ��, ����ü �����ּ� ������ ��, ����ü �迭�ּ� ������ �� ���ϱ�
//

//struct num{
//	int fir;
//	int sec;
//};
//typedef struct num NUM;
//
//void func1(int a, int b)
//{
//	printf("�Լ� 1) %d + %d = %d \n",a,b,a+b);
//}
//void func2(NUM *a)
//{
//	printf("�Լ� 2) ����ü�� �� �� �� : %d\n", (*a).fir * (*a).sec);
//	printf("�Լ� 2) ����ü�� �� �� �� : %d\n", a->fir * a->sec);
//}
//void func3(NUM a[])
//{
//	
//	printf("�Լ� 3) �迭�� �� �� : %d\n",(*a).fir + (*a).sec + (*(a+1)).fir + (*(a+1)).sec);
//	printf("�Լ� 3) �迭�� �� �� : %d\n", a[0].fir + a[0].sec + a[1].fir + a[1].sec) ;
//	printf("�Լ� 3) �迭�� �� �� : %d\n", a->fir + a->sec + (a+1)->fir + (a+1)->sec);
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


// #4. ����ü �����ϱ�
//     >> �޸𸮸� �����Ѵ�.

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



// #5. ��������, ��������, ��������, ����, ��ŷ(����) �� ���̰� ����Ͻ��~~~
//


//struct subject{
//	int subname[5]; // ���� ���� ���� ����  ��ŷ
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
//	// �ڡڡ�[��ŷ�Լ�����]�ڡڡ�
//	// ó���� 1����� ��ζ� ���ϸ鼭
//	// �ڱ⺸�� ������ ������ ++
//	// �ڡڡڡڡڡڡڡڡڡڡڡڡ�
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
//		printf("%d��° ��� �̸� : ", i+1);
//		scanf("%s",man[i].name);
//
//		printf("�������� : ");
//		scanf("%d",& man[i].sub.subname[0]);
//		printf("�������� : ");
//		scanf("%d",& man[i].sub.subname[1]);
//		printf("�������� : ");
//		scanf("%d",& man[i].sub.subname[2]);
//
//		// ������� �� ���κ� Printf�� ���� �Է������ʰ�
//		// char *sz[]={"����","����","����"}; �صΰ�
//		// printf("%s���� : ",sz[i])
//		// scanf("%d", & man[i].sub.subname[i]); 
//		// �̷����ؼ� ����ϰ� �����ϼ̴�.
//
//		man[i].sub.subname[3]=sum(man[i].sub.subname);
//		man[i].avg=avg(man[i].sub.subname);
//
//	}
//
//	printf("---------------------------------------------------------------\n");
//	printf(" ����    ����    ����    ����    �հ�    ���    ����\n");
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



// #6. ���Ͻ�Ʈ�� ������
//

//main()
//{
//	FILE *fwp;
//	int a;
//	char b;
//	char name[10];
//
//	fwp = fopen("a.txt","w"); // fwp�� ��½�Ʈ��
//	fprintf(fwp,"%d %c %s\n", 10, 'A', "OMG");
//	fclose(fwp); // ��Ȯ�ϰ� ������ ���� ����??!!!!
//
//
//	fwp = fopen("a.txt","r"); // fwp�� �����̱⶧���� �̷��� �ٽ� �ٲ��� �� �ִ�.
//							  // �Է½�Ʈ������ ����
//	fscanf(fwp, "%d %c %s", &a, &b, name);
//	fclose(fwp);
//
//	fwp = fopen("a.txt","r+"); // ���������� �ƴ� ����Ʈ������ �������� �����Ѵ�.
//	fprintf(fwp,"%d",99000);
//	fclose(fwp);
//
//	fprintf(stdout,"%d %c %s\n", a,b,name);
//}



// #7.�׸������� COPY(backup)�غ���!!
// �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
// �ڡڡڡڡڡڡڡڡ��������� �Ⱥ��� �ս���©������������ �ͼ��ؾ��Ѵ� [10��]�ڡڡڡڡڡڡڡڡڡڡڡڡ�
// �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
// 
// �׸��� ���ݾ� buffer�� �Űܼ� �������ٺ��� ������ ������ �дٰ� �׸� �о�� ���ִµ�
// �̶� feof�Լ��� ����ϸ� �̰� ��������, ������ �������� ��Ȯ�ϰ� �ľ��� �� �ִ�.
//

//main()
//{
//	char buff[100]; // buffer�� ũ��� ��� 2^n���� �ؾ� ���� (�ʹ�Ŀ�� ���񶧸� �����������ִ�)
//	int count;
//	FILE *frp,*fwp;
//	int sizeff=0;
//
//	frp = fopen("1.jpg","rb"); 
//	fwp = fopen("backup.jpg", "wb"); // txt������ �ƴ� binary�����̹Ƿ� w���ƴ϶� wb�� �Է¡ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
//
//	while(1){
//		count = fread(buff,1,100,frp); // 100��¥�� ����ִ� buff�ٰ������ٰ� 1byte¥�� 100���� �ִ´�
//						   // 1,100�� �ִ������� 1��¥�� 100���̱� ����
//						   // ���� fread(buff,sizeof(struct num), 5,frp); �̶��
//						   // ����ü 5��¥���� �о�鿩�� buff�� ����ְڴ� (buffer�� struct num���̿��߰���!?)
//						   // fread�� ����� �о�鿴���� 100�� return�ϴٰ� �ƴϸ� �ٸ���[�������� �߸𸣰ڴ� �˻��غ���ڡڡ�]
//						   // �װ��� �޾��ִ°� count��� ����
//						   // fread ��ȯ�� : ���� ������ ������ ��ȯ, ���������� size*count��ŭ �о����� count��ȯ
//						   // ���� �߻��� EOF or count���� ������ ��ȯ�Ѵ�.
//		if(count<100)
//		{ //������ �� OR ������ ����
//			
//			if(feof(frp)!=0) // ������ ���� �����ߴ� (eof�� ���� �ƴϸ� 0 ���̸� �ٸ��� return)
//			{
//				fwrite(buff,1,count,fwp);
//				puts("����Ϸ�");
//				sizeff+=count;
//			}
//			else puts("�������");
//			break;
//		}
//		fwrite(buff,1,100,fwp);
//		sizeff += count;
//	}
//	printf("������ ũ��� %dbyte�Դϴ�.\n",sizeff);
//	
//}




// #8. [���� ����] item.txt(������)�� sales.txt(���̸�Ʈ)�� �о� �¶��� ���� ��Ȳ ���α׷��� �ϼ��ϼ���
//     ��strcmp string�� compare�Ѵ�.
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


	
	fwp = fopen("item.txt","r"); //read�� ��ǥ���� �Է½�Ʈ��
	for(i=0;i<19;i++)
	{
		fscanf(fwp,"%s%d", tem[i].name,&tem[i].price);

	}
	
	fwp = fopen("sales.txt","r"); //read�� ��ǥ���� �Է½�Ʈ��
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
	printf("=========== �Ｚ���� �¶��� ���� ��Ȳ ===========\n");
	printf("=================================================\n");
	printf("            ��ǰ��     �ܰ�     ����     �ݾ�\n");
	printf("-------------------------------------------------\n");
	for(i=0;i<19;i++)
	{
		printf("%2d %15s %8d %8d %8d\n",i+1,tem[i].name,tem[i].price,tem[i].count,tem[i].price*tem[i].count);
		sum +=tem[i].price*tem[i].count;
	}
	printf("-------------------------------------------------\n");
	printf("                          ���� �հ� %9d\n",sum);
	printf("=================================================\n");

}