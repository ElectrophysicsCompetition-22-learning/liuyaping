#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d",&a);
	b=a/10;
	switch(b)
	{
		case 10:
		case 9:printf("ΪA�ȼ�");break;
		case 8:printf("ΪB�ȼ�");break;
		case 7:
		case 6:printf("ΪC�ȼ�");break;
		default:printf("ΪD�ȼ�\n");
	}
	return 0;
}
