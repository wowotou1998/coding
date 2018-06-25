#include <iostream>
using namespace std;
void fun(int test){
	if(test==0) throw  test;	//抛出int型异常
	if(test==1) throw 1.5;	    //抛出double型异常
	if(test==2) throw "test ";	//抛出char *型异常
	cout<<"fun调用正常结束"<<endl;
}
/*整个函数的调用过程类似于递归
main()-->caller2()--->caller1()---->fun()

当i=3时
没有异常产生


当i=2 时 
caller2 调用 caller1 caller1 调用fun函数
此时 fun 函数检测到异常，并被throw语句抛出一个 char* 类型错误 
异常机制开始运行，首先在fun函数中 寻找参数为 char*  类型的 catch 语句
如果没有 catch 语句，则将异常传递至上一层调用函数中继续寻找与之对应的catch语句 
在 fun 函数中，没有catch语句
则传递至 caller1 语句中去 
 caller1 中没有与之对应的 catch 语句只有 
然后传到 caller2 中
caller2 函数中有catch（...）语句
这个语句可以捕获所以异常
因此异常在这里被解决 
*/
void caller1(int test){
	try{
	fun(test);
	}
	catch(int){
	cout<<"caller1捕获int->";	//捕获异常
	}
	cout<<"caller1调用正常结束"<<endl;
	 
}
 void caller2(int test){
 	try{
 		caller1(test);
	 }
	catch(double){
		cout<<"caller2捕获double异常->"; 
	}
	catch(...){
		cout<<"捕获所有未知异常->"; //catch(...){...} 语句能捕获所以类型的异常 
	}								
 	cout<<"caller2调用结束"<<endl;  
	  
 }


int main(void){
	for (int i=3;i>=0;i--){
		cout<<"第"<<(4-i)<<"次调用"<<endl; 
		caller2(i);
		cout<<"=======================调用结束===================="<<endl; 
	}
	return 0;
}
