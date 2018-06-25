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
LISTPTR add_to_list(int m,LISTPTR n );//添加函数 
void show_list(LISTPTR);//显示函数 
void free_memory(LISTPTR s);//内存释放函数 
	
int main(void)
{
    LISTPTR head=NULL;//head指针初始值为0 
	int i=0,ch;
	char trash[256];
	 
	while(i++<5) //一共读取5次 
	{

	 ch=0;
	 printf("\n enter character  第%d次",i);
	
	   do 
	    {
		 printf("\n must be a to z:");
		 ch=getc(stdin);//getc函数从流中读取字符并传给变量ch 
		 gets(trash);//从缓存区读取字符 
	    }
	   while((ch<'a'||ch>'z') && (ch<'A'||ch>'Z'));//输入的字符所需要满足的条件 
	 
	    head=add_to_list(ch,head);
    }
    
	    show_list(head);
	
	    free_memory_list(head);
	     
	    return 0; 
	
}


LISTPTR add_to_list(int g,LISTPTR h)//这个函数把每次接受到的字符储存起来 
{
	LISTPTR new_rec=NULL;
    LISTPTR current_rec=NULL;
    LISTPTR prev_rec=NULL;
    new_rec=(LISTPTR)malloc(sizeof(LIST));
    if (!new_rec)//注意一下内存分配不成功的写法 
    {
    	printf("分配内存不成功");
		exit(1);
		 
	}
	new_rec->ch=g;
    new_rec->next_ptr=NULL;
	
}



if (head==NULL)//如果head为 NULL，则字符放在head的后面 
{
	head=new_rec;
	new_rec->next_ptr=NULL;
}

  else
  {
	if(new_rec->ch < head->ch)//如果比前一个字符小 
	{
		new_rec->next_ptr=head;//此元素指向下一个字符的地址 
		head=new_rec;//head所指的地址替换为此元素的地址 
    
		else//否则则是此元素的比前一个字符大 
		{
			current_rec=head->next_ptr;//current的地址 为前一个字母的 next地址 
			prev_rec=head;// 
	    
			if (current_rec=NULL)//如果前一个字母的next指针指向末尾 （即地址为 NULL） 
			{
				pre_rec->next_ptr=new_rec;//直接使前一个字母的next指针指向新字母	
			
			  else//如果前一个字母的next指针地址不为 NULL 此时要插入的的字母前方有两个 
			  {
				while((current_rec->next_ptr!=NULL))//如果前一个字母 next指针不指向末尾 
				{
					if(new_rec->ch<current_rec->ch)//此时例插入字母为c，前两个为a，b 
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
