#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d,%d",&a,&b);
	c=a+b;
	d=a/b;
	e=a%b;
	f=c/2;
	printf("和为：%d,商为：%d，余数为：%d,平均数为：%d\n",c,d,e,f);
	return 0;
}
