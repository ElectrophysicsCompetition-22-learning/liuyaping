#include<stdio.h>
#include<string.h>
int main()
{
	char string[20];
	char str[3][20];
	int i;
	for(i=0;i<3;i++)
{
		gets(str[i]);
	if(strcmp(str[i+1],str[i])>0)
	strcpy(string,str[i+1]);
	else strcpy(string,str[i]);}
	printf("%s",string);
	return 0;
}
