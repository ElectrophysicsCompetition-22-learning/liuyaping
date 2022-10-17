#include<stdio.h>
int main()
{
	int score;
	scanf("%d",&score);
	switch((int)score/10);
	{
		case 10:
        case 9:printf("A\n");break;
	    default:printf("error\n");
	}
}
