#include<stdio.h>
int main()
{
	int a,b,c,d,f,g;
	scanf("%d,%d,%d",&a,&b,&c);
	if(a>b) d=a,a=c,c=d;
	if(a>c) f=a,a=c,c=f;
	if(b>c) g=b,b=c,c=g;
	printf("%d,%d,%d\n",a,b,c);
	return 0;
	}
