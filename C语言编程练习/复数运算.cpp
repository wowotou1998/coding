#include<iostream>
using namespace std;

class Complex{
	float r;		//实部
	float v;    //虚部
	public:
	Complex();
			  
	Complex Add(Complex a,Complex b);			//加法
	void display();
	void input(float a,float b);
};

Complex::Complex(){
	
}//缺省构造函数 

Complex  Complex::Add(Complex a,Complex b){
	r=a.r+b.r;//实部计算 
	v=a.v+b.v;//虚部计算 
}
void Complex::input(float a,float b){
	r=a;
	v=b;
}//输入赋值函数 
void Complex::display(){
	cout<<"复数为："<<r<<"+"<<v<<"i"<<endl;
}

int  main(void){
	float r1,r2,v1,v2; 
	Complex fushu1,fushu2,fushu3;
	cout<<"请输入第一个复数的实部:  ";
	cin >> r1;
	cout<<"请输入第一个复数的虚部:  ";
	cin >> v1;
	fushu1.input(r1,v1);
	
	
	cout<<"\n请输入第二个复数的实部:  ";
	cin >> r2;
	cout<<"请输入第二个复数的虚部:  ";
	cin >> v2;
	fushu2.input(r2,v2);
	fushu3.Add(fushu1,fushu2);
	fushu3.display();
	return 0;
}


