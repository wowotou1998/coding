# include <stdio.h>
int main (void)
{
	struct date {
		int x[4];
		char y[10];
	} first ; 
	
	struct date1 {
		char name;
		char sex;
		int number;
		
	}; 
    struct date1 contact_person[100];//定义了一个含有结构的数组
    
	struct customer {
		char firm[20];
		char contact[25];
		
	};  

    struct sale{
    	struct customer buyer;
    	char item[20];
    	float amount;
	} mysale ={{"acme industries","george"},//结构里的结构变量 
	            "lefet",
	            1000.00
			  };
	
  return 0;
   
}

