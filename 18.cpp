#include<stdio.h>
int main()
{
	int a=1,b=2,c;
	c=a;
	a=b;
	b=c;
	printf("%d,%d",a,b);
	return 0;
}
