#include <stdio.h>

double square(double x) {
	return (double)(x*x);
}

double add(double x, double y){
	return (square(x)+square(y));
}



int main()
{
	double x=2;
	double y=3;
	double result;

	result = add(x,y);

	printf("%lf\n",result);
	return 0;
}
