#include<stdio.h>
#include<stdlib.h>
# define maxvertexnum 30
typedef char infotype;
typedef char vertextype ;
//每一个节点相连的其他节点 邻节点 边节点
typedef struct node{
	int nearvertex;
	infotype info;
	struct node *next;
}edgenode;
//图中的真正节点 
typedef struct vnode{
	vertextype vertex;
	edgenode * firstedge;
	
}vertexnode;
//图结构 
typedef struct {
	vertexnode adjlist[maxvertexnum];//真正节点放在一个列表中
	int vertexnum, edgenum;//顶点数和边数
	
}graph;
//图的建立
void create_graph(graph* G){
	int i,j,k;
	edgenode *p;
	scanf("%d,%d",&(G->vertexnum),&(G->edgenum));//读入顶点数和边数
	for (i=0;i<G->vertexnum;i++){
		scanf("%c",&(G->adjlist[i].vertex));//读入顶点信息

		G->adjlist[i].firstedge = NULL; //定点的边表头指针设为空
	}
	for(k=0;k<G->edgenum;k++)
	{ //建立边表
		scanf("%d,%d", &i, &j) 	;		//读入边《vi，vi》的顶点对应序号
		{											 
			p = (edgenode *)malloc(sizeof(edgenode)); //生成新边表节点p*
			p->nearvertex = j;							  //邻接点序号为j
			p->next = G->adjlist[i].firstedge;		  //将新边表节点p插入到顶点vi的头部
			G->adjlist[i].firstedge = p;			  //
		}
	}
} 
int main (void)
{


  return 0;
}

