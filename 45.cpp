#include<stdio.h>
int main()
{
	int i;
	for(i=100;i>=0;i--)
	if(i%7==0)
	break;
	printf("%d\n",i);
	return 0;
	
}
