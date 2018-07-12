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
�ú���ʵ��ð�����򣬲����ÿ������Ľ��(Ҫ��һ��ð�ݹ����в��������ݽ��������������)



�����ʽ
��һ�У��������������ؼ��ĸ���n
�ڶ��У�����n��������ؼ��֣��ÿո�ָ�����


�����ʽ
ÿ�����ÿ��������������֮����һ���ո�ָ�


��������
10
5 4 8 0 9 3 2 6 7 1


�������
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
