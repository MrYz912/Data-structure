#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct sqList
{
    int length;
    int *a;
}SqList;

void InsertSort(SqList *L)
{
    int i,j,k;
    if(L->length==1)
        printf("%d\n",L->a[1]);
    else{
    for(i=2;i<=L->length;i++)
    {
        if(L->a[i]<L->a[i-1])
        {
            L->a[0]=L->a[i];
            for(j=i-1;L->a[j]>L->a[0];j--)
                L->a[j+1]=L->a[j];
            L->a[j+1]=L->a[0];
        }
        for(k=1;k<=L->length;k++)
            printf("%d ",L->a[k]);
        printf("\n");
    }
    }
}

int main()
{
    SqList *L;
    L = (SqList *)malloc(sizeof(SqList));
    int size,i;
    scanf("%d",&size);
    L->a = (int *)malloc(sizeof(int) * (size + 1));
    L->length=size;
    for(i=1;i<=size;i++)
    {
        scanf("%d",&L->a[i]);
    }
    InsertSort(L);
    return 0;
}

/*
用函数实现直接插入排序，并输出每趟排序的结果.



输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
每行输出一趟排序结果，数据之间用一个空格分隔


输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
4 5 8 0 9 3 2 6 7 1
4 5 8 0 9 3 2 6 7 1
0 4 5 8 9 3 2 6 7 1
0 4 5 8 9 3 2 6 7 1
0 3 4 5 8 9 2 6 7 1
0 2 3 4 5 8 9 6 7 1
0 2 3 4 5 6 8 9 7 1
0 2 3 4 5 6 7 8 9 1
0 1 2 3 4 5 6 7 8 9

*/
