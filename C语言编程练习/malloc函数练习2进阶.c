# include <stdio.h>
#include <stdlib.h>
int main (void)
{
	/*需要50个int类的内存块*/
	
	int*p1;//定义指针 
	
	p1=(int*)malloc(50*(sizeof(int)));//分配内存 
	
	*p1=15893;//往内存里写数据 
	
	printf("%d\n",(*p1));
	
	/*需要100个char类的内存块*/
	
	char*p2;
	p2=(char*)malloc(100*(sizeof(char))) ;
	
	/*需要500个float类的内存块*/
	
	float *p3;
	p3=(float*)malloc(980000000000*(sizeof(float)));
	if(p3==NULL)//判断内存是否分配成功 
	{
	   printf("内存分配不成功");
	}	
	 else printf("内存分配成功") ;


  return 0;
}

