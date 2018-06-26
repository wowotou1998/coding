#include <stdio.h>
typedef char datatype;
typedef struct bnode {
	datatype data;
	struct bnode * lchild ,*rchild;

} bnode,*btree; //

void visit(datatype arg) {
	printf("");

}
//�ݹ��������
void preorder(btree t) {

	if(t) {
		visit(t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

//�ݹ��������
void inorder(btree t) {

	if(t) {
		inorder(t->lchild);
		visit(t->data);
		inorder(t->rchild);
	}


}

//�ݹ�������
void postorder(btree t) {
	if(t) {
		postorder(t->lchild);
		postorder(t->rchild);
		visit(t->data);
	}
}

//main����
int main(void) {

	return 0;
}
//��������ǵݹ��㷨 --------------------------
void non_recursive_preorder(btree t) {
	pseqstack S;	//����һ��ջ
	btree p = t;	//��ʼ��
	S = init_seqstack();	//ջ��ʼ��
	while (p || !empty_seqstack(S)) {		//��p���ڲ���ջ��Ϊ��ʱ
		if (p) {								//���p����
			visit(p->data);					//����p��������ݣ�����p���ָ����ջ��
			push_seqstack(S,p);
			p = p->lchild;					//pָ����ָ�ĵ�ַָ��p���Һ���
		} else {
			pop_seqstack(S,&p);				//���pָ��NULL���ʱ������������Ҷ�ӽڵ��� ��ʼ�����ڵ�
			p = p->rchild;					//��ʼ���������ҽڵ�
		}
	}
}

//��������ǵݹ��㷨------------------
void non_recursive_inorder(bree t) {
	pseqstack S;	//����һ��ջ
	btree p = t;	//��ʼ��
	S = init_seqstack();	//ջ��ʼ��
	while (p || !empty_seqstack(S)) {		//��p���ڲ���ջ��Ϊ��ʱ
		if (p) {								//���p����
			push_seqstack(S,p);				//Ԥ��pָ����ջ��
			p = p->lchild;					//pָ����ָ�ĵ�ַָ��p������
		} else {
			pop_seqstack(S,&p);				//�����ڵ�
			visit(p->data);					//����p���������
			p = p->rchild;					//��ָ��ָ���Һ��ӣ���ʼ���������ҽڵ�
		}
	}
}


//��������ǵݹ��㷨 --------------------------

void non_recursive_postorder(bree t) {
	pseqstack S1;	//����һ��ջ S1
	pseqstack S2;
	btree p = t;	//��ʼ��
	S1 = init_seqstack();	//ջ��ʼ��
	S2 = init_seqstack();
	while (p || !empty_seqstack(S)) {		//��p���ڲ���ջ��Ϊ��ʱ
		if (p) {								//���p����
			push_seqstack(S1,p);			//Ԥ��pָ����ջ S1�� S2��
			push_seqstack(S2,p);
			p = p->rchild;					//pָ����ָ�ĵ�ַָ��p���Һ���	ֱ���������ڵ�
		} else {
			pop_seqstack(S2,&p);			//�����ڵ�
			p = p->lchild;					//��ָ��ָ�����ӣ���ʼ�����������ӽ�����ȫ����ŵ�S1��
		}
	}
	while(!empty(S1)) {						//���еĽڵ㶼������S1��
		pop_seqstack(S1,&p);				//����S1 �Ľڵ�
		visit(p->data);						//���ʽڵ����������
	}

}













