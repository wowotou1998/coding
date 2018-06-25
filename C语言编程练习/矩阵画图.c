#include<stdio.h>
void draw_box(int ,int );

int main (void)
{
	
  draw_box(5,6 );
 
	return 0;
}
 
void draw_box(int h, int lie)
{
	int c;
	for (;h>0;h--);
	{
		for (c=lie;c>0;c--);
		printf("X");
	}
	printf("\n");
}
