# include <stdio.h>

int main (void)
{
	int a,b,num,num1,num2,x,y,xy;
	printf("请输入总数：和挑选的个数\n") ;
	scanf("%d,%d",&a,&b);
	printf("print %d,%d",a,b) ;
    x=func2(a);
    y=func2(b);
    xy=func1(x,y);
    printf("%d",xy) ;
  return 0;
}
int func2(int num)
{
    int result1;
    func2(1)==1; 
	result1=func2(num-1)*num;

	
	return result1;
}
int func1(int num1,int num2)
{

	int result;
	result=num1/num2*(num1-num2);
	return result;
	 
}


