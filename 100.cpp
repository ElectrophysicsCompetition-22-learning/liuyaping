#include<stdio.h>
int main()
{
	float s[5][5]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16,},{17,18,19,20}};
	int i,j,x;
	float sum,t;
	for(i=0;i<5;i++)
	{sum=0;
	for(j=0;j<4;j++)
	{
	sum=sum+s[i][j];
	s[i][5]=sum/4;}
	}
	for(i=0;i<5;i++)
	for(x=0;x<5-i;x++)
    if(s[i][5]>s[i+1][5])
	{t=s[i][5];s[i+1][5]=s[i][5];s[i+1][5]=t;
	 } 
	for(i=0;i<5;i++)
	printf("%f\n",s[i][5]);
}
