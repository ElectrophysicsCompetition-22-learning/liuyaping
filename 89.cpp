#include<stdio.h>
int main()
{
	int a[10];
	int i,j,t;
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	for(j=0;j<9;j++)
	for(i=0;i<9-j;i++)
	if(a[i+1]<a[i])
	{t=a[i+1];a[i+1]=a[i];a[i]=t;
	}
	for(i=0;i<10;i++)
	printf("%d",a[i]);
}
