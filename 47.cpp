#include<stdio.h>
int main()
{
	int i,j,n=0;
	float ave,sum=0;
	printf("���ѧ���ɼ�");
	for(j=1;j<6;j++)
	{
		scanf("%d",&i);
		if(i<60)
		{
		printf("Ϊ������");continue;
	    }
	    sum+=i;
	    n=n+1;
		 ave=sum/n;
		 printf("%d,%-7.2f\n",i,ave);
	} 
}

