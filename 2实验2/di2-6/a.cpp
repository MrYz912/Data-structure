#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define Stack_Size 1010
#define INF 21000000
char cmp[7][8]= {">><<<>>",">><<<>>",">>>><>>",">>>><>>","<<<<<=?",">>>>?>>","<<<<<?="};
/*
      >   >   <   <   <   >   >
      >   >   <   <   <   >   >
      >   >   >   >   <   >   >
      >   >   >   >   <   >   >
      <   <   <   <   <   =   ?
      >   >   >   >   ?   >   >
      <   <   <   <   <   ?   =
*/


typedef struct
{
    char Elem[Stack_Size];
    int top;
} Operator;
typedef struct
{
    double Elem[Stack_Size];
    int top;
} Number;
void InitStack_Operator(Operator* S)
{
    S->top=-1;
}
void InitStack_Number(Number* S)
{
    S->top=-1;
}
int Pop_Operator(Operator* S)
{
    if(S->top==-1)
    {
        printf("运算符栈为空\n");
        exit(10);
    }
    S->top--;
    return 1;
}
int Pop_Number(Number* S)
{
    if(S->top==-1)
    {
        printf("数字栈为空\n");
        exit(11);
    }
    S->top--;
    return 1;
}
int Push_Operator(Operator* S,char ch)
{
    if(S->top==Stack_Size-1)
    {
        printf("运算符栈满\n");
        exit(12);
    }
    S->top++;
    S->Elem[S->top]=ch;
    return 1;
}
int Push_Number(Number* S,double ch)
{
    if(S->top==Stack_Size-1)
    {
        printf("运算符栈满\n");
        exit(13);
    }
    S->top ++;
    S->Elem[S->top]=ch;
    return 1;
}
char Gettop_Operator(Operator *S)
{
    if(S->top==-1)
    {
        printf("运算符栈为空\n");
        exit(17);
    }
    return S->Elem[S->top];
}
double Gettop_Number(Number *S)
{
    if(S->top==-1)
    {
        printf("数字栈为空\n");
        exit(18);
    }
    return S->Elem[S->top];
}
double Calc(double a,double b,char opt)
{
    double res;
    if(opt=='+') res=a+b;
    if(opt=='-') res=a-b;
    if(opt=='*') res=a*b;
    if(opt=='/')
    {
        if(fabs(b)<0.00000001)
        {
            printf("发生除0错误\n");
            exit(15);
        }
        res=a/b;
    }
    //printf("%.2lf %c %.2lf = %.2lf\n",a,opt,b,res);
    return res;
}
int change(char ch)
{
    switch(ch)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '(':
        return 4;
    case ')':
        return 5;
    case '=':
        return 6;
    }
    return -INF;
}
char compare(char a,char b)
{
    if(cmp[change(a)][change(b)]=='?')
    {
        printf("表达式错误\n");
        exit(16);
    }
    return cmp[change(a)][change(b)];
}
int check(char *s,int len)
{
    for(int i=0; i<len; i++)
    {
        if(s[i]>='0'&&s[i]<='9') continue;
        if(s[i]=='+'||s[i]=='-'||s[i]=='*') continue;
        if(s[i]=='/'||s[i]=='('||s[i]==')') continue;
        return 0;
    }
    return 1;
}

int main()
{
    char a[1010],b[1010];
    int len;
    Operator signs;
    Number number;
    InitStack_Number(&number);
    InitStack_Operator(&signs);
    Push_Operator(&signs,'=');
    double x,y;
    scanf("%s",a);
    len=strlen(a);
    a[len]='=';
    int i,f=0,k=0;
    Push_Operator(&signs,'=');
    for(i=0; i<=len; i++)
    {
        if((a[i]>='0'&&a[i]<='9')||a[i]=='.')
        {
            b[k++]=a[i];
            f=1;
            continue;
        }
        if(f)
        {
            b[k]='\0';
            Push_Number(&number,atof(b));
            f=0;
            k=0;
        }
        switch(compare(Gettop_Operator(&signs),a[i]))
        {
        case '<':
            Push_Operator(&signs,a[i]);
            break;
        case'=':
            Pop_Operator(&signs);
            break;
        case'>':
            y=Gettop_Number(&number),Pop_Number(&number);
            x=Gettop_Number(&number),Pop_Number(&number);
            Push_Number(&number,Calc(x,y,Gettop_Operator(&signs)));
            Pop_Operator(&signs);
            i--;
            break;
        }
    }
    double ans=Gettop_Number(&number);
    printf("%g\n",ans);
    return 0;
}
