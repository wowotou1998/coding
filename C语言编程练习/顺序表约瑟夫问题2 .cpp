#include<stdio.h>
#define MaxNum 100
typedef struct
{
    int data[MaxNum];
    int length;
}SqList;

int main()
{
    SqList L;
    int i,j,k=1,e,m;
    printf("������������n�ͳ�ʼֵm��\n");
    scanf("%d%d",&L.length,&m);
    for(i=0;i<L.length;i++)
    L.data[i]=i+1;
    int a[L.length];
    printf("���������룺");
    for(i=0;i<L.length;i++)
    scanf("%d",&a[i]);
    printf("����˳��Ϊ��");
    while(L.length!=0)
    {
        k--;
        i=(k+m-1)%(L.length);
        e=L.data[i];
        printf("%d\t",e);
        m=a[i];
        for(j=i;j<L.length-1;j++)
        {
           L.data[j]=L.data[j+1];
           a[j]=a[j+1];
        }
        L.length--;
        k=i+1;
    }
    printf("\n");
    return 0;
}
