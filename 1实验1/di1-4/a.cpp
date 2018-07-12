//编写算法，创建一个含有n个元素的带头结点的单链表L并实现插入、删除、遍历操作。本题目提供部分代码，请补全内容。
#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1 
#define ElemType int

typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;

int CreateLink_L(LinkList &L,int n){
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

int LoadLink_L(LinkList &L){
// 单链表遍历
 LinkList p = L->next;
 if(L==NULL)printf("The List is empty!"); // 请填空
 else
 {
	 printf("The LinkList is:");
	 while(p!=NULL)    // 请填空
	 {
		printf("%d ",p->data); 
		p=p->next;    // 请填空
	 }
 }
 printf("\n");
 return OK;
}

int GetLength(LinkList &L)
{
  int i=0;
  LinkList p;
  p=L;
  while(p->next!=NULL)
  {
    i++;
    p=p->next;
  }
  return i;
}

int LinkInsert_L(LinkList &L,int i,ElemType e)
{
  LinkList p,s;
  int j;
  p=L;
  j=1;
  while (p&&j<i)
  {
    p=p->next;
    ++j;
  }
  if(!p||j>i)
      return ERROR;
  s=(LinkList) malloc (sizeof(LNode));
  s->data=e;
  s->next=p->next;
  p->next=s;
  return OK;
// 算法2.9
// 在带头结点的单链线性表L中第i个位置之前插入元素e
// 请补全代码

}

int LinkDelete_L(LinkList L,int i, ElemType &e)
{
    int j;
    LinkList p,q;
    p=L;
    j=1;
    while (p->next && j<i)
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i)
        return ERROR;
    q=p->next;
    p->next =q->next;
    e = q->data;
    free(q);
    return OK;
// 算法2.10
// 在带头结点的单链线性表L中，删除第i个元素，并用e返回其值
// 请补全代码

}

int main()
{
 LinkList T;
 int a,n,i;
 ElemType x, e;
 printf("Please input the init size of the linklist:\n");
 scanf("%d",&n);
 printf("Please input the %d element of the linklist:\n", n);
 if(CreateLink_L(T,n))     // 判断链表是否创建成功，请填空
 {
	 printf("A Link List Has Created.\n");
	 LoadLink_L(T);
 }
 while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
				  if(LinkInsert_L(T,i,x)==0) printf("Insert Error!\n"); // 判断i值是否合法，请填空
				  else printf("The Element %d is Successfully Inserted!\n", x); 
				  break;
			case 2: scanf("%d",&i);
				if(LinkDelete_L(T,i,e)==0) printf("Delete Error!\n"); // 判断i值是否合法，请填空
				  else printf("The Element %d is Successfully Deleted!\n", e);
				  break;
			case 3: LoadLink_L(T);
				  break;
			case 0: return 1;
		}
	}
}


/*
输入格式
测试样例格式说明：
根据菜单操作：
1、输入1，表示要实现插入操作，紧跟着要输入插入的位置和元素，用空格分开
2、输入2，表示要实现删除操作，紧跟着要输入删除的位置
3、输入3，表示要输出顺序表的所有元素
4、输入0，表示程序结束


输入样例
3
3 6 9
3
1
4 12
2
1
3
0


输出样例
Please input the init size of the linklist:
Please input the 3 element of the linklist:
A Link List Has Created.
The LinkList is:3 6 9 
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The LinkList is:3 6 9 
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The Element 12 is Successfully Inserted!
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The Element 3 is Successfully Deleted!
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The LinkList is:6 9 12 
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
*/
