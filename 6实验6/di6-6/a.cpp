#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct SqList
{
    int length;
    int *r;
}SqList;

void SelectSort(SqList *L)
{
    int i,j,k,min,temp;
    for(i=1;i<L->length;i++)
    {
        min=i;
        for(j=i+1;j<=L->length;j++)
        {
            if(L->r[min]>L->r[j])
                min=j;
        }
        if(i!=min)
        {
            temp=L->r[min];
            L->r[min]=L->r[i];
            L->r[i]=temp;
        }
        for(k=1;k<=L->length;k++)
        {
            printf("%d ",L->r[k]);
        }
        printf("\n");
    }
}

int main()
{
    SqList *L;
    L=(SqList *)malloc(sizeof(SqList));
    int size,i;
    scanf("%d",&size);
    L->r=(int *)malloc(sizeof(int)*(size+1));
    L->length=size;
    for(i=1;i<=size;i++)
    {
        scanf("%d",&L->r[i]);
    }
    SelectSort(L);
    return 0;
}
/*
用函数实现简单选择排序，并输出每趟排序的结果



输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
每行输出每趟排序的结果，数据之间用一个空格分隔


输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
0 4 8 5 9 3 2 6 7 1
0 1 8 5 9 3 2 6 7 4
0 1 2 5 9 3 8 6 7 4
0 1 2 3 9 5 8 6 7 4
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 6 8 7 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
*/
