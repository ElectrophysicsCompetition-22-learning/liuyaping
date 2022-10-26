#include<stdio.h>
int main()
{
	double i,j=1,t=1,v;
	for(i=1;i<64;i++)
	{
		j=j*2;
		t=t+j;
	}
		v=t/1.42e8;
	printf("%e",v);
}
