#include<stdio.h>
int main()
{
	char ch;
	ch=getchar();
	for(ch=getchar();;)
	{
	    if((ch<='Z')&&(ch>='A')||(ch<='z')&&(ch>='a'))
	    printf("Ϊ��ĸ",ch);	
		else if((ch>='0')&&(ch<='9'))
		printf("Ϊ����",ch);
		else if(ch='#') break;
		else printf("Ϊ����",ch); 
    printf("\n");
}
	return 0;
}
