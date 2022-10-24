#include<stdio.h>
int main()
{
	int a,b;
	do
	{
	printf("输入年份和月份");
	scanf("%d,%d",&a,&b);
	switch(b)
	{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			printf("为31天");break;
			case 4:case 6:case 9:case 11:
				printf("为30天");break;
				case 2:
				if((a%4==0&&a%100!=0)||a%400==0)
				printf("为29天");
				else printf("为28天");break; 
	            default:printf("没有此月份\n"); 
	 } 
	}	while(b!=0);
}

