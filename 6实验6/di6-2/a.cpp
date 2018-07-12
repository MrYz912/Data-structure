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
�ú���ʵ���۰�������򣬲����ÿ������Ľ��.



�����ʽ
��һ�У��������������ؼ��ĸ���n
�ڶ��У�����n��������ؼ��֣��ÿո�ָ�����


�����ʽ
ÿ�����һ��������������֮����һ���ո�ָ�


��������
10
5 4 8 0 9 3 2 6 7 1


�������
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
