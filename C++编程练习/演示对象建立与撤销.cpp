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
		image=com.image;//这里的=号只是传递值 
	}
	void print(){//函数print 
		cout<<real<<'+'<<image<<'i'<<endl;
	}
		
};//整个类结束 
inline complex::complex(complex &com){//inline 表示对编译器提出建议，这里有一个成员函数 
	cout<<"拷贝"<<com.real<<'\t'<<com.image<<endl;
	real=com.real;
	image=com.image;
	
}
complex fun(complex x);//fun函数，返回值是complex类型的值，参数类型也为complex 


complex global;//构造函数global对象 //1

int main(int argc, char** argv) {
	printf("entering main\n"); 
	complex com1,com2(5.6,7.8);//构造com1和com2 //2 3
	complex com3=com1;//构造com3 //3
	com3.print();
	global.print();
	com1=fun(com2);
	com1.print();
	cout<<"退出main"<<endl;
	return 0; 
}

complex fun(complex com){
	cout<<"--------进入fun函数"<<endl;
	global.assign(com);
	cout<<"--------退出fun函数"<<endl;
	return global; 
}
