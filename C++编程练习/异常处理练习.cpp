#include <iostream>
using namespace std;
void fun(int test){
	if(test==0) throw  test;	//�׳�int���쳣
	if(test==1) throw 1.5;	    //�׳�double���쳣
	if(test==2) throw "test ";	//�׳�char *���쳣
	cout<<"fun������������"<<endl;
}
/*���������ĵ��ù��������ڵݹ�
main()-->caller2()--->caller1()---->fun()

��i=3ʱ
û���쳣����


��i=2 ʱ 
caller2 ���� caller1 caller1 ����fun����
��ʱ fun ������⵽�쳣������throw����׳�һ�� char* ���ʹ��� 
�쳣���ƿ�ʼ���У�������fun������ Ѱ�Ҳ���Ϊ char*  ���͵� catch ���
���û�� catch ��䣬���쳣��������һ����ú����м���Ѱ����֮��Ӧ��catch��� 
�� fun �����У�û��catch���
�򴫵��� caller1 �����ȥ 
 caller1 ��û����֮��Ӧ�� catch ���ֻ�� 
Ȼ�󴫵� caller2 ��
caller2 ��������catch��...�����
��������Բ��������쳣
����쳣�����ﱻ��� 
*/
void caller1(int test){
	try{
	fun(test);
	}
	catch(int){
	cout<<"caller1����int->";	//�����쳣
	}
	cout<<"caller1������������"<<endl;
	 
}
 void caller2(int test){
 	try{
 		caller1(test);
	 }
	catch(double){
		cout<<"caller2����double�쳣->"; 
	}
	catch(...){
		cout<<"��������δ֪�쳣->"; //catch(...){...} ����ܲ����������͵��쳣 
	}								
 	cout<<"caller2���ý���"<<endl;  
	  
 }


int main(void){
	for (int i=3;i>=0;i--){
		cout<<"��"<<(4-i)<<"�ε���"<<endl; 
		caller2(i);
		cout<<"=======================���ý���===================="<<endl; 
	}
	return 0;
}
