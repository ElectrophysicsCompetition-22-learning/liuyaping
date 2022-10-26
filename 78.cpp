#include<stdio.h>
int main()
{
	int i,j=0;
	for(i=1;i<=100;i++)
	{
		j=i+j;
	}
	    printf("%d\n",j);
	
	return 0;
}
