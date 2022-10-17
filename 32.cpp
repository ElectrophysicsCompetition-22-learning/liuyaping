#include<stdio.h>
int main()
{
	char ch;
	scanf("%c",&ch);
	if(ch>='A'&&ch<='Z')
	printf("为大写字母");
	else if(ch>='a'&&ch<='z')
	printf("为小写字母");
	else printf("为其它字符\n");
	return 0;
}
