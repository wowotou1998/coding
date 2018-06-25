#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100

typedef struct{
	int data[MAXSIZE];
	int top;
} seqstack;//结构化栈

//初始化栈
void initseqstack(seqstack *st){
	st->top=-1;
}

//对栈判空
int judge_stack_empt(seqstack *st){
	return(st->top==-1?1:0);
}
//进栈
int push_stack(seqstack *st,int x){
	if(st->top==MAXSIZE-1){
		return 1;
	}
	st->data[++(st->top)]= x;
	return 1;
}
//出栈，由于是在数组里，所以不需要释放内存
int pop_stack(seqstack *st, int *x){
	if(st->top==-1){
		return 0;
	}
	*x = st->data[(st->top)--];
	return 1;
}
//打印栈的内容
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
	printf("请输入所要转换的十进制数：");
	scanf("%d",&x);
	while(x!=0){
		push_stack(&T,x%2);
		x = x/2;// 如果int x=2.5 ,由于x的值为int 所以x = 2； 
	}
	
	print_stack(&T);
	return 0;
}
