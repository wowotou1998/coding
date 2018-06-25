#include <stdio.h>
//char *p="C:\\Users\\8\\Desktop\\list.txt"; 

int main(void)
{
	FILE* file1;
	file1=fopen("C:\\Users\\8\\Desktop\\list.txt","r");
	
	if (file1!=NULL)
		printf( "\n open file successfully\n" );
		else
		printf("open file failed");
	fscanf(*file1);
return 0;
}

