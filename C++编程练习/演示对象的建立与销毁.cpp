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
	}
	
	complex(double r,double i=0.0){//�в����Ĺ��캯�� 
		real=r;
		image=i;
		cout<<"��ʼ��"<<r<<'\t'<<i<<endl;
    }
	complex(complex &);//�������� 
	~complex(){
		cout<<"��ʼ���ٺ���"<<endl;
		 
	} 
	void assign(complex com){//����assign 
		real=com.real;//���ڵ�����������Ķ���� 
		image=com.image;
	}
	void print(){//����print 
		cout<<real<<'+'<<image<<'i'<<endl;
	}
		
};//��������� 
inline complex::complex(complex &com){//inline ��ʾ�Ա�����������飬����һ�����캯����˵�� 
	cout<<"����"<<com.real<<'\t'<<com.image<<endl;
	real=com.real+50;
	image=com.image+50;
	
}
complex fun(complex x);//fun����������ֵ��complex���͵�ֵ����������ҲΪcomplex 
complex global;//���캯��global���� 

int main(int argc, char** argv) {
	cout<<"����main"<<endl;
	complex com1(1.0,1.0),com2(5.6,7.8);//����com1��com2 
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

