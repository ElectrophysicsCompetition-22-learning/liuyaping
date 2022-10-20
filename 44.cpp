#include<stdio.h>
int main()
{
	int i,j;
	printf("Âú¾Å¾Å³Ë·¨±í\n");
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		printf("%d*%d=%-4d",i,j,i*j);
	}
	 printf("\n");
	 return 0;	 
}
