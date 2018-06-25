#include<stdio.h>
float x=3.5,y=65.11,z;
float half_of(float k);
int main (void)
{
	z=half_of(x);
	printf("the value of z=%f\n",z);
	
	z=half_of(y);
	printf("the value of z=%f\n",z);
	
	return 0;
 }

float half_of(float k)
{
	return(k/2);
}
