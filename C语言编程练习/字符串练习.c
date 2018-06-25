#include <stdio.h>
#include <stdlib.h> 
int i=5,count;
char string1[10]={'h','l','l','o','w','o','r','l','d'};
char string2[12]="hello,world";//这种写法就比较便捷了
char string3[]="lalallalal";//没有指定长度，编译器自动处理
char *p=string1 ;//一个名为p的指针指向字符串的第一个字符 
char string3[] ;//与上一个等价 char string[]==char *p=string
 
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

