#include<stdio.h>
int main()
{
	int a,b;
	printf("Äê·İÎª");
	for(a=1;a<=3000;a++)
	{
		if((a%4==0&&a%100!=0)||(a%400==0))
	{
		printf("%-5d",a);
		b++;
	}
	if(b==6)
	{
		printf("\n");
		b=0;
	}
		}
}
