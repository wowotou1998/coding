# include <iostream>
# include <string>
using namespace std;
class Person{
	int MarkAchieve;
	string Name;
	public:
		Person(string name){
			Name =name;
			MarkAchieve=0;
		}
		void SetMark(int mark){MarkAchieve=mark;	};
		virtual void CalMark()=0;
		void Print(){
		cout<<Name<<"学分为:"<<MarkAchieve<<endl;}
	
};
class Student:public Person{
	int credit,grade;
	public :
	Student(string name,int cred,int grad):Person(name){//构造函数在类中，则不需要加类名前缀 
		credit=cred;
		grade=grad;
		
	}
	void CalMark() {SetMark(credit*grade);}
};
class Teacher:public Person{
	int classhour,studnum;
	public:
		Teacher(string name,int ch,int sn):Person(name){  //
			classhour=ch;
			studnum=sn;
			
		}
		void CalMark(){
		
		
		
		}
}; 
int main(){
	Person *pp;
	Student s1("zhangcheng",20,80);
	Teacher t1("fanyingmin",60,125),t2("likai",80,85);
	pp=&s1;
	pp->CalMark();
	pp->Print();
	pp=&t1;
	pp->CalMark();
	pp->Print();
	pp=&t2;
	pp->CalMark();
	pp->Print();
	return 0;
}


