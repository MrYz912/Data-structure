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
�ú���ʵ��ϣ��(shell)���򣬲����ÿ������Ľ��,��ʼ����d=n/2,���d=d/2



�����ʽ
��һ�У��������������ؼ��ĸ���n
�ڶ��У�����n��������ؼ��֣��ÿո�ָ�����


�����ʽ
ÿ�����һ��������������֮����һ���ո�ָ�


��������
10
5 4 8 0 9 3 2 6 7 1


�������
3 2 6 0 1 5 4 8 7 9
1 0 3 2 4 5 6 8 7 9
0 1 2 3 4 5 6 7 8 9
*/
