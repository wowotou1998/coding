#include <iostream>
using namespace std;
 
class A
{
protected:   // protected �µĲ������Ա�������������ʣ���private���ܣ� 
	int i;
	int k;	 //���� 
public:
	A(){
		cout<<"construct A"<<endl;
	}
	A(int a1,int a2){
		i=a1;
		k=a2;
	} ;    //�������� 
   void show();
           //��������Ա������ 
};

void A::show(){
	cout<<i<<endl;
	cout<<k<<endl;
}



class B:public A{
private:
	
	int j;	//�������¼�������� 
public:
	B(int a1,int a2,int a3);//�̳���Ĺ��캯�� ,Ҫ�г����� �������� �� ������
	void show();
};

B::B(int a1,int a2,int a3):A(a1, a2){
	j=a3; //���캯����ʽ�����������������캯��������������1 ������1����������2 ������2��..... �������������β���1���β���2��....)
	      //                                                                        ��������ֻ��Ҫд�β����ͺ��ˣ��������Ͳ�Ҫд 		
}
void B::show(){
		cout<<i<<endl;
		cout<<k<<endl;
		cout<<j<<endl;
	}   //������ķ����������˻���ķ���
int main(void)
{
	A array_of_classA[3]; //ֻ������ 
	A aclass(1,2);
	aclass.show();
	B bclass(3,4,5);
	bclass.show();
	

	
	return 0;
}
