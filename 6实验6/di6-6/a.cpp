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
�ú���ʵ�ּ�ѡ�����򣬲����ÿ������Ľ��



�����ʽ
��һ�У��������������ؼ��ĸ���n
�ڶ��У�����n��������ؼ��֣��ÿո�ָ�����


�����ʽ
ÿ�����ÿ������Ľ��������֮����һ���ո�ָ�


��������
10
5 4 8 0 9 3 2 6 7 1


�������
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
