#include<stdio.h>
int main (void)
{
	int i=8,j=2,k;
	int *p1=&i;
	int *p2=&j;
	printf("%d\n",p1);
	printf("%d\n",p2);
    //����ָ�뿪ʼ���ӣ�ÿ�����������ݱ������������ڴ�����ռ���ֽڣ� 
	printf("%d\n",p1);
	k=*(p2+1);//*�ŵ����ȼ���+�Ÿߣ���ˣ���Ҫ�����ţ��� 
	printf("%d",k);
	return 0;
 }

