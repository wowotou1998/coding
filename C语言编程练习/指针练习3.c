#include<stdio.h>
int main (void)
{
	int i=8;
	int *p=&i;//p��ʵ��ʱ������ľ���i�ĵ�ַ�� 
	printf("%p\n",p);
	printf("%d\n",*p);//��ʱ *p����ľ���i��ֵ��*��һ����Ŀ���������������ָ���ֵ����ʾ�ĵ�ַ�ϵı��������� ���⣬��������������ָ�롣 
	
	*p=*p+1;
	printf("%d\n",i);
	

	return 0;
 }

