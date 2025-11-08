/*
已知正整数n、m，你要利用malloc函数动态开辟一个n行、m列的整型二维数组，然后读取nm个整数存入该数组中。再将这nm个整数全部改为其相反数的10倍，然后将其输出。最后你要利用free函数将该动态数组所占用的空间释放。

提示：malloc与free的使用，以下代码即建立了一个n行m列的整型二维动态数组，并释放：

int **a,n ,m;
scanf(“%d%d”,&n,&m);
a=(int **)malloc(sizeof(int *)*n);//建立长度为n的动态指针数组
for(i=0;i<n;i++)
a[i]=(int *)malloc(sizeof(int)*m);//建立长度为m的一维整型数组
for(i=0;i<n;i++)
free(a[i]);
free(a);//释放动态内存。

输入格式:
输入为两行，第一行为两个用空格分隔的正整数n,m，第二行为n*m个用空格分隔整数。测试用例保证所有整数可以用int存储，且为这n*m个整数申请内存不会超出内存限制。

输出格式:
输出按矩阵格式输出，具体见样例。

输入样例:
3 4
1 2 3 4 5 6 7 8 9 10 11 12

输出样例:
-10 -20 -30 -40
-50 -60 -70 -80
-90 -100 -110 -120
*/

#include<stdio.h>

int main()
{
    int **a;
    int n ,m;
    scanf("%d%d",&n,&m);
    a=(int **)malloc(sizeof(int *)*n);//建立长度为n的动态指针数组
    for(int i=0;i<n;i++)
        a[i]=(int *)malloc(sizeof(int)*m);//建立长度为m的一维整型数组

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            a[i][j]*=-10;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("%d\n",a[i][m-1]);
    }

    for(int i=0;i<n;i++)
        free(a[i]);
    free(a);//释放动态内存

    return 0;
}