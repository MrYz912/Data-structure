#include <stdio.h>
#include <malloc.h>

void HeapAdjust(int *a, int s, int m)
{
    int temp = a[s];
    for(int j = 2 * s; j <= m; j *= 2)
    {
        if(j < m && a[j] < a[j + 1]) ++j;
        if(temp >= a[j]) break;
        a[s] = a[j];
        s = j;
    }
    a[s] = temp;
}

void HeapSort(int *a)
{
    for(int i = a[0] / 2; i > 0; --i) HeapAdjust(a, i, a[0]);
    for(int i = a[0]; i > 1; --i)
    {
        for(int j = 1; j <= a[0]; ++j) printf("%d ", a[j]);
        printf("\n");

        int t = a[1];
        a[1] = a[i];
        a[i] = t;

        HeapAdjust(a, 1, i - 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if(!n) return 0;
    int *a = (int *)malloc(sizeof(int) * (n + 1));
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    a[0] = n;
    HeapSort(a);
    for(int j = 1; j <= a[0]; ++j) printf("%d ", a[j]);
    printf("\n");
}


/*
用函数实现堆排序，并输出每趟排序的结果



输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
第一行：初始建堆后的结果
其后各行输出交换堆顶元素并调整堆的结果，数据之间用一个空格分隔


输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
9 7 8 6 4 3 2 5 0 1
8 7 3 6 4 1 2 5 0 9
7 6 3 5 4 1 2 0 8 9
6 5 3 0 4 1 2 7 8 9
5 4 3 0 2 1 6 7 8 9
4 2 3 0 1 5 6 7 8 9
3 2 1 0 4 5 6 7 8 9
2 0 1 3 4 5 6 7 8 9
1 0 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
*/
