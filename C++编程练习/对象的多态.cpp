#include <iostream>
using namespace std;

class animal{
public:
	virtual void behavior(){}//������һ���麯������ֻ�Ǵ���һ������������һ���ӿڣ������ڵ�������Ǳ�������̳в�ʵ��������ķ��� 
};

class lion:public animal{//lion��̳�animal�� 

public:
	void behavior(){
		cout<<"i am runing "<<endl;//��Ϊ 
	}
};
 
class frog:public animal{//frog��̳�animal�� 
	
public:
	void behavior(){
		cout<<"i am jumping "<<endl;//��Ϊ 
	}
}; 
int main (void)
{
	lion a;
	frog b;
	animal *represent;//����һ��ָ������ָ�� 
	represent=&a;//ָ��representָ�����a�����a�ĵ�ַ 
	represent->behavior();//ִ�з��� 
	represent=&b;//ָ��representָ�����b�����b�ĵ�ַ 
	represent->behavior();//ִ�з��� 
  	return 0;
}
