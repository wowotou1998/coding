#include<stdio.h>
//引入外部变量和外部函数 
extern int p(void);   //指定p函数为其他文件里的函数 
extern int i;   //指定i为其他文件里的函数 不可以在这里 extern int i = 8；这样就重定义了 
extern unsigned char key;//指定key为其他文件里的函数 
int main() {   
    p();   
    printf("%c",key);
    system("pause");       
    return 0;        
}  

