#include<iostream>
using namespace std; 
class sample{
	int i; 
	static int k;
	public:
	sample();
	void display();

};
int sample::k=0;//��̬���ݳ�Ա�ڳ�����Ҳֻ��һ�ݿ������ɸ����͵����ж��������
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


