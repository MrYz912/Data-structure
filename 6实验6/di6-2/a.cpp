#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct sqList
{
    int length;
    int *r;
}SqList;

void BInsertSort(SqList *L)
{
    int i,j,m,low,high,k;
    for(i=2;i<=L->length;++i)
    {
        L->r[0]=L->r[i];
        low=1;high=i-1;
        while(low<=high)
        {
            m=(low+high)/2;
            if(L->r[0]<L->r[m])
                high=m-1;
            else
                low=m+1;
        }
        for(j=i-1;j>=high+1;--j)
        L->r[j+1]=L->r[j];
        L->r[high+1]=L->r[0];
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
    L->r=(int *)malloc(sizeof(int) *(size+1));
    L->length=size;
    for(i=1;i<=size;i++)
        scanf("%d",&L->r[i]);
    BInsertSort(L);
    return 0;
}

/*
用函数实现折半插入排序，并输出每趟排序的结果.



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
