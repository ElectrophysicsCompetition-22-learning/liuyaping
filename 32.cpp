#include<stdio.h>
int main()
{
	char ch;
	scanf("%c",&ch);
	if(ch>='A'&&ch<='Z')
	printf("Ϊ��д��ĸ");
	else if(ch>='a'&&ch<='z')
	printf("ΪСд��ĸ");
	else printf("Ϊ�����ַ�\n");
	return 0;
}
