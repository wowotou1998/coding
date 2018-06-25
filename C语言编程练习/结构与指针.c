# include <stdio.h>
int cost=1,interest=2; 
int main (void)
{
	struct date{
		int *value;
		int *rate;
	} first ; 
	first.value=&cost;/* 表达式*first.value指的是变量cost的值 */
	first.rate=&interest;/* 与上同理  */
	
	 
   //char指针有些特别 
   
   char *p_message;
   p_message="klalalalal";
   
   printf("%d\n%c",p_message,(*p_message));/* %c 表示输出字符：可以把输入的数字按照ASCII码转化为相应的字符
                                              %s 表示输出字符串中的字符直至字符串中的空字符（空字符以'\0'表示）*/   
             
   struct msg{
   	char *p1;
   	char *p2;
   	
   }myptrs; 
   myptrs.p1="sdjhsakj";
   myptrs.p2="hasdgqquw";
   
   //指向结构的指针
   struct part{
   	short number;
   	char name[10];
   	
   } third; 
    struct part *p_part;//这是一个指针 但不是一个实例，也就是说，这是一个结构指针，但还没有指向任何结构
	p_part=&third;
	
	//运用指针，我们可以比较便捷的读取结构成员，方式有三种
	/*如果p_str 是指向结构str的指针，则下面的三个表达式是等价的
	 str.member 
	 
     (*p_str).member
     
	 p_str->member
	 
	*/                
    return 0;
}

