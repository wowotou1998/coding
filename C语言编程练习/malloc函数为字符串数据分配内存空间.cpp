# include <stdio.h>
#include <stdlib.h>
char count,*ptr,*p;

int main (void)
{
	ptr=(char*)malloc(35*sizeof(char));
	if (ptr==NULL)
	{
		printf("memory allocation error");
		return 1;
	}
    p=ptr;
     for (count=65;count<91;count++)
     *p++=count;
     *p='\0';
     puts(ptr);
     free(ptr);
     

  return 0;
}

