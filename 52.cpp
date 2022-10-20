#include<stdio.h>
int main()
{
	int s[10],i;
	for(i=0;i<=9;i++)
	s[i]=i;
	for(i=9;i>=0;i--)
	printf("%d",s[i]);
	printf("\n");
	return 0;
}
