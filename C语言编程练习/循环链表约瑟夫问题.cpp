
#include <stdio.h>
#include <malloc.h>


//����ṹ 
 typedef struct node{
 int data;
 struct node *next;
 }linklist;
 
 //��ʼ������ 
 linklist* creat_list(void){
 linklist *h;
 h = (linklist*)malloc(sizeof(linklist));
 if (h){
 	h->next = h;
	return h; 
}
 }

//�������ĳ���
int get_list_length(linklist *L ){
	if(L->next==NULL){
		printf("����Ϊ��");
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
 //����ѭ������ 
 void destroy_linklist(linklist *h){
 	linklist *temp;
 	while(h){
 		temp = h;
 		free(temp);
 		h = h->next;
	}
	h =NULL;
 }
 
 //���ҵ�i��Ԫ�ص�λ�� 
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
 
 
 
 
 
//�ڵ�i��λ��֮ǰ����Ԫ��  
bool insert_element(linklist *L, int i, int num) {  
    if (i<1 || i>get_list_length(L))  
    {  
        printf("���벻�Ϸ�");
    }  
    linklist *p, *q;  
    p = L;  
    for (int j = 0; j < i - 1; j++) {  //��λ��Ҫ�������ǰһ��    
        p = p->next;  
    }  
    q = (linklist*)malloc(sizeof(linklist));  
    if (!q)  
    {  
        printf("�ڴ���䲻��");
    }  
    q->data = num;  
    q->next = p->next;  
    p->next = q;  
    return true;  
}  

//ɾ����i��Ԫ��  
bool deleteListElem(linklist *L, int i) {  
    if (i<1 || i>get_list_length(L))  
    {  
        printf("���벻�Ϸ�");
    }  
  linklist *p,*q;  
    p = L;  
    int j;  
    for (j = 0; j < i - 1; j++)   //��λ��Ҫɾ���Ľ���ǰһ��  
    {  
        p = p->next;  
    }  
    q = p->next;  
    p->next = p->next->next;  
    free(q);  
    return true;  
}  
//���Ҳ����ص�i��λ�õ�Ԫ��  
int getelement(linklist *L, int i) {  
    if (i<1 || i>get_list_length(L))  
    {  
       printf("���벻�Ϸ�");
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

//����Լɪ����⺯��
int josephus_SeqList(linklist *josephus_link,int s,int m){//Լɪ���㷨
linklist *p,*pre;
int count;
if (!josephus_link){
	printf("������Ԫ��");
	return 0;
}
p = josephus_link;

for (count=1;count<s;count++){
	p = p->next;
}
printf("���Լɪ�����б�");
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
//����������

int main(void){

return 0;
}


