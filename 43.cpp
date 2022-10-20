#include<stdio.h>
int main()
{
	double b=1.30756e9,r=0.01;
	int y;
	for(y=2006;b<1.5e9;y++)
	b=b*(1+r);
    printf("%d,%e\n",y,b);
    return 0;
}
