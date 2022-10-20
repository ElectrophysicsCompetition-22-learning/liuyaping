#include<stdio.h>
int main()
{
	int i,a,sum;
	double b;
	for(i=1;i<=64;i++)
	{
		a=i+1;
		sum+=i;
	}
	b=sum/1.42e+008;
	printf("%fn",b);
	return 0;
}
