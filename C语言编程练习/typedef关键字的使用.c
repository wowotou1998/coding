# include <stdio.h>
int main (void)
{
	typedef struct{
		int x;
		int y;
	}str;//在这里 可以使用关键字typedef这个关键字来给结构和共用体创建别名，虽然这里省略了结构名称 但不重要，只需要知道这是一个结构就可以 
	str first;

  return 0;
}

