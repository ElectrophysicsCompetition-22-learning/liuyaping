#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,s,area;
	printf("���߱߳�:");
	scanf("%lf,%lf,%lf",&a,&b,&c);
	s=(a+b+c)/2.0;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("���Ϊ%lf\n",area);
	return 0;
}
