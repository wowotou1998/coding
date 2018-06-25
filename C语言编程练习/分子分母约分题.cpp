#include <iostream>
using namespace std;
int main()
{
    long  n,m,max,i=1,sum=1;
    cout<<"输入分子:"<<endl;
    cin>>n;
    cout<<"输入分母:"<<endl;
    cin>>m;
    if(m==0){
    	cout<<"fenmu wei 0"<<endl;
	}
    	else if (n!=0&&m!=0)
			while (i<=n){
    			if (n%i==0&&m%i==0){
    				cout<<i<<endl;
    				sum =i;
					} 
	    		else{}	
					i++;
         			cout<<"sum is:"<<sum<<endl;
    				cout<<(n/sum)<<"/"<<(m/sum)<<endl;
				}
		else{cout<<0<<"/"<<0;} 
    return 0;
}
 /*for(int i=1;n>=i;i++) 
      if(n%i==0 && m%i==0)
      {
         n/=i;
         m/=i;
    */       
