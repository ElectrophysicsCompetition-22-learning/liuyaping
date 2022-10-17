#include<stdio.h>
int main()
{
	char ch1,ch2;
	int n1,n2;
	ch1=getchar();
	ch2=getchar();
	n1=ch1='0';
	n2=n1*10+(ch2-'0');
	printf("%d\n",n2);
	return 0;
}
