#include<stdio.h>
int main()
{
	int a[10];
	int t,i,j,c=0;
	printf("输出的数为");
	for(i=0;i<10;i++)
	scanf("%d",&a[i]) ;
	printf("\n");
	for(j=0;j<9;j++)
	for(i=0;i<9-j;i++)
	if(a[i]>a[i+1])
	{
		t=a[i];
		a[i]=a[i+1];
		a[i+1]=t;
	}
	    printf("\n");
	    for(i=0;i<10;i++)
	    {
		printf("%-5d",a[i]);
		c++;
		if(c==5); 
	{
		printf("\n");
		c=0;
	}
	}
}

