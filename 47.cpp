#include<stdio.h>
int main()
{
	int i,j,n=0;
	float ave,sum=0;
	printf("输出学生成绩");
	for(j=1;j<6;j++)
	{
		scanf("%d",&i);
		if(i<60)
		{
		printf("为不及格");continue;
	    }
	    sum+=i;
	    n=n+1;
		 ave=sum/n;
		 printf("%d,%-7.2f\n",i,ave);
	} 
}

