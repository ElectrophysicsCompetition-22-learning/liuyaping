#include<stdio.h>
int main()
{
	int a,b;
	do
	{
	printf("������ݺ��·�");
	scanf("%d,%d",&a,&b);
	switch(b)
	{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			printf("Ϊ31��");break;
			case 4:case 6:case 9:case 11:
				printf("Ϊ30��");break;
				case 2:
				if((a%4==0&&a%100!=0)||a%400==0)
				printf("Ϊ29��");
				else printf("Ϊ28��");break; 
	            default:printf("û�д��·�\n"); 
	 } 
	}	while(b!=0);
}

