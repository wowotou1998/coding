#include<stdio.h>
#define MAX 10
int array[MAX],count;
int largest(int num_array[],int length);

int main (void)
{
	for (count=0;count<MAX;count++)
	{
	printf("������һ������\n");
	scanf("%d",&array[count]);
    }   
    printf("�����Ϊ��%d\n",largest(array,MAX))��//���������ŵ���������һ��ָ�룬��ʾ�����һ��Ԫ�صĵ�ַ������array��*array[0]�ȼۣ� 
	return 0;
 }
 
 
int largest(int num_array[],int length)//���鴫�ݸ������ķ���һ���Ǵ���������ֵ��ָ���һ��Ԫ�ص�ָ���ָ��������Ԫ����Ŀ�������� 
{
	int count,biggest=-1200;
	for (count=0;count<length;count++)
	{
		if (num_array[count]>biggest)
		biggest=num_array[count];
	}
	return biggest;
}
