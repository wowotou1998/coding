#include <stdio.h>
typedef char datatype;
//链式存储结构 
typedef struct bnode{
    datatype data;
    struct bnode *lchild ,*rchild;
}bnode, *btree;//二叉树的定义， 其实节点也是一颗数，只不过是子树 

void visit(char data){
	;
} 
//先序遍历  
void preoder(btree t){
    if(t){
        visit(t->data);
        preoder(t->lchild);
        preoder(t->rchild);
      
    }
}

int  main(void){
	
	
	return 0;
}
