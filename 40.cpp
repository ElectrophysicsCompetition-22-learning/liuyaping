#include<stdio.h>
int main()
{
	int n,m,sum=0,i=1;
	do
	{
		printf("¾è¿îÎª");
		scanf("%d",&m);
		sum+=m;
		i++; 
	}while(sum<=10000);
	printf("%d\n",sum);
	return 0;
	
}
