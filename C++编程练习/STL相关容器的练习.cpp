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
	v1.insert(v1.begin(),0);//��ͷ������0 
	v1.insert(v1.end(),5); // ������β������4 
	v1.insert(v1.end()-1,3);//��β����ǰһλ��Ҳ���ǵ����ڶ�λ����3
	sort(v1.begin(),v1.end()) ;//�������������� ����Ϊ��������Ŀ�ͷ�ͽ�β 
	for (int i=0;i<v1.size();i++){
		cout<<v1[i] <<endl;
	} 
	
	
	cout<<"----------------------"<<endl;
	for (int i=1;i<10;i++){
		v2.push_back(i);
	}
	//����һ�����������������е���ָ�� 
	vector<int>::iterator it;		
	for(it=v2.begin();it<v2.end();it++){
		if(*it%2==0){			//*it������ָ�ĵ�������Ԫ�ص�ֵ 
			cout<<*it<<endl;
		}
	}
	
	
	
	cout<<"------------------------"<<endl;
	for (it=v2.begin();it<v2.end();){
		if(*it%2 ==0){
			//v2.erase����ɾ��֮�����һ��Ԫ�ص�λ�� 
			it=v2.erase(it);		
			cout<<*(it)<<endl;
		}
		else{
			it++;
		}
	} 
	cout<<"---------------------"<<endl;
	sort(v2.begin(),v2.end());
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),new_v3.begin());//�ϲ��㷨merge��ע�������Ҫ��˳��� 
	
	for(it=new_v3.begin();it!=new_v3.end();it++){
		cout<<*it<<endl;
	}
	
	//����map��pair����
	 pair<string,string> pair_example1("mama","she is mmama");
	 map<string,string> map_example1;
	 map_example1.insert(pair_example1);
	 cout<<map_example1["mama"];
     return 0;
}

