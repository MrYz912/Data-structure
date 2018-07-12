/*用函数实现如下二叉排序树算法： 
（1） 插入新结点 
（2） 前序、中序、后序遍历二叉树 
（3） 中序遍历的非递归算法 
（4） 层次遍历二叉树 
（5） 在二叉树中查找给定关键字(函数返回值为成功1,失败0) 
（6） 交换各结点的左右子树 
（7） 求二叉树的深度 
（8） 叶子结点数


Input

第一行：准备建树的结点个数n 
第二行：输入n个整数，用空格分隔 
第三行：输入待查找的关键字 
第四行：输入待查找的关键字 
第五行：输入待插入的关键字

Output

第一行：二叉树的先序遍历序列 
第二行：二叉树的中序遍历序列 
第三行：二叉树的后序遍历序列 
第四行：查找结果 
第五行：查找结果 
第六行~第八行：插入新结点后的二叉树的先、中、序遍历序列 
第九行：插入新结点后的二叉树的中序遍历序列(非递归算法) 
第十行：插入新结点后的二叉树的层次遍历序列 
第十一行~第十三行：第一次交换各结点的左右子树后的先、中、后序遍历序列 
第十四行~第十六行：第二次交换各结点的左右子树后的先、中、后序遍历序列 
第十七行：二叉树的深度 
第十八行：叶子结点数

*/

#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;
typedef int KeyType;
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量
#define MAXQSIZE 100

typedef int  ElemType;
typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;


Status SearchBST(BiTree T,KeyType key,BiTree f,BiTree &p)
{
	if(!T){p=f;return FALSE;}
	else if(key==T->data){p=T;return TRUE;}
	else if(key<T->data)return SearchBST(T->lchild,key,T,p);
	else return(SearchBST(T->rchild,key,T,p));
}


Status InsertBST(BiTree &T,ElemType e)
{
	BiTree s,p;
        if(!SearchBST(T,e,NULL,p))
	{
		s=(BiTree)malloc(sizeof(BiTNode));
		s->data=e;s->lchild=s->rchild=NULL;
		if(!p)T=s;
		else if(e<p->data)p->lchild=s;
		else p->rchild=s;
		return TRUE;
	}
    else return FALSE;
}

Status PrintElement( ElemType e ) {  // 输出元素e的值
printf("%d ", e ); 
return OK;
}// PrintElement


Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) {
   // 前序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
   //补全代码,可用多个语句
    if(T)
	{
		if(Visit(T->data))
			if(PreOrderTraverse(T->lchild,Visit))
			if(PreOrderTraverse(T->rchild,Visit))return OK;
			return ERROR;
	}
	else return OK;
  
} // PreOrderTraverse

Status InOrderTraverse( BiTree T, Status(*Visit)(ElemType) )
 {
     // 中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    //补全代码,可用多个语句
	if(T)
	{
		if(InOrderTraverse(T->lchild,Visit))
			if(Visit(T->data))
				if(InOrderTraverse(T->rchild,Visit))
					return OK;
				return ERROR;
	}
     else return OK;
} // InOrderTraverse

Status PostOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) {
     // 后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
     //补全代码,可用多个语句
	if(T)
	{
        if(PostOrderTraverse(T->lchild,Visit))
			if(PostOrderTraverse(T->rchild,Visit))
				if(Visit(T->data))return OK;
				return ERROR;
	}
	else return OK;
    
} // PostOrderTraverse

Status Putout(BiTree T)
{
    PreOrderTraverse(T,PrintElement);
	printf("\n");
	InOrderTraverse(T, PrintElement);
    printf("\n");
	PostOrderTraverse(T,PrintElement);
    printf("\n"); 
	return OK;
}

//·······················非递归算法

struct SqStack
{
     BiTree *base; // 在栈构造之前和销毁之后，base的值为NULL
     BiTree *top; // 栈顶指针
     int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S)       
{      
   S.base=(BiTree *)malloc(STACK_INIT_SIZE*sizeof(BiTree));	
   if(!S.base)return ERROR;
   S.top=S.base;
   S.stacksize=STACK_INIT_SIZE;
   return OK;
}
Status Push(SqStack &S,BiTree e)   
{
   if((S.top-S.base)>=S.stacksize)
   {
	   S.base=(BiTree*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(BiTree));
       if(!S.base)return ERROR;
       S.top=S.base+S.stacksize;
       S.stacksize+=STACKINCREMENT;
   }
   *S.top++=e;
   return OK;
}

Status Pop(SqStack &S,BiTree &e)   
{
    if(S.top==S.base)return ERROR;
	e=*--S.top;
	return OK;	
}
Status StackEmpty(SqStack S)
 { // 若栈S为空栈，则返回TRUE，否则返回FALSE
   if(S.top-S.base==0)return TRUE;
   else return FALSE;
 }


Status InOrderTraverse1(BiTree T,Status(*Visit)(ElemType e),SqStack S)
{
	BiTree p;
	InitStack(S);p=T;
	while(p||!StackEmpty(S))
	{
		if(p){Push(S,p);p=p->lchild;}
		else 
		{
			Pop(S,p);
			if(!Visit(p->data))return ERROR;
			p=p->rchild;
		}
	}
	return OK;
}

//···························层次遍历

typedef struct
{
   BiTree *base; // 初始化的动态分配存储空间
   int front; // 头指针,若队列不空,指向队列头元素
   int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置
 }SqQueue;

Status InitQueue(SqQueue &Q)   
{
   Q.base=(BiTree*)malloc(MAXQSIZE*sizeof(BiTree));
   if(!Q.base)return ERROR;
   Q.front=Q.rear=0;
   return OK;
}
int QueueLength(SqQueue Q)  
{
// 返回Q的元素个数
// 请补全代码
   return(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;	
}

Status EnQueue(SqQueue &Q,BiTree e)  
{ 
// 插入元素e为Q的新的队尾元素
// 请补全代码
   if((Q.rear+1)%MAXQSIZE==Q.front)return ERROR;
   Q.base[Q.rear]=e;
   Q.rear=(Q.rear+1)%MAXQSIZE;
   return OK;
}

Status DeQueue(SqQueue &Q,BiTree &e) 
{  
// 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
// 请补全代码
   if(Q.front==Q.rear)return ERROR;
   e=Q.base[Q.front];
   Q.front=(Q.front+1)%MAXQSIZE;
   return OK;
}

Status LevelTraverse(BiTree T,SqQueue Q)//层次遍历二叉树
{
	InitQueue(Q);
	BiTree p;
	p=T;
	if(T)EnQueue(Q,T);
//	printf("%d",QueueLength(Q));
	while(QueueLength(Q)!=0)
	{
		DeQueue(Q,p);   //根结点出队
		printf("%d ",p->data);   //输出数据
		if(p->lchild)EnQueue(Q,p->lchild);  //左孩子进队
		if(p->rchild)EnQueue(Q,p->rchild);  //右孩子进队
      
	}
	return OK;
} 



void Change(BiTree T)
{
	BiTNode *p;
	if(T)
	{p=T->lchild;
	T->lchild=T->rchild;
	T->rchild=p;
	Change(T->lchild);
	Change(T->rchild);
	}
   // return OK;
}





int BTreeDepth(BiTree T)  
  //求由BT指针指向的一棵二叉树的深度  
{
	
//	int dep1,dep2;
    if(T!=NULL)
	{
  //计算左子树的深度  
        int dep1=BTreeDepth(T->lchild);  
  //计算右子树的深度  
        int dep2=BTreeDepth(T->rchild);  
  //返回树的深度  
        if(dep1>dep2)  
        return dep1+1;  
        else 
			return dep2+1;  
	}
	else return 0;
}  
//`````````````叶子结点数
Status yezhi(BiTree T,SqQueue Q)
{
	int i=0;
	InitQueue(Q);
	BiTree p;
	p=T;
	if(T)EnQueue(Q,T);
//	printf("%d",QueueLength(Q));
	while(QueueLength(Q)!=0)
	{
		DeQueue(Q,p);
		if(p->lchild)EnQueue(Q,p->lchild);
		if(p->rchild)EnQueue(Q,p->rchild);
		if(!p->lchild&&!p->rchild)
         i++;    
	}
	return i;
} 



int main()   //主函数
{
    SqStack S;
	SqQueue Q,Q3;
	BiTree T=NULL,f,p;
	int i,n,e,a,b,c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
        InsertBST(T,e);		
	}
    
	scanf("%d",&a);scanf("%d",&b);scanf("%d",&c);Putout(T);
	printf("%d\n",SearchBST(T,a,f,p));
	
	printf("%d\n",SearchBST(T,b,f,p));
	
	InsertBST(T,c);
	Putout(T);
	InOrderTraverse1(T, PrintElement,S);
    printf("\n");
	LevelTraverse(T,Q);
	printf("\n");
   Change(T);
	Putout(T);
	Change(T);
	Putout(T);
	printf("%d",BTreeDepth(T));
	printf("\n");
	printf("%d",yezhi(T,Q3));
	printf("\n");
	return OK;

}//main

