#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string>
#include <map>
#include <utility> 
using namespace std;
int main (void)
{
	vector<int> v1;
	vector<int> v2;
	vector<int> new_v3;
	v1.push_back(8);
	v1.push_back(4);
	v1.insert(v1.begin(),0);//在头部插入0 
	v1.insert(v1.end(),5); // 在容器尾部插入4 
	v1.insert(v1.end()-1,3);//在尾部向前一位，也就是倒数第二位插入3
	sort(v1.begin(),v1.end()) ;//容器的排序函数， 参数为排序区间的开头和结尾 
	for (int i=0;i<v1.size();i++){
		cout<<v1[i] <<endl;
	} 
	
	
	cout<<"----------------------"<<endl;
	for (int i=1;i<10;i++){
		v2.push_back(i);
	}
	//定义一个迭代器，迭代器有点像指针 
	vector<int>::iterator it;		
	for(it=v2.begin();it<v2.end();it++){
		if(*it%2==0){			//*it代表所指的迭代器中元素的值 
			cout<<*it<<endl;
		}
	}
	
	
	
	cout<<"------------------------"<<endl;
	for (it=v2.begin();it<v2.end();){
		if(*it%2 ==0){
			//v2.erase返回删除之后的下一个元素的位置 
			it=v2.erase(it);		
			cout<<*(it)<<endl;
		}
		else{
			it++;
		}
	} 
	cout<<"---------------------"<<endl;
	sort(v2.begin(),v2.end());
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),new_v3.begin());//合并算法merge，注意参数是要有顺序的 
	
	for(it=new_v3.begin();it!=new_v3.end();it++){
		cout<<*it<<endl;
	}
	
	//创建map和pair对象
	 pair<string,string> pair_example1("mama","she is mmama");
	 map<string,string> map_example1;
	 map_example1.insert(pair_example1);
	 cout<<map_example1["mama"];
     return 0;
}

