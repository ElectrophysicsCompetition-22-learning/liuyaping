#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,i;
	printf("输出的数为");
	scanf("%d",&a);
	b=(int)sqrt(a);
	for(i=2;i<=b;i++)
	if(a%i==0) break;
    if(i>b)
    printf("%d prinme",a);
    else printf("%d not prinme",a);
    return 0;
	
}
