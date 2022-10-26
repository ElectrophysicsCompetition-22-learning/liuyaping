#include<stdio.h>
int main()
{
	double p=13.54,r=0.01;
	int year;
	for(year=2012;year<3012;year++)
	{
		p=p*(1+r);
	}
	printf("%d,%f\n",year,p);
}
