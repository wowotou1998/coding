#include <iostream>
using namespace std;
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class complex{
	private:
		double real,image;
	public:
		complex() {
		real=0.0;
		image=0.0;
		cout<<"��ʼ�� 0 0"<<endl;//����complex 
	}//Ĭ�ϵĹ��캯�� 
	 
	complex(double r,double i=0.0){//�������Ĺ��캯�� 
		real=r;
		image=i;
		cout<<"��ʼ��"<<r<<'\t'<<i<<endl;
    }
	complex(complex &);//���ƹ��캯������ 

	~complex(){//��������
		cout<<"��ʼ���ٺ���"<<endl;
		 
	} 
	void assign(complex com){//����assign 
		real=com.real;
		image=com.image;
	}
	void print(){//����print 
		cout<<real<<'+'<<image<<'i'<<endl;
	}
		
};//��������� 
inline complex::complex(complex &com){//inline ��ʾ�Ա�����������飬������һ����Ա���� 
	cout<<"����"<<com.real<<'\t'<<com.image<<endl;
	real=com.real;
	image=com.image;
	
}
complex fun(complex );//fun����������ֵ��complex���͵�ֵ����������ҲΪcomplex 
complex global;//���캯��global���� ȫ�ֶ������Ƚ��� 

int main(int argc, char** argv) {
	cout<<"����main"<<endl;
	complex com1,com2(5.6,7.8);//����com1��com2 
	complex com3=com1;//����com3 
	com3.print();
	global.print();
	com1=fun(com2);
	com1.print();
	cout<<"�˳�main"<<endl;
	return 0; 
}

complex fun(complex com){
	cout<<"���뺯��"<<endl;
	global.assign(com);
	cout<<"�˳�����"<<endl;
	return global; 
}
