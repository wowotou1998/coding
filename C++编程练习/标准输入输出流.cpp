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
	file1.open("E:\\example.txt");//也可以以多种模式打开file1.open("E:\\example.txt",ios::app|ios::binary); 
	if(!file1){
		cout<<"文件打开失败"<<endl; //检验文件是否打开成功 
		
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

