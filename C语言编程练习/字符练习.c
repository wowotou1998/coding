#include <stdio.h>
#define a 'a'//������ �������ɽ������ַ�����ת��Ϊ��Ӧ��ASCII�� 

int main (void)
{
	char c1='c';//���ʱ�� char�ı���Ӧ����'c'������ʽ�� ����'sss'����ַ��Ǵ���� 
	char c2=90; 
	unsigned char mychar;
	printf("%c\n",c1);
	printf("%d\n",c1);
	for (mychar=1;mychar<4;mychar++)
	{
		printf("%d \t is \t %c \t \n",mychar,mychar);//\t���Ʊ�� 
		
	 } 
	/*printf("%c\n",a);//%c��ʾ����ַ� 
    printf("%d\n",a);//%d��ʾ���ʮ���Ƶ��� 
    */
    
  return 0;
}


