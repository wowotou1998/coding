#include <stdio.h>
#include <stdlib.h>
int main (void)
{
	void *p;
	int cnt=0;
	while ((p=malloc(100*1024*1024)))
	{
		cnt++;
	}
	printf("获得%d00MB的内存",cnt);

	return 0;
 }

