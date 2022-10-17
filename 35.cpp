#include<stdio.h>
int main()
{
	int a,b,c;
	printf("税前收入为"); 
	scanf("%d",&a);
	if(a<=5000) b=0;
	else if(a<=8000) b=(a-5000)*0.03;
	else if(a<=17000) b=90+(a-8000)*0.1;
	else if(a<=30000) b=990+(a-17000)*0.2;
	c=a-b;
	printf("个人所得税为%d,个人实际收入%d\n",b,c);
	return 0;
}
