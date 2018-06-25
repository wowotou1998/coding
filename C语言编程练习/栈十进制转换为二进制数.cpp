#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100

typedef struct{
	int data[MAXSIZE];
	int top;
} seqstack;//�ṹ��ջ

//��ʼ��ջ
void initseqstack(seqstack *st){
	st->top=-1;
}

//��ջ�п�
int judge_stack_empt(seqstack *st){
	return(st->top==-1?1:0);
}
//��ջ
int push_stack(seqstack *st,int x){
	if(st->top==MAXSIZE-1){
		return 1;
	}
	st->data[++(st->top)]= x;
	return 1;
}
//��ջ������������������Բ���Ҫ�ͷ��ڴ�
int pop_stack(seqstack *st, int *x){
	if(st->top==-1){
		return 0;
	}
	*x = st->data[(st->top)--];
	return 1;
}
//��ӡջ������
void print_stack(seqstack *st ){
	while(st->top!=-1){
		printf("%d",st->data[(st->top)--]);
	}
}

int main (void/* arguments */) {
	/* code */
	seqstack T;
	print_stack(&T);;
	int x;
	printf("��������Ҫת����ʮ��������");
	scanf("%d",&x);
	while(x!=0){
		push_stack(&T,x%2);
		x = x/2;// ���int x=2.5 ,����x��ֵΪint ����x = 2�� 
	}
	
	print_stack(&T);
	return 0;
}
