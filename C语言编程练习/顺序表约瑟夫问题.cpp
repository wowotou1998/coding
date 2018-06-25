#include <stdio.h>
#include <malloc.h>
#define  maxsize 105

//顺序表结构 
 typedef struct node{
 int data[maxsize];
 int length ;
 }seqlist;
 
 //创建顺序表 
 seqlist* create_seqlist(void){
 seqlist *h;
 h = (seqlist*)malloc(sizeof(seqlist));
 if (h){
 	h->length = 0;
	return h; 
	}
 }

//定义删除元素函数
int delete_seqlist(seqlist *pl,int i){//删除元素
int j;
if(!pl){
	printf("list in not existed");
	return (-1);
}

if (i<1||i>pl->length){
	printf("delele error");
	return 0; 
}
for (j=i;j<pl->length;j++){
	//printf("被删除元素为%d",pl->data[j]); 
	pl->data[j-1] = pl->data[j];
	};
	
	pl->length--;
	return 1;
 

}
//定义销毁顺序表函数
int  destroy_seqist(seqlist *h){//销毁顺序表
    free(h);
if (h==NULL){
    return 1;
}
else{
printf("delele error");
return 0;
}

}




//定义约瑟夫求解函数
void  josephus_seqlist(seqlist *josephus_seqlist,int s,int m){//约瑟夫算法
int s1, i, w;
if (josephus_seqlist->length <= 0){
printf("表中无元素");

}

s1 = s-1;
printf("输出约瑟夫序列表:");
for (i=josephus_seqlist->length; i>0;i--){
s1 = (s1+m-1)%i; 

w = josephus_seqlist->data[s1];
printf("《%d》",w);
delete_seqlist(josephus_seqlist,s1+1);
}

printf("问题结束");
}


//定义主函数

int main(void){
seqlist *example;
example = create_seqlist();
for(int i=0;i<99;i++){
example->data[i]=i;
example->length++;
} 

printf("\n");
josephus_seqlist(example,2,5);
return 0;
}

