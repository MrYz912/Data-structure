//构造二叉链表表示的二叉树：按先序次序输入二叉树中结点的值（一个字符），'#'字符表示空树，构造二叉链表表示的二叉树T；再输出三种遍历序列。本题只给出部分代码,请补全内容。
#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;

typedef char  ElemType;
typedef struct BiTNode
{
  ElemType data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T) 
{  // 算法6.4
  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
  // 构造二叉链表表示的二叉树T。
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data=ch;// 生成根结点
    CreateBiTree(T->lchild); // 构造左子树
    CreateBiTree(T->rchild); // 构造右子树
  }
  return OK;
} // CreateBiTree


Status PrintElement( ElemType e ) 
{  // 输出元素e的值
    printf("%c", e ); 
    return OK;
}// PrintElement


Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) 
{
    if(T)
    {
        if(Visit(T->data))
            if(PreOrderTraverse(T->lchild,Visit))
                if(PreOrderTraverse(T->rchild,Visit))
                    return OK;
        return ERROR;
    }
    else
        return OK;
   // 前序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
   //补全代码,可用多个语句
  
} // PreOrderTraverse

Status InOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) 
{
    if(T)
    {
        if(InOrderTraverse(T->lchild,Visit))
            if(Visit(T->data))
                if(InOrderTraverse(T->rchild,Visit))
                        return OK;
        return ERROR;
    }
    else
        return OK;
     // 中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    //补全代码,可用多个语句
    
} // InOrderTraverse

Status PostOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) 
{
    if(T)
    {
        if(PostOrderTraverse(T->lchild,Visit))
            if(PostOrderTraverse(T->rchild,Visit))
                if(Visit(T->data))
                    return OK;
        return ERROR;
    }
    else
        return OK;
     // 后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
     //补全代码,可用多个语句
    
} // PostOrderTraverse



int main()   //主函数
{
    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    return 0;
                      //补充代码
}//main



/*
输入格式
第一行：输入一棵二叉树的先序遍历序列


输出格式
第一行：二叉树的先序遍历序列
第二行：二叉树的中序遍历序列
第三行：二叉树的后序遍历序列


输入样例
AB##C##


输出样例
ABC
BAC
BCA
*/
