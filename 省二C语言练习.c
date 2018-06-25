#include<stdio.h>
#include<stdlib.h>
int a;
enum weekday{sun,mon,tue,wed};
typedef enum weekday week; 
typedef struct {

	
} obj ;


void copy_string(char *from, char * to){
		for(;*from!='\0';from++,to++){
			*to=*from;
			*to='\0';
		}
}
	
int main (void)
{
	char ch ;
	FILE *fp = fopen("exa.txt","w") ;
	if(fp==NULL){
		exit(0);
	}
	ch = getchar();
	while(ch!='#'){
		fputc(ch,fp);
		ch = getchar();
	}
	fclose(fp);
	week weekd;
	weekd = sun;
	char s[] = {2,4,6,8,10};
	char *p ;
	int  ii = -1;
	while(0){
		printf("zhen");
	}
//	scanf("%s",s);
//	p = s;
//	printf("%d\n",p) ;
	int arg ;
	for (arg=2;arg<15;arg++){
		if(arg<10){
			continue;
		}else{
			printf("arg is %d\n",arg);
		
			
		}
		
	} 
	
	int i,j;
	for(i=0;i<=3;i++){
		
		for (j=0;j<i;j++){
			printf("%d",i);
			
		}
		printf("*\n");
	} 
	printf("%d,%d",i,j);//这里 i j 的值发生了改变 

  return 0;
}

