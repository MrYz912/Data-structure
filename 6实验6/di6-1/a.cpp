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
�ú���ʵ��ֱ�Ӳ������򣬲����ÿ������Ľ��.



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
