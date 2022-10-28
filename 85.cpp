#include<stdio.h>
int main()
{
	int a[10];
	int i,j;
    for(i=0;i<=9;i++)
    {
    	a[i]=i;
	}
	for(i=9;i>=0;i--)
	printf("%d",a[i]);
}
