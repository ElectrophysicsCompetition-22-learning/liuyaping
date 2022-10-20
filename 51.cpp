#include<stdio.h>
int main()
{
	char ch;
	while((ch=getchar())!='\n')
	{
    if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
    {
    	ch=ch+4;
    	if((ch>'Z'&&ch<='Z'+4)||(ch>='z'&&ch<='z=4'))
    	ch-=26;
	}
	printf("%c",ch);
}
return 0;
}
