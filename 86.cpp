#include<stdio.h>
int main()
{
	int f[20]={1,1};
	int i,j;
	for(i=0;i<20;i++)
	{f[i+2]=f[i]+f[i+1];
	}
	for(i=0;i<20;i++)
	
	printf("%d",f[i]);
	printf("\n");
	return 0;
}
