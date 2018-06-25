#include<stdio.h>
#define MAX 10
int array[MAX],count;
int largest(int num_array[],int length);

int main (void)
{
	for (count=0;count<MAX;count++)
	{
	printf("请输入一个数字\n");
	scanf("%d",&array[count]);
    }   
    printf("最大数为：%d\n",largest(array,MAX))；//不带方括号的数组名是一个指针，表示数组第一个元素的地址，例如array与*array[0]等价； 
	return 0;
 }
 
 
int largest(int num_array[],int length)//数组传递给函数的方法一般是传递两个数值，指向第一个元素的指针和指向数组中元素数目的整数； 
{
	int count,biggest=-1200;
	for (count=0;count<length;count++)
	{
		if (num_array[count]>biggest)
		biggest=num_array[count];
	}
	return biggest;
}
