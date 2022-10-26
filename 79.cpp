#include<stdio.h>
int main()
{
	float i,j=0;
	do
	{scanf("%f",&i);
	j=j+i;
	}while(j<=10000);
	printf("sum=%f\n",j);
	return 0;
}
