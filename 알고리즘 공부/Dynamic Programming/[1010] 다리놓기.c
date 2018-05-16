#include <stdio.h>

int Combi(int M, int N)
{
	int i;
	long long int x=1,y=1;
	if(N>M/2) N=M-N;
	if(N==0) return 1;
	if(N==1) return M;
	
	for(i=1; i<=N;i++)
	{
		x*= M-i+1;
		y*= N-i+1;
	}
	x /= y;
	return x;
}

int main()
{
	int T,N,M,i;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d",&N,&M);
		printf("%d\n",Combi(M,N));
	}
}