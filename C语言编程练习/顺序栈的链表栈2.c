#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int data;
  struct node *next;
}node;

typedef struct{
  node *top;
}stacktop_pointer;

//��ʼ��ջ 
stacktop_pointer * initseqstack(void){
  stacktop_pointer *h;
  h = (stacktop_pointer *)malloc(sizeof(stacktop_pointer));
  if(h) h->top = NULL;
  return(h);
}
//�ж�ջ�գ��շ���0 �ǿշ���1
int judge_stack_empty( stacktop_pointer *s){
  return (s->top==NULL?0:1);
}

//������ջ 
void push_stack(stacktop_pointer *s,int x){
  node *p;
  p = (node*)malloc(sizeof(node));
  if (p==NULL){
    printf("Memory ERROR\n");
    exit(0);
  }
  p->next = NULL;
  p->data = x;
  p->next = s->top;
  s->top = p;
}
//���ݳ�ջ 
int pop_stack(stacktop_pointer *s, int *x){
  node *p;
  p = (node*)malloc(sizeof(node));
  if (p==NULL){
    printf("Memory ERROR\n");
    exit(0);
  }
  if (s->top==NULL){
    return 0;
  }
  p = s->top;
  *x = p->data;
  s->top = p->next;
  free(p);
  return 1;
}


//�õ�ջ�� 
int gettop_stack(stacktop_pointer *s, int *x){
  if(s->top=NULL){
    return 0;
  }
  *x = (s->top)->data;
  return 1;
}
//��ӡջ�е�Ԫ�� 
void print_stack(stacktop_pointer *s){
  if (s->top=NULL){
    printf("stack is empty \n");
  }
  int x;
  while(s->top!=NULL){
    printf("%d\n",s->top->data);
    s->top = s->top->next;
  }
}
//������ 
int main (void)
{
    stacktop_pointer nd;
    int arg;
    stacktop_pointer *a = initseqstack();
    push_stack(&nd,2);
    push_stack(&nd,3);
    push_stack(&nd,4);
    push_stack(&nd,5);
    pop_stack(&nd,&arg);
    print_stack(&nd);
    printf("%d\n",arg);
    printf("element is :%d\n", arg);
    //printStack(&nd);
    return 0;
}

