#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// ���� STANDARD�� ��� !!
// �̰� �� �����ϰ� �Ѿ���Ѵ� ������!!!

////2���� �迭�� 2���� ��� ����
//void arr2d(int (*p)[3])
//{
//	p[0][1]=3;
//	*(*(p+1)+2)=9;
//
//}
//
//// 2���� �迭�� 1������� ����
//void arr1d (int *p)
//{
//	p[2]=5;
//}
//
//main()
//{
//	int a[2][3];
//	arr2d(a);
//	printf("%d\n", a[0][1]);
//	printf("%d\n", a[1][2]);
//	arr1d(a[0]);
//	printf("%d\n",a[0][2]);
//}


// #1. connect�Լ� �ϼ��ϱ�
//
// ���������� �߻����ؼ� �ٽ��غ���
// ���� �׳� a�� �����ͼ� ������ *p�� �־���!!

//void connect(int **p,int *a)
//{
//	*p=a;
//}
//
//main()
//{
//	int a=77;
//	int *pp;
//
//	connect(&pp,&a);//�̾ȿ� �������� �ұ�?
//	printf("%d\n", *pp);  // 77���
//}


// #2. �ܼ�â �����ϱ� �ڡڡڡڡڡڡ�
//
//int main(int argc, char **argv)
//{
//	int dx;
//	for(dx=0;dx<argc;dx++)
//	{
//		printf("%d : %s\n",dx,argv[dx]);
//	}
//	return 0;
//}
//
//

// [cmd ��ɾ�]
// d: - d�� �̵�
// mkdir test : test��� ���丮 ����
// cddir test : test��� ���丮�� ��
// dir : ���� ���丮�� ����ִ°� Ȯ��
// echo >> a.txt - ���뿡 "echo�� �����Ǿ� �ֽ��ϴ�"��� a.txt���� ����
// copy a.txt b.txt : a.txt������ �����Ͽ� b.txt����
// cls : ����� �����.

// 0 : c:\Users\bit-user\Documents\Visual Studio 2008\Projects\0412\Debug\0412.exe ���
// 0��°�� �ڱ��ڽ��̰�, 0����µȰɷ� ���� argc=1�̰ڱ���
// Alt+F7 : ������Ʈ �Ӽ� - ���� �Ӽ� - �����  - ������� - a.txt b.txt �Է��ϸ� 
// 0 : c:\Users\bit-user\Documents\Visual Studio 2008\Projects\0412\Debug\0412.exe
// 1 : a.txt
// 2 : b.txt
// ��� 
// Ctrl + O - �ϳ� ���� - debug - .exe���� ���翡�� test���� �ȿ� ����
// dir�� ���� �̸� Ȯ���ϰ�
// �տ� �ġ�� Tap ������ �ڵ����� �����̸� �Է� (��ĭ���) a.txt b.txt aaa bbbb cccc �Է�
// 0 : 0412.exe
// 1 : a.txt
// 2 : b.txt
// 3 : aaa
// 4 : bbbbb
// 5 : cccc
// ���
// ���߿� DB�� �Է��Ҷ� ���� ����Ѵ�!!!

// F5 : �ߴ������� �ٷ� ����
// F11 : �Լ��������� ����
// F10 : ���پ� ����

// #3. Calculate.exe ���� �����ϱ�
//

//int main(int argc, char **argv)
//{
//	int dx;
//	int a,b,c;
//	a=atoi(argv[2]);
//	b=atoi(argv[4]);
//
//	switch(*argv[3]) // �Ǵ� argv[4][0];
//	{
//	case '+': 
//		printf("%d + %d = %d\n", a, b, a+b);
//		break;
//	case '-':
//		printf("%d - %d = %d\n", a, b, a-b);
//		break;
//	case '*':
//		printf("%d * %d = %d\n", a, b, a*b);
//		break;
//	case '/':
//		printf("%d / %d = %d\n", a, b, a/b);
//		break;
//	case '%':
//		printf("%", a, b, a%b);
//		break;
//	default: ;
//	}
//
//
//	for(dx=0;dx<argc;dx++)
//	{
//		printf("%d : %s\n",dx,argv[dx]);
//	}
//
//	
//
//	return 0;
//}

// �����Ҷ� cmd���� 0412.exe cal 9 - 6 �̷������� �Է�          




// #4. �Լ� ������ �����ϱ�
// 

//
//int add(int a, int b){return a+b;}
//int sub(int a, int b){return a-b;}
//int mul(int a, int b){return a*b;}
//int dvd(int a, int b){return a/b;}
//
//typedef unsigned int uint;
//typedef int(*p)(int,int) mypf; // �̷��� �������!!!
//typedef int(*mypf)(int,int); // �̷��� �����ؾ��Ѵ�.�ڡڡڡڡ�
//typedef int *mysingleP; // main�������� mysingleP dp;�� �ϸ� int* dp�� ���� �ڡڡڡڡ�
//typedef int arr[3]; // main�������� arr b; �ϸ� int b[3]�� �������� �ڡڡڡڡ�
//main()
//{
//	//int (*p)(int, int);
//	//mypf p; �ε� ����� �����ϴ�
//	//p = add;
//	//printf("%d\n",p(9,2));
//
//	//p = sub;
//	//printf("%d\n",p(9,2));
//
//	//p = mul;
//	//printf("%d\n",p(9,2));
//
//	//p = dvd;
//	//printf("%d\n",p(9,2));
//
//	// �ݺ����� ����ϸ� �ǰڴ�. �װ� ���ؼ� �Լ� ������ �迭�� �������� �Ѵ�.
//	int (*fp[4])(int, int) = {add,sub,mul,dvd};
//	mypf[4] = {add,sub,mul,dve}; // �̷��� ǥ���ϸ� �ξ� �����ϰ� ǥ������ �ڡڡڡڡ�
//	int i;
//
//	for(i=0;i<4;i++)
//		printf("%d\n",fp[i](9,3));  // fp[i](9,3) �� *(fp+i)(9,3)���� �ϸ� �ȵȴ�
//								    //              (*(fp+i))(9,3)
//	
//
//}



// #5. �Լ������Ϳ� �Ű�����
//

//int add(int a,int b){return a+b;}
//int sub(int a,int b){return a-b;}
//int temp1(int(*p_func)(int , int ),int a, int b){
//	return (p_func)(a,b);
//}
//int temp2(int(**p_func)(int , int ),int a, int b){
//	return (*p_func)(a,b);
//}
//
//main()
//{
//	int a=10, b=5;
//	int (*p)(int,int);
//
//	printf("%d \n",temp1(add,a,b));
//	printf("%d \n",temp1(sub,a,b));
//
//	p=add;
//	printf("%d \n",temp1(p,a,b));
//	p=sub;
//	printf("%d \n",temp1(p,a,b));
//
//	p=add;
//	printf("%d \n",temp2(&p,a,b));
//	p=sub;
//	printf("%d \n",temp2(&p,a,b));
//  }
	// �Լ� ������ �迭�� ���� 
	// �ݺ������� �ѹ� �� �غ���!!



// #6. ĳ���� ������ �־��
//

//main()
//{
//
//	char a='A';
//	int b;
//	float c;
//	double d;
//
//	d=(double)(c=(float)(b=(int)a));  //��ȣ�� ��Ȯ�ϰ� ���� ������ �����ϵ��� �ʴ´�.�ڡڡ�
//	puts("");
//}



// #7. 5x2�� 2���� �迭�� 1���� �Լ��� �ּҰ�, 2���� ���ڿ��� �����ߴٸ�
//     (�ڡڱ׷��ٸ� 5x2 �迭�� ��� "5x2¥�� ���� ������ �迭!!)
//     �� �� 10�� 5�� ���Ͽ� ��Ģ������ �����ϴ� ���⸦ �����غ���!!

//int add(int a, int b){return a+b;}
//int sub(int a, int b){return a-b;}
//int mul(int a, int b){return a*b;}
//int dvd(int a, int b){return a/b;}
//
//main()
//{
//	int (*fp[4])(int,int) = {add,sub,mul,dvd};
//	char (*sp[4])[15] = {"Addition","Subtraction","Multiply","Divide"};
//	void* arr[5][2] = {
//		{fp[0],sp[0]},
//		{fp[1],sp[1]},
//		{fp[2],sp[2]},
//		{fp[3],sp[3]},
//	};
//
//	int whattodo;
//	int i,n;
//	puts("���� ���α׷�");
//	for(i=1;i<=4;i++)
//	{
//		printf("%d. %s\n",i,(char*)arr[i-1][1]);	
//	}
//	printf("��ȣ�� �����ϼ��� : ");
//	scanf("%d",&n);
//	
//	printf("����� : %d \n", ((int (*)(int,int))arr[n-1][0])(10,5));
//
//
//
//}

// ����� Ǯ�� �ڡڡڡڡڡڡڡڡڡ�

//main()
//{
//
//	void *p[5][2] = {add,"addition",sub,"subtraction",mul,"multiply",dvd,"divide",0,0};
//	int dx = 0, sel ;
//
//	while(p[dx][0]!=NULL)
//	{
//		printf("%d. %s\n", dx+1, (char*)p[dx][1]);
//		dx++;
//	}
//	scanf("%d", &sel);
//
//	printf("����� : %d \n", ((int (*)(int,int))p[sel-1][0])(10,5));
//}

//�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
//���� ������ ��ȣ�� ������ �����ؾ��Ѵ�
//    ((int (*) (int,int))p[sel-1][0])(��1,��2));
// ��ȣ �ϳ��� ������ �����R ��������!!!!!!!!!!!!!!!!!!!!!!!!!!!
//�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
// int�� ����ȯ�ϴ� ��� �� ��������.
//�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�

// #8-1. ��ó���� �����ϱ�
//


//#define FLAG
//
//void fn1(void)
//{
//	extern int a;
//	printf("����%d\n",a);
//}
//extern int a=100;
//main()
//{
//#ifdef FLAGa 
//	printf("Defined");
//#else 
//	printf("NoDefined");
//#endif
//	fn1();
//}


// #8-2. ��ó���� �����ϱ�
//

//void func1(void){ puts("func1");}
//void func2(void){ puts("func2");}
//void func3(void){ puts("func3");}
//void func4(void){ puts("func4");}
//
//#define call(x) func##x
//
//main()
//{
//	int dx;
//	for(dx=1;dx<5;dx++) call(dx)(); // ������ �߻��ϴ� ����?
//								    // �̷��� f4������ �ľ�����
//									// funcdx�� ���ǵ��� �ʾҽ��ϴ�!!??
//									// ������ �Ǳ����� call(dx)�� funcdx�� �ǹ��ȴܰ� !
//									// ��ó���� ��û ���� ����ƴ�.
//									// void funcdx(void) {puts("funcdx");} ��� �Լ��� ���������� �̰͸� 4�� ȣ��
//}




// #9.
// #define square(x)  ????
// //25/square(5) = 1  �� �ǵ��� square ��ũ�� �ۼ�
//
// #define PR(x) ????
// //PR(x)    x���� ����ϴ� PR ��ũ�� �Լ� �ۼ�
//
// #define ABS(x) ????
// //���밪   �� ������ִ� ��ũ�� �ۼ�
//
// #define THREE_MAX(a,b,c)  ?????
// //�ִ밪 (three_max)   3���� ���� ���� ū ���� ����ϴ� ��ũ�� �ۼ�
//
// #define SWAP(x,y) ?????

#define SQUARE(x) x*x
#define PR(x) printf("%d\n",x)
#define ABS(x) (x>=0)?x:-x
#define THREE_MAX(a,b,c) (((a>=b)?a:b) >= c ? ((a>=b)?a:b) : c)
#define SWAP(x,y) {x=x^y; y=x^y; x=x^y;}
#define FLAG 0

main()
{
	int a = 90, b = 60;
	int sq=20;

	PR(SQUARE(5));
	PR(ABS((-99)));				// -99���� ��ȣ �ȳ����� �����ڷ� �νĵǱ� ������ �����߻�
	PR(THREE_MAX(-30,90,60));
	//SWAP(a,b);					// SWAP�� define�Ҷ� {}�ȿ��� ������ ������ ������ ��ġ������ �����߻� !! 
									// �ذ�å�� define�ȿ� {}�� �ִ¹��
	
	if(sq>0) SWAP(a,b);
	
	else SWAP(a,sq);	// ����� Ư�������ڡڡڡڡڡڡ� �� �������߻��ϴ°�?

	printf("%d %d\n",a,b);
}