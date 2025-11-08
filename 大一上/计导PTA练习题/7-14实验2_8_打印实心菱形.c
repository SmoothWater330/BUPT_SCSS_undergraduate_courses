/*
已知一个整数n，你要根据n打印出n阶的实心菱形。

输入格式:
只有一个整数n(0<n<40，代表要打印的菱形阶数)。测试用例保证合法。

输出格式:
n阶实心菱形(占2乘n-1行)。

输入样例:
5
 

输出样例:
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/

#include<stdio.h>
 
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(int j1=i;j1<n-1;j1++)
        {
            printf(" ");
        }
        for(int j2=2*(i+1)-1;j2>0;j2--)
        {
            printf("*");
        }
        printf("\n");
    }
 
    int n0=n;
    for(i=1;i<n;i++)
    {
        for(int j3=i;j3>0;j3--)
        {
            printf(" ");
        }
        for(int j4=2*n0-3;j4>0;j4--)
        {
            printf("*");
        }
        n0--;
        printf("\n");
    }
 
    return 0;
}