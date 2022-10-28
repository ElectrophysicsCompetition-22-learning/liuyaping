#include<stdio.h>
int main()
{
	float a[3][11];
	int i,j;
	float sum=0,d;
	for(j=0;j<3;j++)
	{
	for(i=0;i<10;i++)
    {
		scanf("%f",a[j][11]);
		sum=sum+a[0][i];
		a[j][11]=sum/10.0;}
		if(a[0][11]>a[1][11])
		d=a[0][11];
		else d=a[1][11];
		if(a[2][11]>d)
		d=a[2][11];}
	    printf("%f",d);	
	
}
