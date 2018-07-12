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
�ú���ʵ�ֿ������򣬲����ÿ�η���������Ľ��



�����ʽ
��һ�У��������������ؼ��ĸ���n
�ڶ��У�����n��������ؼ��֣��ÿո�ָ�����


�����ʽ
ÿ�����ÿ������Ľ��������֮����һ���ո�ָ�


��������
10
5 4 8 0 9 3 2 6 7 1


�������
1 4 2 0 3 5 9 6 7 8
0 1 2 4 3 5 9 6 7 8
0 1 2 4 3 5 9 6 7 8
0 1 2 3 4 5 9 6 7 8
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 7 6 8 9
0 1 2 3 4 5 6 7 8 9
*/
