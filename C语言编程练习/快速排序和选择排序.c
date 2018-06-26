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
	
	keytype centerpoint;//pivot�����ĵ����˼ 
	s->r[0] = s->r[low];//s->r[0]��Ϊǰ��վ 
	centerpoint = s->r[low].key;
	while(low<high){ 
	//��ǰ�� 
			
		while(low<high && s->r[high].key >= centerpoint){
			high--;
		}
		s->r[low] = s->r[high];
		
		while(low<high && s->r[high].key <= centerpoint){
			low--;
		}
		s->r[high] = s->r[low];
		
	}
	
	s->r[low] = s->r[0];   //��ֵ�����ĵ㣩��¼��λ ��ǰ��վ�ŵ����ĵ㴦 

	return low;//������ֵ��¼����λ�� Ҳ�������ĵ��¼��λ�� 
	
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
	//	��������� 
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
