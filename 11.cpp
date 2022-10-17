#include<stdio.h>
int main()
{
	char a;
	printf("请输入一个小写字母：");
	a=getchar();
	printf("对应的大写字母；%c\n",a-32);
	return 0; 
}
