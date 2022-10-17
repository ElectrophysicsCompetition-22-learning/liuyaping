#include<stdio.h>
#include<math.h>
int main()
{
	int a,b;
	float c,m;
	a=324500;
	b=3245;
	c=0.008;
	m=(log10(b)-log10(b-a*c))/log10(1+c);
	printf("%f\n",m);
	printf("%f\n",m*a);
	return 0;
}
