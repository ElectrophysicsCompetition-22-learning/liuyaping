#include<stdio.h>
int main()
{
	int i,j;
	printf("���žų˷���\n");
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		printf("%d*%d=%-4d",i,j,i*j);
	}
	 printf("\n");
	 return 0;	 
}