#include<stdio.h>
int main()
{
	char ch;
	printf("s");
	scanf("%c",&ch);
	if(ch>='A'&&ch<='Z')
	printf("为大写");
	if(ch>='a'&&ch<='z')
	printf("为小写");
	else
	printf("为其他");
	return 0; 
}
