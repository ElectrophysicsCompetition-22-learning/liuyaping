#include<stdio.h>
int main()
{
	int x;
	printf("学生的成绩为");
	scanf("%d",&x);
	if(x<60)
	printf("成绩为不及格");
	else if(x<70) 
	printf("成绩为及格");
	else if(x>70);
	printf("成绩为优秀\n"); 
	return 0;
}
