#include <iostream>
using namespace std;
 
class A
{
protected:   // protected 下的参数可以被它的派生类访问，而private则不能！ 
	int i;
	int k;	 //属性 
public:
	A(){
		cout<<"construct A"<<endl;
	}
	A(int a1,int a2){
		i=a1;
		k=a2;
	} ;    //构造内容 
   void show();
           //方法（成员函数） 
};

void A::show(){
	cout<<i<<endl;
	cout<<k<<endl;
}



class B:public A{
private:
	
	int j;	//派生类新加入的属性 
public:
	B(int a1,int a2,int a3);//继承类的构造函数 ,要列出所有 数据类型 和 参数名
	void show();
};

B::B(int a1,int a2,int a3):A(a1, a2){
	j=a3; //构造函数格式（派生类名：：构造函数名（数据类型1 数据名1，数据类型2 数据名2，..... ）：基类名（形参名1，形参名2，....)
	      //                                                                        这里基类就只需要写形参名就好了，数据类型不要写 		
}
void B::show(){
		cout<<i<<endl;
		cout<<k<<endl;
		cout<<j<<endl;
	}   //派生类的方法，屏蔽了基类的方法
int main(void)
{
	A array_of_classA[3]; //只有三个 
	A aclass(1,2);
	aclass.show();
	B bclass(3,4,5);
	bclass.show();
	

	
	return 0;
}
