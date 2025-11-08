/*
任意给定一个n*m的矩阵，矩阵的行数为n,列数为m。你的任务是寻找该矩阵的鞍点。一个矩阵的鞍点即该位置上的元素在所在行上最大，在所在列上最小。有的矩阵也可能没有鞍点。不难证明，如果一个矩阵有鞍点，那么这个鞍点一定是唯一的。如果某个矩阵只有1行（1列），则默认该行上的所有元素满足列上最小（行上最大）的要求。

例如矩阵M：
1 2 3 4 5
2 4 6 8 10
3 6 9 12 15
4 8 12 16 20

该矩阵的鞍点为M[0][4]=5，该数在第0行最大，在第4列最小。

测试用例保证同行或同列内没有相等的值。

输入格式:
共n+1行，第一行为用空格分隔的两个整数n、m，代表矩阵的行数与列数，n、m的范围均是1—100。后边n行为n*m个整数，即此矩阵的元素。具体见样例。测试用例保证所有整数可以用int存储。

输出格式:
只有一行，如果找到该矩阵的鞍点则输出“The saddle point is (x,y)=v.”，x为该鞍点所在的行，y为该鞍点所在的列，v为该位置上元素的值；如果该矩阵没有鞍点，则输出“There is no saddle point in the matrix.”。

输入样例:
4 5
1 2 3 4 5
2 4 6 8 10
3 6 9 12 15
4 8 12 16 20
 

输出样例:
The saddle point is (0,4)=5.
*/

#include<stdio.h>
 
int main()
{
    int n,m,max,i0,flag=0;
    int goal_lie,goal_hang;//目标行列
    int arr[101][101]={0};
    //输入
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&arr[i][j]);
    //分行列筛选
    for(int i=0;i<n;i++)
    {
        max=arr[i][0];
        goal_lie=0;
        goal_hang=i;
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]>max)//行内找最大
            {
                max=arr[i][j];
                goal_lie=j;
                goal_hang=i;
            }
        }
        for(i0=0;i0<n;i0++)//判定是否列内最小
        {
            if(arr[i0][goal_lie]<max)
                break;
        }
        if(i0==n)//遍历后无结果则为鞍点
        {
            printf("The saddle point is (%d,%d)=%d."
                   ,goal_hang,goal_lie,arr[goal_hang][goal_lie]);
            flag=1;
            break;
        }
    }
    if(!flag)
        printf("There is no saddle point in the matrix.");
 
    return 0;
}