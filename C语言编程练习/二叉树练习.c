#include <stdio.h>
typedef char datatype;
//��ʽ�洢�ṹ 
typedef struct bnode{
    datatype data;
    struct bnode *lchild ,*rchild;
}bnode, *btree;//�������Ķ��壬 ��ʵ�ڵ�Ҳ��һ������ֻ���������� 

void visit(char data){
	;
} 
//�������  
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
