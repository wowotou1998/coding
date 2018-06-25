#include<stdio.h>
int a,b,c;
int main (void)
{
	printf("你想使用此程序计算什么？扣1选择计算递减相加\n"); 
	scanf("%d",&b);
	if (b==1)
	   printf("你选择了递减相加\n");
	   printf("请输入你想计算的数\n");
	   scanf("%d",&c);
	      for (;c==0;c=c+(c-1))
	   {
	   	   return(c);
	   }
    else
	  printf("lllll");
	 
	 

	return 0;
 }

