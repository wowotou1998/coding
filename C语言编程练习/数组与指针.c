#include<stdio.h>
int main (void)
{
	int array[10];
	int*p1_array,*p2_array;
	p1_array=array;//此时，array是数组的名称，也表示数组第一个元素的地址
	p2_array=&array[0];
	printf("p1_array=%d\n",p1_array); 
	printf("p2_array=%d\n",p2_array); 

	return 0;
 }

