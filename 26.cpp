#include<stdio.h>
int main()
{
	int c;
	double p,w,s,d,f;
	printf("输出单价、路程和距离：");
	scanf("%lf,%lf,%lf",&p,&w,&s);
	if(s>=3000) c=12;
	else c=s/250;
	switch(c)
	{
		case 0:d=0;break;
		case 1:d=1;break;
		case 2:
		case 3:d=4;break;
		case 5:
		case 6:
		case 7:d=5;break;
		case 8:
		case 9:
		case 10:
		case 11:d=6;break;
		}
		f=p*w*s*(1-d);
		printf("运费为%lf\n",f);
		return 0;
}
