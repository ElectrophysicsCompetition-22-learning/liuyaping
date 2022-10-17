#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,s,area;
	printf("三边边长:");
	scanf("%lf,%lf,%lf",&a,&b,&c);
	s=(a+b+c)/2.0;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("面积为%lf\n",area);
	return 0;
}
