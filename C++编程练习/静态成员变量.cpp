#include<iostream>
using namespace std; 
class sample{
	int i; 
	static int k;
	public:
	sample();
	void display();

};
int sample::k=0;//静态数据成员在程序中也只有一份拷贝，由该类型的所有对象共享访问
sample::sample(){
	i=0;k++;}
void sample::display()
{   
	cout<<"i="<<i<<",k="<<k<<endl;
}
int  main(void)
{	
	sample a; 
	sample b;
	a.display();
	b.display();
}


