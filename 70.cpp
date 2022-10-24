#include<stdio.h>
#include<math.h>
int main()
{
	float x1,y1,x2,y2;
	float a;
	scanf("%f,%f,%f,%f",&x1,&y1,&x2,&y2);
	a=sqrt(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	printf("¾àÀëÎª£º%f\n",a);
	return 0;
}
