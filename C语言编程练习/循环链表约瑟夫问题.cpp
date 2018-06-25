
#include <stdio.h>
#include <malloc.h>


//链表结构 
 typedef struct node{
 int data;
 struct node *next;
 }linklist;
 
 //初始化链表 
 linklist* creat_list(void){
 linklist *h;
 h = (linklist*)malloc(sizeof(linklist));
 if (h){
 	h->next = h;
	return h; 
}
 }

//获得链表的长度
int get_list_length(linklist *L ){
	if(L->next==NULL){
		printf("链表为空");
		return 0; 
	}
	linklist* p;
	p = L;
	int  j = 0;
	while(p->next!=L){
		j++;
		p = p->next;
	}
	return j;
} 
 //销毁循环链表 
 void destroy_linklist(linklist *h){
 	linklist *temp;
 	while(h){
 		temp = h;
 		free(temp);
 		h = h->next;
	}
	h =NULL;
 }
 
 //查找第i个元素的位置 
 linklist*  locate_linklist(linklist h, int i){
 	linklist *p;
 	int j;
 	p = &h; j=0;
 	while(p && j<i){
 		p = p->next;
		j++;
	}
	
	if (j!=i||!p){
		printf(" the number what you  want to found is error");
		return(NULL);
	}
 	return (p);
}
 
 
 
 
 
//在第i个位置之前插入元素  
bool insert_element(linklist *L, int i, int num) {  
    if (i<1 || i>get_list_length(L))  
    {  
        printf("输入不合法");
    }  
    linklist *p, *q;  
    p = L;  
    for (int j = 0; j < i - 1; j++) {  //定位到要插入结点的前一个    
        p = p->next;  
    }  
    q = (linklist*)malloc(sizeof(linklist));  
    if (!q)  
    {  
        printf("内存分配不足");
    }  
    q->data = num;  
    q->next = p->next;  
    p->next = q;  
    return true;  
}  

//删除第i个元素  
bool deleteListElem(linklist *L, int i) {  
    if (i<1 || i>get_list_length(L))  
    {  
        printf("输入不合法");
    }  
  linklist *p,*q;  
    p = L;  
    int j;  
    for (j = 0; j < i - 1; j++)   //定位到要删除的结点的前一个  
    {  
        p = p->next;  
    }  
    q = p->next;  
    p->next = p->next->next;  
    free(q);  
    return true;  
}  
//查找并返回第i个位置的元素  
int getelement(linklist *L, int i) {  
    if (i<1 || i>get_list_length(L))  
    {  
       printf("输入不合法");
    }  
  	linklist *p;  
    p = L;  
    int j;  
    for (j = 0; j < i; j++)  
    {  
        p = p->next;  
    }  
    return p->data;  
}  

//定义约瑟夫求解函数
int josephus_SeqList(linklist *josephus_link,int s,int m){//约瑟夫算法
linklist *p,*pre;
int count;
if (!josephus_link){
	printf("表中无元素");
	return 0;
}
p = josephus_link;

for (count=1;count<s;count++){
	p = p->next;
}
printf("输出约瑟夫序列表");
	while(p!=p->next){
	pre = p->next;
	while(pre->next!=p){
	pre = pre->next;
	}
	for(count=1;count<m;count++){
		pre = p;
		p = pre->next;
	}
	printf("%d\t",p->data);
	pre->next=p->next;
	free(p);
	p=p->next;
	}
printf("%d\t",p->data);
free(p);
return 1;

}
//定义主函数

int main(void){

return 0;
}


