#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d",&a);
	b=a/10;
	switch(b)
	{
		case 10:
		case 9:printf("为A等级");break;
		case 8:printf("为B等级");break;
		case 7:
		case 6:printf("为C等级");break;
		default:printf("为D等级\n");
	}
	return 0;
}
