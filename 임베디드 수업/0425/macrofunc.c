#define MUL1(x,y) (x*y)
#define MUL2(x,y) ((x)*(y)) 

#include <stdio.h>

int main()
{
	int a=1,b=2,c=3,d=4;

	printf("1+2 * 3+4=%d\n",MUL1(a+b,c+d));
	printf("1+2 * 3+4=%d\n",MUL2(a+b,c+d));	






	return 0;
}
