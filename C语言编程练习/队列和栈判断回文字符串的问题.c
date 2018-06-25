#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAXSIZE 100

typedef  struct node{
	char data;
	struct node *next;
} LSNode;


typedef struct qnode{
	char data;
	struct qnode *next;
} LQNode;

typedef struct{
	LQNode *front;							/*��ͷָ��*/
	LQNode *rear;							/*��βָ��*/
} LQueue;


void StackInitiate(LSNode LSN)
/*��ʼ����ͷ�����ʽ��ջ*/
{
	LSNode *p_ls,**head;
	p_ls = &LSN;
	head = &p_ls ;

	*head = (LSNode *)malloc(sizeof(LSNode));
	if(*head == NULL)
   {
		printf("û�пռ�����\n");

}
	(*head)->next = NULL;
}

int StackNotEmpty(LSNode *head)
 /*�ж�ջ�Ƿ�ǿգ��ǿշ���1���շ���0*/
{
	if(head->next == NULL){
	 	return 0;
	}

	else{
	 	return 1;
	}
}

int StackPush(LSNode *head, char x)
/*������Ԫ��x������ʽ��ջhead��ջ����Ϊ�µ�ջ�� */
{
	LSNode *p;

	if((p = (LSNode *)malloc(sizeof(LSNode))) == NULL)
	{
		printf("�ڴ�ռ䲻���޷�����! \n");
		return 0;
	}

	p->data = x;
	p->next = head->next;				/*�½������ջ��*/
	head->next = p; 					/*�½���Ϊ�µ�ջ��*/
	return 1;
}

int StackPop(LSNode *head, char *d)
/*��ջ����ջ��Ԫ���ɲ���d����*/
{
	LSNode *p = head->next;
	if(p == NULL)
	{
		printf("��ջ�ѿճ���");
		return 0;
	}

	head->next = p->next;			/*ɾ��ԭջ�����*/
	*d = p->data; 					/*ԭջ�����Ԫ�ظ���d*/
	free(p); 						/*�ͷ�ԭջ������ڴ�ռ�*/
	return 1;
}

int StackTop(LSNode *head, char *d)
/*ȡջ��Ԫ�ز���ջ��Ԫ���ɲ���d����*/
{
	LSNode *p = head->next;
	if(p == NULL)
	{
		printf("��ջ�ѿճ���\n");
		return 0;
	}
	*d = p->data;
	return 1;
}

void DestroyLSNode(LSNode *head)
{
	LSNode *p, *p1;

	p = head;
	while(p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}


void QueueInitiate(LQueue *Q)				/*��ʼ����ʽ����Q*/
{
	Q->rear = NULL;					/*�����ʼ��βָ���±�ֵ*/
	Q->front = NULL;					/*�����ʼ��ͷָ���±�ֵ*/
}

int QueueNotEmpty(LQueue Q)
/*����ʽ����Q�ǿշ񣬷ǿ��򷵻�1�����򷵻�0*/
{
	if(Q.front == NULL) {
	return 0;
	} 
	else{
	return 1;
	} 
}

int QueueAppend(LQueue *Q, char x)
/*������Ԫ��ֵx������ʽ����Q�Ķ�β������гɹ��򷵻�1�����򷵻�0 */
{
	LQNode *p;
	if((p = (LQNode *)malloc(sizeof(LQNode))) == NULL)
	{
		printf("�ڴ�ռ䲻�㣡");
		return 0;
	}

	p->data = x;
	p->next = NULL;

	if(Q->rear != NULL) Q->rear->next = p;
	Q->rear = p;
	if(Q->front == NULL) Q->front = p;
	return 1;
}

int QueueDelete(LQueue *Q, char *d)
/*ɾ����ʽ����Q�Ķ�ͷ����Ԫ��ֵ��d �������гɹ��򷵻�1�����򷵻�0*/
{
	LQNode *p;
	if(Q->front == NULL)
	{
		printf("�����ѿ�������Ԫ�س�����! \n");
		return 0;
	}
	else
	{
		*d = Q->front->data;
		p = Q->front;
		Q->front = Q->front->next;
		if(Q->front == NULL) Q->rear = NULL;
		free(p);
		return 1;
	}
}

int QueueGet(LQueue Q, char *d)
/*ȡ��ʽ����Q�ĵ�ǰ��ͷ����Ԫ��ֵ��d ���ɹ��򷵻�1�����򷵻�0*/
{
	if(Q.front == NULL)
	{
		printf("�����ѿ�������Ԫ�س�����! \n");
		return 0;
	}
	else
	{
		*d = Q.front->data;
		return 1;
	}
}

void DestroyLQueue(LQueue Q){
	LQNode *p, *p1;

	p = Q.front;
	while(p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}
int HuiWen(char str[],LQueue Q,LSNode head){
  // ��ջ
	int j ;
	for (j= 0;j<=strlen(str);j++){
		StackPush(&head, str[j]);
		QueueAppend(&Q, str[j]);
	}
// ��ջ
	while(QueueNotEmpty(Q)){
		char str_x[0] = "";
		char str_y[0] = "";
		StackPop(&head,&str_x[0]);
		QueueGet(Q, &str_y[0]);
// �ж�
		if (strcmp(str_x, str_y) == 0){
        	printf("���� \n");
        }
    	else{
        	printf("������ \n");
        	break; 
        	
		}
	}
}

int  main(void)
{
	LQueue LQ;
//	һ��Ҫ��ʼ��
//	һ��Ҫ��ʼ�� 
//	һ��Ҫ��ʼ��
	QueueInitiate(&LQ);
	LSNode LS;
	StackInitiate(LS);
	char str1[]="aeccea";
	char str2[]="ABCDEABCDE";
    HuiWen(str1,LQ,LS);
    HuiWen(str2,LQ,LS);
    return 0;
}

