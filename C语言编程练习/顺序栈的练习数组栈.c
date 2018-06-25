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
	st->data[++ st->top]= x;
	return 1;
}
//出栈，由于是在数组里，所以不需要释放内存
int pop_stack(seqstack *st, int *x){
	if(st->top==-1){
		return 0;
	}
	*x = st->data[st->top--];
	return 1;
}
//打印栈的内容
void print_stack(seqstack *st ){
	while(st->top!=-1){
		printf("栈的元素：%d\n",st->data[st->top--]);
	}
}

int main (void/* arguments */) {
	/* code */
	int x;
	seqstack st={{1,2,7,68,98},3};
	push_stack(&st, 5);
	pop_stack(&st, &x);
	printf("%d\n",x );
	print_stack(&st);
	return 0;
}
