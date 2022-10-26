#include<stdio.h>
int main()
{
	float score,sum=0,average;
	int i,n;
	for(i=1;i<=30;i++)
	{
		scanf("%f",&score);
		if(score<0) break;
	    sum=sum+score;
	}
	n=i-1;
	average=sum/n;
	printf("%f",average);
	return 0;
}
