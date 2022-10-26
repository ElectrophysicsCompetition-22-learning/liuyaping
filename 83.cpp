#include<stdio.h>
int main()
{
	int i,sum=2;
	int a[20]={1,1};
	for(i=0;i<18;i++)
	{
		a[i+2]=a[i+1]+a[i];
		printf("%d",a[i+2]);
	}
	return 0;
}
