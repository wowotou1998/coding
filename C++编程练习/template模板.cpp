#include <iostream>
#include<string>
using namespace std;

template <typename T>
void display(T a)
{
	cout<<a<<endl;
}
template<typename T,class S>
void display(T t,S s)
{
	cout<<t<<endl;
	cout<<s<<endl;
}
template <typename T,int ksize>
void display(T a)
{
	for(int i=0;i<ksize;i++)
	{
		cout<<a<<endl;
	}
}

int main (void)
{
	display<int>(10);
	display<int,double>(5,8.3);
	display<int,10>(9);

 	 return 0;
}

