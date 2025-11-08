/*
有表达式如下：
a / ( b * c - d )
请按要求计算 。

输入格式:
只有一行，为4个用空格分隔的浮点数，依次代表a,b,c,d（请用double 类型存储）。

输出格式:
如果除数为0，则输出error，否则输出该表达式的值（保留1位小数）。

输入样例:
66.09 7.7 3.5 1.6

输出样例:
2.6
*/

#include<stdio.h>
#include<math.h>

int main()
{
    double a,b,c,d;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    double result=a/(b*c-d);
    if(fabs(b*c-d)<1e-6)
    {
        printf("error");
    }
    else
    {
        printf("%.1lf\n",result);
    }
    
    return 0;
}