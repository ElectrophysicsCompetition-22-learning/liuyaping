#include<stdio.h>
int main()
{
	int x,y,z;
	scanf("%d",&x);
	y=x/100;
	z=(x-y*100)/10;
	printf("��λ����%d\n",y);
	printf("ʮλ����%d\n",z);
	printf("��λ����%d\n",x%10);
	return 0;
}
