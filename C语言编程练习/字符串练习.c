#include <stdio.h>
#include <stdlib.h> 
int i=5,count;
char string1[10]={'h','l','l','o','w','o','r','l','d'};
char string2[12]="hello,world";//����д���ͱȽϱ����
char string3[]="lalallalal";//û��ָ�����ȣ��������Զ�����
char *p=string1 ;//һ����Ϊp��ָ��ָ���ַ����ĵ�һ���ַ� 
char string3[] ;//����һ���ȼ� char string[]==char *p=string
 
int *p1=&i;
int main (void)
{
	printf("%d\n",p);
	char *p2;
	p2=(char*)malloc(1*sizeof(char));
	if (p2==NULL)
	{
		puts("memory allocation error");	
    }
    for (*p2==60;*p<91;(*p)++)
    {
    	printf("%c\n",(*p));
	}


  return 0;
}

