#include<stdio.h>
int main()
{
	float a[3][4]={{45,46,47,42},{48,43,46,46},{44,48,49,45}};
	int i,j;
	float sum,average;
	for(j=0;j<4;j++)
	{
		sum=0;
		for(i=0;i<3;i++)
		{
	    sum=sum+a[i][j];
		average=sum/3;}
		printf("%f\n",average);
	}
}
