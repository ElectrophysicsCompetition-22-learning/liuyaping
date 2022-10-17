#include<stdio.h>
enum Sex
{
	MALE,
	FEMALE,
	SECRET,
};
int main()
{
	enum Sex a=FEMALE;
	printf("%d\n",a);
	return 0;
}
