#include<stdio.h>
int main()
{
	long int i,f1=1,f2=1;
	int b;
	for(i=1;i<=20;i++)
	{
		printf("%12ld,%12ld",f1,f2);
		if(b%4==0)
		printf("\n");
		f1+=f2;
		f2+=f1;
	}
}
