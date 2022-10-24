#include<stdio.h>
int main()
{
	char ch;
	ch=getchar();
	for(ch=getchar();;)
	{
	    if((ch<='Z')&&(ch>='A')||(ch<='z')&&(ch>='a'))
	    printf("为字母",ch);	
		else if((ch>='0')&&(ch<='9'))
		printf("为数字",ch);
		else if(ch='#') break;
		else printf("为其他",ch); 
    printf("\n");
}
	return 0;
}
