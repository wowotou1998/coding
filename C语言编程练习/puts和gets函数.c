# include <stdio.h>
int main (void)
{
	char string[55];
	puts("input some words");
	gets(string);//string是数组的名称，也是数组第一个元素的指针 
	printf("%s",string); //要使用字符串，要使用转换说明符%s 
  return 0;
}
//c语言中的while语句当表达式的值为真（不为0） 时，将执行循环体，否则 则退出循环
 
