#include <stdio.h>

struct test1{
	char a;
	short b;
	int c;
};

struct test2{
	char a;
	char b;
	char c;
	short d;
	double e;
};


int main()
{
	struct test1 A;
	struct test2 B;
	printf("char = %p , short = %p, int = %p \n", &A.a,&A.b,&A.c);
	printf("\nchar1 = %p, char2 = %p, char3 = %p, \nshort = %p, double = %p\n",&B.a,&B.b,&B.c,&B.d,&B.e);

	return 0;

}
