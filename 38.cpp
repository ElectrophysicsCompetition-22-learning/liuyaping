#include<stdio.h>
int main()
{
	int a=1,n,scr,sum=0,ave;
	printf("��������ί�ĵ�����");
	scanf("%d",&n);
	while(a<=n)
	{
		printf("��������");
		 scanf("%d",&scr);
		 sum+=scr;
		a++;
	} 
	ave=sum/n;
	printf("%d\n",ave);
	return 0;
}
