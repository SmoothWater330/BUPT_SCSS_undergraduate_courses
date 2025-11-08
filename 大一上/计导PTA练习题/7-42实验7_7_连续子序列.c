/*
已知两个由正整数组成的无序序列A、B，每个序列的元素个数未知，但至少有一个元素。你的任务是判断序列B是否是序列A的连续子序列。假设B是“1 9 2 4 18”，A是“33 64 1 9 2 4 18 7”，B是A的连续子序列；假设B是“1 9 2 4 18”，A是“33 1 9 64 2 4 18 7”，B不是A的连续子序列。

输入格式:
依次输入两个乱序的正整数序列A、B，序列中元素个数未知，但每个序列至少有一个元素，并以输入“-1”结束（-1不算序列中元素），每个序列占一行。两个数列的长度均不超过1000。

输入保证合法，且所有整数均可用int存储。

输出格式:
如果序列B是序列A的连续子序列，则输出“ListB is the sub sequence of ListA.”，否则输出“ListB is not the sub sequence of ListA.”。

输入样例:
5 4 3 2 1 -1
3 2 1 -1
 

输出样例:
ListB is the sub sequence of ListA.
*/

#include<stdio.h>
 
int main()
{
    int A[1000];
    int B[1000];
    int i = 0, j = 0, lena = 1, lenb = 1, flag = 1;
    scanf("%d", &A[i]);
    while (A[i] != -1)
    {
        i++;
        lena++;
        scanf("%d", &A[i]);
    }
    scanf("%d", &B[j]);
    while (B[j] != -1)
    {
        j++;
        lenb++;
        scanf("%d", &B[j]);
    }
 
    if(lena<lenb)
        printf("ListB is not the sub sequence of ListA.");
    else
    {
        for (int k = 0; k <= lena - lenb; k++)
        {
            flag = 1;
            for (j = 0; j < lenb-1; j++)//必须是lenb-1否则会把-1当做比较的对象
            {
                if (B[j] != A[j + k])
                    flag = 0;
            }
            if (flag==1)
                break;
        }
        if (flag == 1)
            printf("ListB is the sub sequence of ListA.");
        else
            printf("ListB is not the sub sequence of ListA.");
    }
 
 
    return 0;
}