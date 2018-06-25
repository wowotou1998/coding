#include<stdio.h>
void f(int *p);
void g(int k);

int main (void)
{
int i=6;
printf("&i=%p\n",&i);//*是一个单目运算符，用来访问指针的值所表示的地址上的变量！！！
f(&i);
g(i);

	return 0;
 }
 void f(int *p)
{
	printf("p=%p\n",p);
	printf("*p=%p\n",*p);
	*p=6;//*是一个单目运算符，用来访问指针的值所表示的地址上的变量！！！
	
}
void g(int k)
{
	printf("k=%d\n",k);
	
}
