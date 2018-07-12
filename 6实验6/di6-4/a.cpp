#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct SqList
{
    int length;
    int *r;
}SqList;

void BubbleSort(SqList *L)
{
    int i,j,k,temp;
    int flag=1;
    for(i=1;i<=L->length&&flag;i++)
    {
        flag=0;
        for(j=1;j<=L->length-i;j++)
        {
            if(L->r[j]>L->r[j+1])
            {
                temp=L->r[j];
                L->r[j]=L->r[j+1];
                L->r[j+1]=temp;
                flag=1;
            }
        }
        for(k=1;k<=L->length;k++)
            printf("%d ",L->r[k]);
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
        scanf("%d",&L->r[i]);
    BubbleSort(L);
    return 0;
}

/*
用函数实现冒泡排序，并输出每趟排序的结果(要求当一趟冒泡过程中不再有数据交换，则排序结束)



输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
每行输出每趟排序结果，数据之间用一个空格分隔


输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
4 5 0 8 3 2 6 7 1 9
4 0 5 3 2 6 7 1 8 9
0 4 3 2 5 6 1 7 8 9
0 3 2 4 5 1 6 7 8 9
0 2 3 4 1 5 6 7 8 9
0 2 3 1 4 5 6 7 8 9
0 2 1 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9

*/
