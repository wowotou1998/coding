#include<iostream>
using namespace std;

class Complex{
	float r;		//ʵ��
	float v;    //�鲿
	public:
	Complex();
			  
	Complex Add(Complex a,Complex b);			//�ӷ�
	void display();
	void input(float a,float b);
};

Complex::Complex(){
	
}//ȱʡ���캯�� 

Complex  Complex::Add(Complex a,Complex b){
	r=a.r+b.r;//ʵ������ 
	v=a.v+b.v;//�鲿���� 
}
void Complex::input(float a,float b){
	r=a;
	v=b;
}//���븳ֵ���� 
void Complex::display(){
	cout<<"����Ϊ��"<<r<<"+"<<v<<"i"<<endl;
}

int  main(void){
	float r1,r2,v1,v2; 
	Complex fushu1,fushu2,fushu3;
	cout<<"�������һ��������ʵ��:  ";
	cin >> r1;
	cout<<"�������һ���������鲿:  ";
	cin >> v1;
	fushu1.input(r1,v1);
	
	
	cout<<"\n������ڶ���������ʵ��:  ";
	cin >> r2;
	cout<<"������ڶ����������鲿:  ";
	cin >> v2;
	fushu2.input(r2,v2);
	fushu3.Add(fushu1,fushu2);
	fushu3.display();
	return 0;
}


