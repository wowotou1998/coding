#include<stdio.h>
int main (void)
{
	int array[10];
	int*p1_array,*p2_array;
	p1_array=array;//��ʱ��array����������ƣ�Ҳ��ʾ�����һ��Ԫ�صĵ�ַ
	p2_array=&array[0];
	printf("p1_array=%d\n",p1_array); 
	printf("p2_array=%d\n",p2_array); 

	return 0;
 }

