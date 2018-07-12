//线性链表的基本操作如下：
#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1 
#define ElemType int

typedef int Status;
typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;


Status ListInsert_L(LinkList &L, int i, ElemType e) 
{  // 算法2.9
  // 在带头结点的单链线性表L的第i个元素之前插入元素e
  LinkList p,s;
  p = L;   
  int j = 0;
  while (p && j < i-1) {  // 寻找第i-1个结点
    p = p->next;
    ++j;
  } 
  if (!p || j > i-1) return ERROR;      // i小于1或者大于表长
  s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
  s->data = e;  s->next = p->next;      // 插入L中
  p->next = s;
  return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e) 
{  // 算法2.10
  // 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
  LinkList p,q;
  p = L;
  int j = 0;
  while (p->next && j < i-1) {  // 寻找第i个结点，并令p指向其前趋
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i-1) return ERROR;  // 删除位置不合理
  q = p->next;
  p->next = q->next;           // 删除并释放结点
  e = q->data;
  free(q);
  return OK;
} // ListDelete_L

int CreateLink_L(LinkList &L,int n)
{
// 创建含有n个元素的单链表
  LinkList p,q;
  int i;
  ElemType e;
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;              // 先建立一个带头结点的单链表
  q = (LinkList)malloc(sizeof(LNode));
  q = L;
  for (i=0; i<n; i++)
  {
    scanf("%d", &e);
    p = (LinkList)malloc(sizeof(LNode));  // 生成新结点
    p->data=e;
    p->next=NULL;
    q->next=p;
    q=p;// 请补全代码

  }
  return OK;
}

void Hebing(LinkList &C,LinkList B,int c,int d)
{//合并B,C链表并排序
    LinkList q,s,p,pmin;
    int temp,e;
    int i=1;
    e=c+d;
    q=B->next;
    s=C->next;
    while(q!=NULL)
    {
        ListInsert_L(C,i,q->data);
        q=q->next;
        i++;
    }
    for(p=C;p->next!=NULL;p=p->next)
    {
        pmin=p;
        q=pmin->next;
        for(q->next;q;q=q->next)
        {
            if(q->data<pmin->data)
            {
                pmin=q;
            }
        }
        if(pmin!=p)
        {
            temp=pmin->data;
            pmin->data=p->data;
            p->data=temp;
        }
    }
}

int main()
{
    LinkList A,B,C,p,q,s;
	int a,b,i;
	scanf("%d",&a);
	CreateLink_L(A,a);
    p=A->next;
	scanf("%d",&b);
	CreateLink_L(B,b);
    q=B->next;
    CreateLink_L(C,0);
    for(i=1;i<=a;i++)
    {
       ListInsert_L(C,i,p->data);
       p=p->next;
    }
    p=A->next;
    printf("List A:");
    for(i=1;i<=a;i++)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    printf("List B:");
    for(i=1;i<=b;i++)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    Hebing(C,B,a,b);
    s=C->next;
    printf("\n");
    printf("List C:");
    for(i=1;i<=a+b;i++)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    
    return 0;
}

/*
设计一个算法将两个非递减有序链表A和B合并成一个新的非递减有序链表C。



输入格式
第一行：单链表A的元素个数
第二行：单链表A的各元素（非递减），用空格分开
第三行：单链表B的元素个数
第四行：单链表B的各元素（非递减），用空格分开


输出格式
第一行：单链表A的元素列表
第二行：单链表B的元素列表
第三行：合并后单链表C的元素列表


输入样例
6
12 24 45 62 84 96
4
15 31 75 86


输出样例
List A:12 24 45 62 84 96 
List B:15 31 75 86 
List C:12 15 24 31 45 62 75 84 86 96
*/
