#include<stdio.h>
int main()
{
	int f[20]={1,1};
	int i;
	for(i=2;i<20;i++)
	f[i]=f[i-1]+f[i-2];
	for(i=0;i<20;i++)
	{
	if(i%5==0)
	printf("\n");
	printf("%12d",f[i]);
	}
	printf("\n");
	return 0;
}
