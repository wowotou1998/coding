# include <stdio.h>
int main (void)
{
	struct xy{
		int x;
		int y;
		
		
	} first,second;
	first.x=20;
	first.y=50;
	printf("%d  %d",first.x,first.y); 
	//第二种命名结构的方式 
    struct ab{
    	int a;
    	int b;
    	
	};
    struct ab lala,dudu;

  return 0;
}

