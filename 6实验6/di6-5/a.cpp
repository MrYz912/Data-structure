#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct SqList
{
    int length;
    int *r;
}SqList;

int Partition(SqList *L,int low,int high)
{
        L->r[0]=L->r[low];
        int x=L->r[low];
        while(low<high)
        {
            while(low<high&&L->r[high]>=x)
                --high;
                L->r[low]=L->r[high];
            while(low<high&&L->r[low]<x)
                ++low;
                L->r[high]=L->r[low];
        }
        L->r[low]=L->r[0];
        return low;
}

void QSort(SqList *L,int low,int high)
{
    int k,x;
    if(low<high)
    {
    x=Partition(L,low,high);
    for(k=1;k<=L->length;k++)
    {
        printf("%d ",L->r[k]);
    }
    printf("\n");
    QSort(L,low,x-1);
    QSort(L,x+1,high);
    }
}

int main()
{
    SqList *L;
    L=(SqList *)malloc(sizeof(SqList));
    int size,i,low,high;
    scanf("%d",&size);
    L->r=(int *)malloc(sizeof(int)*(size+1));
    L->length=size;
    low=1;
    high=size;
    for(i=1;i<=size;i++)
    {
        scanf("%d",&L->r[i]);
    }
    QSort(L,low,high);
    return 0;
}

/*
用函数实现快速排序，并输出每次分区后排序的结果



输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
每行输出每趟排序的结果，数据之间用一个空格分隔


输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
1 4 2 0 3 5 9 6 7 8
0 1 2 4 3 5 9 6 7 8
0 1 2 4 3 5 9 6 7 8
0 1 2 3 4 5 9 6 7 8
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 7 6 8 9
0 1 2 3 4 5 6 7 8 9
*/
