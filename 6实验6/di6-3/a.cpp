#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct SqList
{
    int length;
    int *r;
}SqList;

void ShellSort(SqList *L)
{
    int i,j,k;
    int increment=L->length;
    do
    {
        increment=increment/2;
        for(i=increment+1;i<=L->length;i++)
        {
            if(L->r[i]<L->r[i-increment])
            {
                L->r[0]=L->r[i];
                for(j=i-increment;j>0&&L->r[0]<L->r[j];j=j-increment)
                    L->r[j+increment]=L->r[j];
                L->r[j+increment]=L->r[0];
            }
        }
        for(k=1;k<=L->length;k++)
            printf("%d ",L->r[k]);
        printf("\n");
    }
    while(increment>1);
}

int main()
{
    SqList *L;
    L=(SqList *)malloc(sizeof(SqList));
    int size,i;
    scanf("%d",&size);
    L->r=(int *)malloc(sizeof(int)*(size + 1));
    L->length=size;
    for(i=1;i<=size;i++)
    {
        scanf("%d",&L->r[i]);
    }
    ShellSort(L);
    return 0;
}

/*
用函数实现希尔(shell)排序，并输出每趟排序的结果,初始增量d=n/2,其后d=d/2



输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
每行输出一趟排序结果，数据之间用一个空格分隔


输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
3 2 6 0 1 5 4 8 7 9
1 0 3 2 4 5 6 8 7 9
0 1 2 3 4 5 6 7 8 9
*/
