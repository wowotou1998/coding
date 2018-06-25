#include <stdio.h>
#define a 'a'//单引号 编译器可将字面字符常量转换为相应的ASCII码 

int main (void)
{
	char c1='c';//这个时候 char的变量应该是'c'这种形式的 这种'sss'多个字符是错误的 
	char c2=90; 
	unsigned char mychar;
	printf("%c\n",c1);
	printf("%d\n",c1);
	for (mychar=1;mychar<4;mychar++)
	{
		printf("%d \t is \t %c \t \n",mychar,mychar);//\t是制表符 
		
	 } 
	/*printf("%c\n",a);//%c表示输出字符 
    printf("%d\n",a);//%d表示输出十进制的数 
    */
    
  return 0;
}


