#include <iostream>
using namespace std;
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class complex{
	private:
		double real,image;
	public:
		complex() {
		real=10.0;
		image=10.0;
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
		image=com.image;//�����=��ֻ�Ǵ���ֵ 
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
complex fun(complex x);//fun����������ֵ��complex���͵�ֵ����������ҲΪcomplex 


complex global;//���캯��global���� //1

int main(int argc, char** argv) {
	printf("entering main\n"); 
	complex com1,com2(5.6,7.8);//����com1��com2 //2 3
	complex com3=com1;//����com3 //3
	com3.print();
	global.print();
	com1=fun(com2);
	com1.print();
	cout<<"�˳�main"<<endl;
	return 0; 
}

complex fun(complex com){
	cout<<"--------����fun����"<<endl;
	global.assign(com);
	cout<<"--------�˳�fun����"<<endl;
	return global; 
}
