#include<stdio.h>
int main()
{
	char x,y,z;
	printf("输入的大写字母为");
	x=getchar();
	y=getchar();
	z=getchar();
	printf("%c,%c,%c\n",x+32,y+32,z+32);
	return 0;
}
