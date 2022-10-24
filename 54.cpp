#include<stdio.h>
int main()
{
	char ch;
    do
	{
		ch=getchar();
	    if((ch<='Z')&&(ch>='A')||(ch<='z')&&(ch>='a'))
	    printf("为字母");	
		else if((ch>='0')&&(ch<='9'))
		printf("为数字");
		else printf("为其他"); 
	}
	while(ch!='#');
	return 0;
}
