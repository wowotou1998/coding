#include<stdio.h>
long x,f;
 
long function1(long a);
int main ()
{
printf("������һ����\n");

scanf("%d",&x);

f=function1(x);

printf("%u ����� %u\n",x,f);

	return 0;
 }
 
long function1(long a)
{
	if (a==1)
	return 1;
	else
	{
	a=a*function1(a-1);
	return a;
    }
}
long function2() 
