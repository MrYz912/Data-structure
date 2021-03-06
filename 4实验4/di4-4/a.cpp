//利用静态链表建立赫夫曼树，建树过程中要求左子树权值小于右子树权值，求各结点的编码。要求：叶子结点的个数n及结点值由键盘录入。本题给出程序代码,要求修改以满足测试要求.
#include "stdio.h"
#include "malloc.h"
#include "string.h"
typedef struct{
   unsigned int weight;
   unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;

typedef char **HuffmanCode;

void   Select(HuffmanTree &HT, int n, int &s1, int &s2)
//在HT[1..n]中选择parent为0且weight最小的两个结点，
// 其序号分别为s1和s2。
{
    s1 = s2 = -1;
	int i;
    for (i=1;i<=n;i++)
    {
      if (HT[i].parent==0)
		if (s1==-1) s1=i;
		else
		  {
		      s2 = i;
		      break;
		  }
    }
    if(HT[s1].weight > HT[s2].weight)
    {
        int t = s1;
        s1 = s2;
        s2 = t;
    }
    for(i += 1;i<=n; ++i)
    {
        if(HT[i].parent == 0)
        {
            if(HT[i].weight<HT[s1].weight)
            {
                s2 = s1;
                s1 = i;
            }else if(HT[i].weight < HT[s2].weight)
            s2 = i;
        }
    }
    //i s1 s2
    //s1 i s2
  // 并求出n个字符的哈夫曼编码HC
}

 void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
 {
  int i, j, m, s1, s2, start;
  char *cd;
  HuffmanTree p;
  unsigned int c, f;
  if (n<=1) return;
  m = 2 * n - 1;
  HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));  // 0号单元未用
  for(p = HT +1, i = 1; i<=n; ++i, ++p, ++w)  *p = {*w, 0, 0, 0};
  for(;i<=m; ++i, ++p )  *p = {0, 0, 0, 0};
  for (i=n+1; i<=m; i++) {  // 建哈夫曼树
    // 在HT[1..i-1]中选择parent为0且weight最小的两个结点，
    // 其序号分别为s1和s2。
    Select(HT, i-1, s1, s2);
    HT[s1].parent = i;  HT[s2].parent = i;
    HT[i].lchild = s1;  HT[i].rchild = s2;
    HT[i].weight = HT[s1].weight + HT[s2].weight;
  }
   //--- 从叶子到根逆向求每个字符的哈夫曼编码 ---
  cd = (char *)malloc(n*sizeof(char));    // 分配求编码的工作空间
  cd[n-1] = '\0';                         // 编码结束符。
  for (i=1; i<=n; ++i) {                  // 逐个字符求哈夫曼编码
    start = n-1;                          // 编码结束符位置
    for (c=i, f=HT[i].parent; f!=0; c=f, f=HT[f].parent)
      // 从叶子到根逆向求编码
      if (HT[f].lchild==c) cd[--start] = '0';
      else cd[--start] = '1';
    HC[i] = (char *)malloc((n-start)*sizeof(char));
         // 为第i个字符编码分配空间
    strcpy(HC[i], &cd[start]);    // 从cd复制编码(串)到HC

  }
  free(cd);   //释放工作空间
} //HuffmanCoding

int main()
{
   int i,n;
   int *w;
   HuffmanTree HT;
   HuffmanCode HC;
   scanf("%d",&n);  //权值个数
   w=(int *)malloc(n*sizeof(int));
   for ( i=0;i<n;i++)  //录入权值
	 scanf("%d",&w[i]);

   HC=(char **)malloc((n+1)*sizeof(char*)); //0空间未用
   HT=(HuffmanTree)malloc((2*n+1+1)*sizeof(HTNode));//0空间未用
   HuffmanCoding(HT, HC, w, n);
   for (i = 1; i<n+1; i++){
	 puts(HC[i]);//输出哈夫曼编码
	 free(HC[i]);  //释放空间
   }
   free(HC);
   free(HT);
   return 0;
}//main


/*
输入格式
第一行：权值个数
第二行：输入n个权值，用空格分隔


输出格式
输出n行
每行表示各权值对应的哈夫曼编码


输入样例
8
5 29 7 8 14 23 3 11


输出样例
0001
10
1110
1111
110
01
0000
001
*/


