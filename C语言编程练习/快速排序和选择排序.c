#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define maxsize 31
typedef int keytype;
typedef char othertype;

//
typedef struct{
	keytype key;
	othertype other;
}datatype;

typedef struct{
	datatype r[maxsize];
	int length;
}sqlist; 

//
int quicksortpart(sqlist *s ,int low,int high){
	
	keytype centerpoint;//pivot是中心点的意思 
	s->r[0] = s->r[low];//s->r[0]作为前哨站 
	centerpoint = s->r[low].key;
	while(low<high){ 
	//大前提 
			
		while(low<high && s->r[high].key >= centerpoint){
			high--;
		}
		s->r[low] = s->r[high];
		
		while(low<high && s->r[high].key <= centerpoint){
			low--;
		}
		s->r[high] = s->r[low];
		
	}
	
	s->r[low] = s->r[0];   //轴值（中心点）记录到位 将前哨站放到中心点处 

	return low;//返回轴值记录所在位置 也就是中心点记录的位置 
	
}

//

void quicksort(sqlist *s ,int low, int high){
	int pivotloc;
	if(low<high0){
		pivotloc = quicksortpart(s,low,high);
		quicksort(s,low,pivotloc-1);
		quicksort(s,pivotloc+1,high);
		
	}
} 


int main(void){
	srand(time(NULL)); 
	//	产生随机数 
	int p = rand()%100+1;

	sqlist s1;
	int i;
	for(i=1;i<=31;i++){
		s1.r[i].key = rand()%100+1;
	}
	int count = 1;
	for(i=1;i<=30;i++){
		
		printf("%d ",s1.r[i].key);
	}

	
	
	
	
	
	
	
	
	
	
	
//	int temp = 5;
//	
//	for(i=0;i<1;i++){
//		int temp = 8;
//		printf("%d\n",temp);
//	}
//	printf("%d\n",temp);
//	return 0;
	
} 
