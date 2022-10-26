#include<stdio.h>
int main()
{
	int x,y;
	scanf("%d",&x);
	if(y%4==0)
	{
		if(y%100==0)
	    {
	    	if(y%400==0)
	    	x=1;
	    	else x=0;
		}
		else x=1;
	}
	else x=0;
	if(x)
	printf("为闰年",x);
	else printf("不为闰年\n",x);
	return 0;
}
