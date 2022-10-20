#include<stdio.h>
int main()
{
	int a=1,n,scr,sum=0,ave;
	printf("请输入评委的的人数");
	scanf("%d",&n);
	while(a<=n)
	{
		printf("参赛评分");
		 scanf("%d",&scr);
		 sum+=scr;
		a++;
	} 
	ave=sum/n;
	printf("%d\n",ave);
	return 0;
}
