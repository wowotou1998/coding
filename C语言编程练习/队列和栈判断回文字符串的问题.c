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
	LQNode *front;							/*队头指针*/
	LQNode *rear;							/*队尾指针*/
} LQueue;


void StackInitiate(LSNode LSN)
/*初始化带头结点链式堆栈*/
{
	LSNode *p_ls,**head;
	p_ls = &LSN;
	head = &p_ls ;

	*head = (LSNode *)malloc(sizeof(LSNode));
	if(*head == NULL)
   {
		printf("没有空间申请\n");

}
	(*head)->next = NULL;
}

int StackNotEmpty(LSNode *head)
 /*判堆栈是否非空，非空返回1；空返回0*/
{
	if(head->next == NULL){
	 	return 0;
	}

	else{
	 	return 1;
	}
}

int StackPush(LSNode *head, char x)
/*把数据元素x插入链式堆栈head的栈顶作为新的栈顶 */
{
	LSNode *p;

	if((p = (LSNode *)malloc(sizeof(LSNode))) == NULL)
	{
		printf("内存空间不足无法插入! \n");
		return 0;
	}

	p->data = x;
	p->next = head->next;				/*新结点链入栈顶*/
	head->next = p; 					/*新结点成为新的栈顶*/
	return 1;
}

int StackPop(LSNode *head, char *d)
/*出栈并把栈顶元素由参数d带回*/
{
	LSNode *p = head->next;
	if(p == NULL)
	{
		printf("堆栈已空出错！");
		return 0;
	}

	head->next = p->next;			/*删除原栈顶结点*/
	*d = p->data; 					/*原栈顶结点元素赋予d*/
	free(p); 						/*释放原栈顶结点内存空间*/
	return 1;
}

int StackTop(LSNode *head, char *d)
/*取栈顶元素并把栈顶元素由参数d带回*/
{
	LSNode *p = head->next;
	if(p == NULL)
	{
		printf("堆栈已空出错！\n");
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


void QueueInitiate(LQueue *Q)				/*初始化链式队列Q*/
{
	Q->rear = NULL;					/*定义初始队尾指针下标值*/
	Q->front = NULL;					/*定义初始队头指针下标值*/
}

int QueueNotEmpty(LQueue Q)
/*判链式队列Q非空否，非空则返回1，否则返回0*/
{
	if(Q.front == NULL) {
	return 0;
	} 
	else{
	return 1;
	} 
}

int QueueAppend(LQueue *Q, char x)
/*把数据元素值x插入链式队列Q的队尾，入队列成功则返回1，否则返回0 */
{
	LQNode *p;
	if((p = (LQNode *)malloc(sizeof(LQNode))) == NULL)
	{
		printf("内存空间不足！");
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
/*删除链式队列Q的队头数据元素值到d ，出队列成功则返回1，否则返回0*/
{
	LQNode *p;
	if(Q->front == NULL)
	{
		printf("队列已空无数据元素出队列! \n");
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
/*取链式队列Q的当前队头数据元素值到d ，成功则返回1，否则返回0*/
{
	if(Q.front == NULL)
	{
		printf("队列已空无数据元素出队列! \n");
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
  // 进栈
	int j ;
	for (j= 0;j<=strlen(str);j++){
		StackPush(&head, str[j]);
		QueueAppend(&Q, str[j]);
	}
// 出栈
	while(QueueNotEmpty(Q)){
		char str_x[0] = "";
		char str_y[0] = "";
		StackPop(&head,&str_x[0]);
		QueueGet(Q, &str_y[0]);
// 判断
		if (strcmp(str_x, str_y) == 0){
        	printf("回文 \n");
        }
    	else{
        	printf("不回文 \n");
        	break; 
        	
		}
	}
}

int  main(void)
{
	LQueue LQ;
//	一定要初始化
//	一定要初始化 
//	一定要初始化
	QueueInitiate(&LQ);
	LSNode LS;
	StackInitiate(LS);
	char str1[]="aeccea";
	char str2[]="ABCDEABCDE";
    HuiWen(str1,LQ,LS);
    HuiWen(str2,LQ,LS);
    return 0;
}

