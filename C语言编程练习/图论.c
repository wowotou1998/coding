#include<stdio.h>
#include<stdlib.h>
# define maxvertexnum 30
typedef char infotype;
typedef char vertextype ;
//ÿһ���ڵ������������ڵ� �ڽڵ� �߽ڵ�
typedef struct node{
	int nearvertex;
	infotype info;
	struct node *next;
}edgenode;
//ͼ�е������ڵ� 
typedef struct vnode{
	vertextype vertex;
	edgenode * firstedge;
	
}vertexnode;
//ͼ�ṹ 
typedef struct {
	vertexnode adjlist[maxvertexnum];//�����ڵ����һ���б���
	int vertexnum, edgenum;//�������ͱ���
	
}graph;
//ͼ�Ľ���
void create_graph(graph* G){
	int i,j,k;
	edgenode *p;
	scanf("%d,%d",&(G->vertexnum),&(G->edgenum));//���붥�����ͱ���
	for (i=0;i<G->vertexnum;i++){
		scanf("%c",&(G->adjlist[i].vertex));//���붥����Ϣ

		G->adjlist[i].firstedge = NULL; //����ı߱�ͷָ����Ϊ��
	}
	for(k=0;k<G->edgenum;k++)
	{ //�����߱�
		scanf("%d,%d", &i, &j) 	;		//����ߡ�vi��vi���Ķ����Ӧ���
		{											 
			p = (edgenode *)malloc(sizeof(edgenode)); //�����±߱�ڵ�p*
			p->nearvertex = j;							  //�ڽӵ����Ϊj
			p->next = G->adjlist[i].firstedge;		  //���±߱�ڵ�p���뵽����vi��ͷ��
			G->adjlist[i].firstedge = p;			  //
		}
	}
} 
int main (void)
{


  return 0;
}

