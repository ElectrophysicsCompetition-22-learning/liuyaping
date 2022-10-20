#include<stdio.h>
int main()
{
	int i,j=0;
	for(i=1;i<=100;i++)
	{
		printf("%-5d",i);
		j++;
		if(j==6)
		{
			printf("\n");
			j=0;
		}
		}
}
