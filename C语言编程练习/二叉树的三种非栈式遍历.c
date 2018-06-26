#include <stdio.h>
typedef char datatype;
typedef struct bnode {
	datatype data;
	struct bnode * lchild ,*rchild;

} bnode,*btree; //

void visit(datatype arg) {
	printf("");

}
//递归先序遍历
void preorder(btree t) {

	if(t) {
		visit(t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

//递归中序遍历
void inorder(btree t) {

	if(t) {
		inorder(t->lchild);
		visit(t->data);
		inorder(t->rchild);
	}


}

//递归后序遍历
void postorder(btree t) {
	if(t) {
		postorder(t->lchild);
		postorder(t->rchild);
		visit(t->data);
	}
}

//main函数
int main(void) {

	return 0;
}
//先序遍历非递归算法 --------------------------
void non_recursive_preorder(btree t) {
	pseqstack S;	//构建一个栈
	btree p = t;	//初始化
	S = init_seqstack();	//栈初始化
	while (p || !empty_seqstack(S)) {		//当p存在并且栈不为空时
		if (p) {								//如果p存在
			visit(p->data);					//访问p所存的数据，并将p这个指针入栈，
			push_seqstack(S,p);
			p = p->lchild;					//p指针所指的地址指向p的右孩子
		} else {
			pop_seqstack(S,&p);				//如果p指向NULL则此时遍历到了树的叶子节点上 开始弹出节点
			p = p->rchild;					//开始遍历树的右节点
		}
	}
}

//中序遍历非递归算法------------------
void non_recursive_inorder(bree t) {
	pseqstack S;	//构建一个栈
	btree p = t;	//初始化
	S = init_seqstack();	//栈初始化
	while (p || !empty_seqstack(S)) {		//当p存在并且栈不为空时
		if (p) {								//如果p存在
			push_seqstack(S,p);				//预留p指针在栈中
			p = p->lchild;					//p指针所指的地址指向p的左孩子
		} else {
			pop_seqstack(S,&p);				//弹出节点
			visit(p->data);					//访问p所存的数据
			p = p->rchild;					//将指针指向右孩子，开始遍历树的右节点
		}
	}
}


//先序遍历非递归算法 --------------------------

void non_recursive_postorder(bree t) {
	pseqstack S1;	//构建一个栈 S1
	pseqstack S2;
	btree p = t;	//初始化
	S1 = init_seqstack();	//栈初始化
	S2 = init_seqstack();
	while (p || !empty_seqstack(S)) {		//当p存在并且栈不为空时
		if (p) {								//如果p存在
			push_seqstack(S1,p);			//预留p指针在栈 S1和 S2中
			push_seqstack(S2,p);
			p = p->rchild;					//p指针所指的地址指向p的右孩子	直到遇到根节点
		} else {
			pop_seqstack(S2,&p);			//弹出节点
			p = p->lchild;					//将指针指向左孩子，开始遍历树的左孩子将左孩子全部存放到S1中
		}
	}
	while(!empty(S1)) {						//所有的节点都存入了S1中
		pop_seqstack(S1,&p);				//弹出S1 的节点
		visit(p->data);						//访问节点所存的数据
	}

}













