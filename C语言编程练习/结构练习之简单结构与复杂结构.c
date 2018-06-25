# include <stdio.h>
int main (void)
{
	struct xy{
		int x;
		int y;	
	} first,second;
	first.x=20;
	first.y=50;
	printf("%d  %d\n",first.x,first.y); 
	
	//第二种命名结构的方式 
    struct point{
    	int a;
    	int b;
    	
	};
	struct point point1,point2;
	struct area{
		struct point point1;
		struct point point2;
	} area1,area2;
	
	area1.point1.a=0;
	area1.point1.b=10;
	area2.point2.a=100;
	area2.point2.b=200;
	printf("%d\n",((area2.point2.a-area1.point1.a)*(area2.point2.b-area1.point1.b)));
	

  return 0;
}

