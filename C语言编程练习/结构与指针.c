# include <stdio.h>
int cost=1,interest=2; 
int main (void)
{
	struct date{
		int *value;
		int *rate;
	} first ; 
	first.value=&cost;/* ���ʽ*first.valueָ���Ǳ���cost��ֵ */
	first.rate=&interest;/* ����ͬ��  */
	
	 
   //charָ����Щ�ر� 
   
   char *p_message;
   p_message="klalalalal";
   
   printf("%d\n%c",p_message,(*p_message));/* %c ��ʾ����ַ������԰���������ְ���ASCII��ת��Ϊ��Ӧ���ַ�
                                              %s ��ʾ����ַ����е��ַ�ֱ���ַ����еĿ��ַ������ַ���'\0'��ʾ��*/   
             
   struct msg{
   	char *p1;
   	char *p2;
   	
   }myptrs; 
   myptrs.p1="sdjhsakj";
   myptrs.p2="hasdgqquw";
   
   //ָ��ṹ��ָ��
   struct part{
   	short number;
   	char name[10];
   	
   } third; 
    struct part *p_part;//����һ��ָ�� ������һ��ʵ����Ҳ����˵������һ���ṹָ�룬����û��ָ���κνṹ
	p_part=&third;
	
	//����ָ�룬���ǿ��ԱȽϱ�ݵĶ�ȡ�ṹ��Ա����ʽ������
	/*���p_str ��ָ��ṹstr��ָ�룬��������������ʽ�ǵȼ۵�
	 str.member 
	 
     (*p_str).member
     
	 p_str->member
	 
	*/                
    return 0;
}

