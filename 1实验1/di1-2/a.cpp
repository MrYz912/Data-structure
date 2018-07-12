#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef int Status;
typedef struct
{
    int *elem;
    int length;
    int listsize;
}SqList;

Status InitList_Sq(SqList &L)
{  // 算法2.3
  // 构造一个空的线性表L。
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if (!L.elem) return OK;        // 存储分配失败
  L.length = 0;                  // 空表长度为0
  L.listsize = LIST_INIT_SIZE;   // 初始存储容量
  return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{  // 算法2.4
  // 在顺序线性表L的第i个元素之前插入新的元素e，
  // i的合法值为1≤i≤ListLength_Sq(L)+1
  ElemType *p;
  if (i < 1 || i > L.length+1) return ERROR;  // i值不合法
  if (L.length >= L.listsize) {   // 当前存储空间已满，增加容量
    ElemType *newbase = (ElemType *)realloc(L.elem,
                  (L.listsize+LISTINCREMENT)*sizeof (ElemType));
    if (!newbase) return ERROR;   // 存储分配失败
    L.elem = newbase;             // 新基址
    L.listsize += LISTINCREMENT;  // 增加存储容量
  }
  ElemType *q = &(L.elem[i-1]);   // q为插入位置
  for (p = &(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
                                  // 插入位置及之后的元素右移
  *q = e;       // 插入e
  ++L.length;   // 表长增1
  return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{  // 算法2.5
  // 在顺序线性表L中删除第i个元素，并用e返回其值。
  // i的合法值为1≤i≤ListLength_Sq(L)。
  ElemType *p, *q;
  if (i<1 || i>L.length) return ERROR;  // i值不合法
  p = &(L.elem[i-1]);                   // p为被删除元素的位置
  e = *p;                               // 被删除元素的值赋给e
  q = L.elem+L.length-1;                // 表尾元素的位置
  for (++p; p<=q; ++p) *(p-1) = *p;     // 被删除元素之后的元素左移
  --L.length;                           // 表长减1
  return OK;
} // ListDelete_Sq

void MergeList_Sq(SqList La,SqList Lb,SqList &Lc)
{
    int i,k,temp;
    for(i=1;i<=La.length;i++)
    {
        ListInsert_Sq(Lc,i,La.elem[i-1]);
    }
    Lc.length=La.length;
    k=0;
    for(i=0;k<Lb.length;i++)
    {
	ListInsert_Sq(Lc,k+1,Lb.elem[i]);
   	 k++;
    }
    for(i=0;i<Lc.length-1;i++)
    {
        for(k=0;k<Lc.length-1-i;k++)
        {
            if(Lc.elem[k]>Lc.elem[k+1])
            {
                temp=Lc.elem[k];
                Lc.elem[k]=Lc.elem[k+1];
                Lc.elem[k+1]=temp;
            }
        }
    }
}//MergeList_Sq

int main()
{
    SqList La,Lb,Lc;
    InitList_Sq(La);
    int a,i,e1,e2,b,k,j;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&e1);
        ListInsert_Sq(La,i+1,e1);
    }
    InitList_Sq(Lb);
    scanf("%d",&b);
    for(k=0;k<b;k++)
    {
        scanf("%d",&e2);
        ListInsert_Sq(Lb,k+1,e2);
    }
    InitList_Sq(Lc);
    j=i+k;

    printf("List A:");
    for(i=0;i<a;i++)
    {
        printf("%d ",La.elem[i]);
    }
    printf("\n");
    printf("List B:");
    for(k=0;k<b;k++)
    {
        printf("%d ",Lb.elem[k]);
    }
    printf("\n");
    MergeList_Sq(La,Lb,Lc);
    printf("List C:");
    for(i=0;i<j;i++)
    {
        printf("%d ",Lc.elem[i]);
    }
}
/*编写算法，将两个非递减有序顺序表A和B合并成一个新的非递减有序顺序表C。


#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#defi
输入格式
第一行：顺序表A的元素个数
第二行：顺序表A的各元素（非递减），用空格分开
第三行：顺序表B的元素个数
第四行：顺序表B的各元素（非递减），用空格分开


输出格式
第一行：顺序表A的元素列表
第二行：顺序表B的元素列表
第三行：合并后顺序表C的元素列表


输入样例
5
1 3 5 7 9
5
2 4 6 8 10


输出样例
List A:1 3 5 7 9
List B:2 4 6 8 10
List C:1 2 3 4 5 6 7 8 9 10
*/

