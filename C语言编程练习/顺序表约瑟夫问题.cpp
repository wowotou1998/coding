#include <stdio.h>
#include <malloc.h>
#define  maxsize 105

//˳���ṹ 
 typedef struct node{
 int data[maxsize];
 int length ;
 }seqlist;
 
 //����˳��� 
 seqlist* create_seqlist(void){
 seqlist *h;
 h = (seqlist*)malloc(sizeof(seqlist));
 if (h){
 	h->length = 0;
	return h; 
	}
 }

//����ɾ��Ԫ�غ���
int delete_seqlist(seqlist *pl,int i){//ɾ��Ԫ��
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
	//printf("��ɾ��Ԫ��Ϊ%d",pl->data[j]); 
	pl->data[j-1] = pl->data[j];
	};
	
	pl->length--;
	return 1;
 

}
//��������˳�����
int  destroy_seqist(seqlist *h){//����˳���
    free(h);
if (h==NULL){
    return 1;
}
else{
printf("delele error");
return 0;
}

}




//����Լɪ����⺯��
void  josephus_seqlist(seqlist *josephus_seqlist,int s,int m){//Լɪ���㷨
int s1, i, w;
if (josephus_seqlist->length <= 0){
printf("������Ԫ��");

}

s1 = s-1;
printf("���Լɪ�����б�:");
for (i=josephus_seqlist->length; i>0;i--){
s1 = (s1+m-1)%i; 

w = josephus_seqlist->data[s1];
printf("��%d��",w);
delete_seqlist(josephus_seqlist,s1+1);
}

printf("�������");
}


//����������

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

