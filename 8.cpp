#include<stdio.h>
int main()
{
	int a,b,c;
	a=56;
	b+=a+=(a-=a*a);
	c=b++;
	printf("%d,%d,%d",a,b,c);
	return 0;
}
