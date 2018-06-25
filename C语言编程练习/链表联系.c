#include <stdio.h>
#include <stdlib.h>
#ifndef NULL
 #define NULL 0
#endif
struct list {
	int ch;
	struct list* next_ptr;
	
};
typedef struct list LIST;
typedef LIST* LISTPTR;
LISTPTR add_to_list(int m,LISTPTR n );//��Ӻ��� 
void show_list(LISTPTR);//��ʾ���� 
void free_memory(LISTPTR s);//�ڴ��ͷź��� 
	
int main(void)
{
    LISTPTR head=NULL;//headָ���ʼֵΪ0 
	int i=0,ch;
	char trash[256];
	 
	while(i++<5) //һ����ȡ5�� 
	{

	 ch=0;
	 printf("\n enter character  ��%d��",i);
	
	   do 
	    {
		 printf("\n must be a to z:");
		 ch=getc(stdin);//getc���������ж�ȡ�ַ�����������ch 
		 gets(trash);//�ӻ�������ȡ�ַ� 
	    }
	   while((ch<'a'||ch>'z') && (ch<'A'||ch>'Z'));//������ַ�����Ҫ��������� 
	 
	    head=add_to_list(ch,head);
    }
    
	    show_list(head);
	
	    free_memory_list(head);
	     
	    return 0; 
	
}


LISTPTR add_to_list(int g,LISTPTR h)//���������ÿ�ν��ܵ����ַ��������� 
{
	LISTPTR new_rec=NULL;
    LISTPTR current_rec=NULL;
    LISTPTR prev_rec=NULL;
    new_rec=(LISTPTR)malloc(sizeof(LIST));
    if (!new_rec)//ע��һ���ڴ���䲻�ɹ���д�� 
    {
    	printf("�����ڴ治�ɹ�");
		exit(1);
		 
	}
	new_rec->ch=g;
    new_rec->next_ptr=NULL;
	
}



if (head==NULL)//���headΪ NULL�����ַ�����head�ĺ��� 
{
	head=new_rec;
	new_rec->next_ptr=NULL;
}

  else
  {
	if(new_rec->ch < head->ch)//�����ǰһ���ַ�С 
	{
		new_rec->next_ptr=head;//��Ԫ��ָ����һ���ַ��ĵ�ַ 
		head=new_rec;//head��ָ�ĵ�ַ�滻Ϊ��Ԫ�صĵ�ַ 
    
		else//�������Ǵ�Ԫ�صı�ǰһ���ַ��� 
		{
			current_rec=head->next_ptr;//current�ĵ�ַ Ϊǰһ����ĸ�� next��ַ 
			prev_rec=head;// 
	    
			if (current_rec=NULL)//���ǰһ����ĸ��nextָ��ָ��ĩβ ������ַΪ NULL�� 
			{
				pre_rec->next_ptr=new_rec;//ֱ��ʹǰһ����ĸ��nextָ��ָ������ĸ	
			
			  else//���ǰһ����ĸ��nextָ���ַ��Ϊ NULL ��ʱҪ����ĵ���ĸǰ�������� 
			  {
				while((current_rec->next_ptr!=NULL))//���ǰһ����ĸ nextָ�벻ָ��ĩβ 
				{
					if(new_rec->ch<current_rec->ch)//��ʱ��������ĸΪc��ǰ����Ϊa��b 
					{
						new_rec->next_ptr=current_rec;
				    
						/*if(new_rec->next_ptr!=prev_rec->next_ptr)
						{
							printf("ERROR");
							getc(stdin);
							exit(0);
						}*/
						
						
						prev_rec->next_ptr=new_rec;
						break;
					    
						
					
					 else
					 {
					 current_rec=current_rec->next_ptr;
				     prev_rec=prev_rec->next_ptr;	
					 }
				   }
					
			   }
		      }
				
				if(current_rec->next_ptr==NULL)
				{
					if(new_rec->ch<current_rec->ch)
					{
						new_rec->next_ptr=current_rec;
						prev_rec->next_ptr=new_rec;
					  
					    else
					    {
						current_rec->next_ptr=new_rec;
						new_rec->next_ptr=NULL;
						
					    }
					}		
				}
		    }
	    }
    }
		
  }

	return (head);
	
}


void show_list(LISTPTR head)
{
	LISTPTR cur_ptr;
	int counter=1;
	printf("\n\nRec addr  Position  Data  Next Rec addr\n");
	cur_ptr=head;
	while(cur_ptr!=NULL)
	{
		printf("%X",cur_ptr);
		printf("    %i      %c",counter++,cur_ptr->ch);
		printf("     %X   \n",cur_ptr->next_ptr);
		cur_ptr=cur_ptr->next_ptr;
	}
}

void free_memory_list (LISTPTR s)
{
	LISTPTR cur_ptr,next_ptr;
	cur_ptr=s;
	while(cur_ptr!=NULL)
	{
		next_ptr=cur_ptr->next_ptr;
		free(cur_ptr);
		cur_ptr=next_ptr;
		
	}
}
