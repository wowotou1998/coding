#include <iostream>
#include <vector>
#include <fstream> 
#include <algorithm>
#include <string>
#include <map>
#include <utility>
using namespace std;
int main (void)
{
	fstream file1;
	file1.open("E:\\example.txt");//Ҳ�����Զ���ģʽ��file1.open("E:\\example.txt",ios::app|ios::binary); 
	if(!file1){
		cout<<"�ļ���ʧ��"<<endl; //�����ļ��Ƿ�򿪳ɹ� 
		
	}
	char ch[50];
	
	while(file1){
		char c=file1.get();
	
		if(file1) 
			cout<<c;
	} 
	ofstream fout("E:\\out.txt");
	file1.close();
	return 0;

}

