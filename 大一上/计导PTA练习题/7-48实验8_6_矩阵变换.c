/*
任意给定一个n*n的矩阵，矩阵的行数与列数均为n。你的任务是通过行变换，使得矩阵每行元素的平均值按递增顺序排列。如果出现有的行平均值相同的情况，则按照原顺序输出。

输入格式:
共n+1行，第一行为一个整数n代表矩阵的行数（列数），n的范围是1—100。后边n行为n*n个整数，即此矩阵的元素。矩阵元素的绝对值不会超过1000000。

输出格式:
共n行，为经过行变换后的新矩阵。每行的每个元素用空格分隔，注意最后一个元素后为换行符。具体见样例。

输入样例:
3
5 5 5
3 3 3
1 1 1


输出样例:
1 1 1
3 3 3
5 5 5
*/

#include<stdio.h>
 
int main()
{
    int n;
    scanf("%d",&n);
    long long arr[n][n];
    long long sum[n];
    for(int i=0;i<n;i++)
        sum[i]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%lld ",&arr[i][j]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            sum[i]+=arr[i][j];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(sum[j]>sum[j+1])
            {
                for(int k=0;k<n;k++)
                {
                    long long temp=arr[j+1][k];
                    arr[j+1][k]=arr[j][k];
                    arr[j][k]=temp;
                }
                //下面三行放在k的for循环外面，否则会多次交换出问题
                long long temp1=sum[j];
                sum[j]=sum[j+1];
                sum[j+1]=temp1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
            printf("%lld ",arr[i][j]);
        printf("%lld\n",arr[i][n-1]);
    }
 
    return 0;
}