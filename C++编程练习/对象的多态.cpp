#include <iostream>
using namespace std;

class animal{
public:
	virtual void behavior(){}//这里是一个虚函数，他只是代表一个方法，或者一个接口，他存在的意义就是被其他类继承并实例化各类的方法 
};

class lion:public animal{//lion类继承animal类 

public:
	void behavior(){
		cout<<"i am runing "<<endl;//行为 
	}
};
 
class frog:public animal{//frog类继承animal类 
	
public:
	void behavior(){
		cout<<"i am jumping "<<endl;//行为 
	}
}; 
int main (void)
{
	lion a;
	frog b;
	animal *represent;//定义一个指向基类的指针 
	represent=&a;//指针represent指向对象a，获得a的地址 
	represent->behavior();//执行方法 
	represent=&b;//指针represent指向对象b，获得b的地址 
	represent->behavior();//执行方法 
  	return 0;
}
