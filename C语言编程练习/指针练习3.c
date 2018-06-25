#include<stdio.h>
int main (void)
{
	int i=8;
	int *p=&i;//p其实此时所代表的就是i的地址； 
	printf("%p\n",p);
	printf("%d\n",*p);//此时 *p代表的就是i的值；*是一个单目运算符，用来访问指针的值所表示的地址上的变量！！！ 另外，数组变量是特殊的指针。 
	
	*p=*p+1;
	printf("%d\n",i);
	

	return 0;
 }

