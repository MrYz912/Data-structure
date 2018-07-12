//编写Search_Bin函数，实现在一个递增有序数组ST中采用折半查找法确定元素位置的算法. 
#include"malloc.h" /* malloc()等 */ 
#include"stdio.h"
#include"stdlib.h"

typedef int ElemType; 
typedef struct /*静态查找表的顺序存储结构 */ 
{ 
	ElemType *elem; /* 数据元素存储空间基址，建表时按实际长度分配，0号单元留空 */ 
	int length; /* 表长度 */ 
}SSTable; 

void Creat_Seq(SSTable &ST,int n) 
{ /* 操作结果: 构造一个含n个数据元素的静态顺序查找表ST(数据来自数组r) */ 
	int i,temp; 
	ST.elem=(ElemType *)malloc((n+1) * sizeof(ElemType)); /* 动态生成n个数据元素空间(0号单元不用) */ 
	if(!(ST).elem) 
	{
		printf("ERROR\n");
		exit(0);
	} /*内存分配失败结束程序*/ 
	for(i=1;i<=n;i++) 
	{ 
		scanf("%d",&temp); 
		*(ST.elem+i)=temp; /* 依次赋值给ST */ 
	} 
	ST.length=n; 
} 

int Search_Seq(SSTable &ST,ElemType key) 
{ /* 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为 */ 
/* 该元素在表中的位置，否则为0。算法9.2 */ 
    int low,high,mid;
    low=1;
    high=ST.length;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key<ST.elem[mid])
            high=mid-1;
        else if(key>ST.elem[mid])
            low=mid+1;
        else
            return mid;
    }
    return 0;
} 

main() 
{ 
	SSTable ST; 
	int loc,key; 
	int n; 
	scanf("%d",&n); 
	Creat_Seq(ST,n); 
	//printf("Please input the key value："); 
	scanf("%d",&key); 
	loc = Search_Seq(ST,key); 
	if(loc!=0) 
		printf("The element position is %d.\n",loc-1); 
	else 
		printf("The element is not exist.\n"); 
}
/*
输入格式
第一行:元素个数n 
第二行：依次输入n个元素的值（有序） 
第三行：输入要查找的关键字key的值


输出格式
输出分两种情形： 
1.如果key值存在，则输出其在表中的位置x(表位置从0开始),格式为The element position is x. 
2.如果key值不存在输出："The element is not exist."


输入样例
6
1 3 5 7 9 10
5


输出样例
The element position is 2.
*/
