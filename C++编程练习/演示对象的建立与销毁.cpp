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
		cout<<"初始化 0 0"<<endl;//对象complex 
	}
	
	complex(double r,double i=0.0){//有参数的构造函数 
		real=r;
		image=i;
		cout<<"初始化"<<r<<'\t'<<i<<endl;
    }
	complex(complex &);//析构函数 
	~complex(){
		cout<<"开始销毁函数"<<endl;
		 
	} 
	void assign(complex com){//函数assign 
		real=com.real;//属于调用这个函数的对象的 
		image=com.image;
	}
	void print(){//函数print 
		cout<<real<<'+'<<image<<'i'<<endl;
	}
		
};//整个类结束 
inline complex::complex(complex &com){//inline 表示对编译器提出建议，这是一个构造函数的说明 
	cout<<"拷贝"<<com.real<<'\t'<<com.image<<endl;
	real=com.real+50;
	image=com.image+50;
	
}
complex fun(complex x);//fun函数，返回值是complex类型的值，参数类型也为complex 
complex global;//构造函数global对象 

int main(int argc, char** argv) {
	cout<<"进入main"<<endl;
	complex com1(1.0,1.0),com2(5.6,7.8);//构造com1和com2 
	complex com3=com1;//构造com3 
	com3.print();
	global.print();
	com1=fun(com2);
	com1.print();
	cout<<"退出main"<<endl;
	return 0; 
}

complex fun(complex com){
	cout<<"进入函数"<<endl;
	global.assign(com);
	cout<<"退出函数"<<endl;
	return global; 
}

