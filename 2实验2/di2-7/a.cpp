#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int QElemType;
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)

typedef struct
{
   QElemType *base; // 初始化的动态分配存储空间
   int front; // 头指针,若队列不空,指向队列头元素
   int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置
 }SqQueue;

Status InitQueue(SqQueue &Q)
{
// 构造一个空队列Q，该队列预定义大小为MAXQSIZE
	Q.base=(QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q.base) exit(1);
	Q.rear=Q.front=0;
	return OK;
}

Status EnQueue(SqQueue &Q,QElemType e)
{
// 插入元素e为Q的新的队尾元素
	 if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;
	 Q.base[Q.rear]=e;
	 Q.rear=(Q.rear+1)%MAXQSIZE;
	 return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
// 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
	 if(Q.front==Q.rear) return ERROR;
	 e=Q.base[Q.front];
	 Q.front=(Q.front+1)%MAXQSIZE;
	 return OK;
}

Status GetHead(SqQueue Q, QElemType &e)
{
// 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
	if(Q.front==Q.rear) return ERROR;
	e=Q.base[Q.front];
	return OK;
}

int QueueLength(SqQueue Q)
{
// 返回Q的元素个数
	return Q.rear%MAXQSIZE-Q.front%MAXQSIZE;
}

int main()
{
    int n,i,k,first1,first2,e;
    double a[20]={0},b[20]={0},c[20]={0};
    double sum=0;
    scanf("%d",&n);
    scanf("%d",&first1);
    scanf("%d",&first2);
    e=first1+first2;
    for(i=0;i<n-1;i++)
    {
        scanf("%lf",&a[i]);
        scanf("%lf",&b[i]);
    }
    for(i=0,k=0;i<n-1;i++,k++)
    {
        c[i]=e-a[i];
        e=e+b[k];
        if(c[i]<0)
        {
            c[i]=0;
            e=a[i]+b[k];
        }
    }
    for(i=0;i<n-1;i++)
    {
        sum=sum+c[i];
    }
    sum=sum/n;
    printf("%.2lf",sum);
    return 0;
}
/*
某银行有一个客户办理业务站，在一天内随机地有客户到达，设每位客户的业务办理时间是某个范围内的值。设只有一个窗口，一位业务人员，要求程序模拟统计在
一天时间内，所有客户的平均等待时间。模拟数据按客户到达的先后顺序依次由键盘输入，对应每位客户有两个数据，到达时刻和需要办理业务的时间。



输入格式
第一行：一天内的客户总人数n
第二行：第一个客户的到达时刻和需要办理业务的时间
第三行：第二个客户的到达时刻和需要办理业务的时间
……
第n行：第n - 1个客户的到达时刻和需要办理业务的时间
第n + 1行：第n 个客户的到达时刻和需要办理业务的时间


输出格式
第一行：所有客户的平均等待时间（精确到小数点后2位）


输入样例
3
1 3
2 1
3 5


输出样例
1.33
*/
