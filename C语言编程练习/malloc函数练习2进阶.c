# include <stdio.h>
#include <stdlib.h>
int main (void)
{
	/*��Ҫ50��int����ڴ��*/
	
	int*p1;//����ָ�� 
	
	p1=(int*)malloc(50*(sizeof(int)));//�����ڴ� 
	
	*p1=15893;//���ڴ���д���� 
	
	printf("%d\n",(*p1));
	
	/*��Ҫ100��char����ڴ��*/
	
	char*p2;
	p2=(char*)malloc(100*(sizeof(char))) ;
	
	/*��Ҫ500��float����ڴ��*/
	
	float *p3;
	p3=(float*)malloc(980000000000*(sizeof(float)));
	if(p3==NULL)//�ж��ڴ��Ƿ����ɹ� 
	{
	   printf("�ڴ���䲻�ɹ�");
	}	
	 else printf("�ڴ����ɹ�") ;


  return 0;
}

