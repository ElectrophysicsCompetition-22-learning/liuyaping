#include<stdio.h>
int main()
{
	int x,y,z;
	scanf("%d",&x);
	y=x/100;
	z=(x-y*100)/10;
	printf("百位数是%d\n",y);
	printf("十位数是%d\n",z);
	printf("个位数是%d\n",x%10);
	return 0;
}
