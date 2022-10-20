#include<stdio.h>
int main()
{
	int i,num=0;
	for(i=1;i<=100;i++)
	{
	printf("%-5d",i);
	num++;
	if(num==6)
	{
		printf("\n");
		num=0;
	}
	}
}
