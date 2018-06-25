#include<stdio.h>
int main (void)
{
	int i=8,j=2,k;
	int *p1=&i;
	int *p2=&j;
	printf("%d\n",p1);
	printf("%d\n",p2);
    //这里指针开始增加，每次增加量依据变量的类型在内存中所占的字节； 
	printf("%d\n",p1);
	k=*(p2+1);//*号的优先级比+号高，因此，需要有括号（） 
	printf("%d",k);
	return 0;
 }

