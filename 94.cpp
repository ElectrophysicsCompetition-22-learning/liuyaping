#include<stdio.h>
int main()
{
	int a[10]={1,3,2,4,6,8,7,9,0,5};
	int i,num,t;
	for(i=0;i<10;i++)
	if(a[i]>a[i+1])
	{t=a[i];a[i]=a[i+1];a[i+1]=t;
	num=i;}
	printf("%d,%d",a[9],num);
	
}
