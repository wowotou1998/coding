#include<stdio.h>
int a;

int main (void)
 {
 	scanf("%d",&a);
 	if(a<10)
 	  printf("a小于10"); 
 	else if(50>a)
 	  printf("a小于50大于10");
	 else
	 printf("a不属于10到50内的数") ;
	  
  return 0;
 }

