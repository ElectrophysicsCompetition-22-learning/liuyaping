#include<stdio.h>
int main()
{
	char string[81];
	int i,num=0,word=0;
	gets(string);
	char c;
	for(i=0;(c=string[i])!='\0';i++)
	if(c==' ')
	word=0;
	else if(word==0)
	{word=1;num++;
	}
	printf("%d",num);
	return 0;
}
