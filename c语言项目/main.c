#include<stdio.h>
//�����ⲿ�������ⲿ���� 
extern int p(void);   //ָ��p����Ϊ�����ļ���ĺ��� 
extern int i;   //ָ��iΪ�����ļ���ĺ��� ������������ extern int i = 8���������ض����� 
extern unsigned char key;//ָ��keyΪ�����ļ���ĺ��� 
int main() {   
    p();   
    printf("%c",key);
    system("pause");       
    return 0;        
}  

