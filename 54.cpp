#include<stdio.h>
int main()
{
	char ch;
    do
	{
		ch=getchar();
	    if((ch<='Z')&&(ch>='A')||(ch<='z')&&(ch>='a'))
	    printf("Ϊ��ĸ");	
		else if((ch>='0')&&(ch<='9'))
		printf("Ϊ����");
		else printf("Ϊ����"); 
	}
	while(ch!='#');
	return 0;
}
