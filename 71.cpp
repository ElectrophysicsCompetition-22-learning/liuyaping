#include<stdio.h>
int main()
{
	int max(int x,int y);
	int a,b,c;
	printf("������������");
	scanf("%d,%d",&a,&b);
	c=max(a,b);
	printf("%d\n",c);
}
	int max(int x,int y)
	{
		int z;
		if(x>y)
		z=x;
		else z=y;
		return(z);
	
	}
