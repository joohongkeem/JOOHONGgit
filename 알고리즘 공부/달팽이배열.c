#include <stdio.h>


int main()
{
        int n,i=0,j=-1,value=1,k,dir,t;
		int arr[51][51]={0};

        printf("달팽이 배열 size ?");
        scanf("%d",&n);
        k=n;
        dir=-1;

		

		for(k=n;k>=0;)
		{
			dir *= -1;
			t=0;
			for(j=j+dir;t<k;j=j+dir)
			{
				arr[i][j]=value++;
				t++;
			}
			k--;
			j-=dir;
			t=0;
			for(i=i+dir;t<k;i=i+dir)
			{
				arr[i][j]=value++;
				t++;
			}
			i-=dir;
		}
   

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) printf("%5d",arr[i][j]);
			puts("");
		}
		     return 0;
}
