#include<stdio.h>
void f(int *p);
void g(int k);

int main (void)
{
int i=6;
printf("&i=%p\n",&i);//*��һ����Ŀ���������������ָ���ֵ����ʾ�ĵ�ַ�ϵı���������
f(&i);
g(i);

	return 0;
 }
 void f(int *p)
{
	printf("p=%p\n",p);
	printf("*p=%p\n",*p);
	*p=6;//*��һ����Ŀ���������������ָ���ֵ����ʾ�ĵ�ַ�ϵı���������
	
}
void g(int k)
{
	printf("k=%d\n",k);
	
}
