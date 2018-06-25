# include <stdio.h>

int main (void)
{
	int a,b,num,num1,num2;
	printf("请输入总数：和挑选的个数\n") ;
	scanf("%d,%d",&a,&b);
	printf("print %d,%d",a,b) ;
	
  return 0;
}
int func1(int num1,num2)
{
	int num1,num2;
	int result;
	result=func2(num1)/func2(num2)*func2(num1-num2);
	return result;
	 
}

int func2(int num)
{
	int num,Result;
	func2(1)=1;
	Result=func2(num-1)*num;
	return Result;
}
