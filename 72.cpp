#include<stdio.h>
int main()
{
	char ch;
	printf("s");
	scanf("%c",&ch);
	if(ch>='A'&&ch<='Z')
	printf("Ϊ��д");
	if(ch>='a'&&ch<='z')
	printf("ΪСд");
	else
	printf("Ϊ����");
	return 0; 
}
