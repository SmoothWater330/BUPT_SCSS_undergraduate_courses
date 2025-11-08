/*
编写一个程序，用下面的公式计算ex的值。

ex=1+1!x​+2!x2​+3!x3​+...

1)对于项n!xn​ ,随着n的增大，|n!xn​|会渐渐趋向于0。因此可以假设当项 |n!xn​|<1e－8时，循环终止。1e－8即为10的-8次方。

2)如何求x的绝对值：使用库函数fabs(x)，其中x是浮点数，返回结果也是浮点数。如判断|f|是否接近于0可以这么写：if(fabs(f)<1e-8)。

3)如何检验运行结果是否正确：标准库函数exp(x)用来求e的x次幂，其中x是浮点数，返回值也是浮点数。同学可以通过比较自己程序计算结果和标准函数exp(x)的计算结果是否一致来检验自己程序的正确性。如写上这条语句：“printf("%.4f\n",exp(x));”。建议程序中的数据一律使用double型变量。

输入格式:
只有一个浮点数x，即代表ex中的指数x,且x满足x<=20。

输出格式:
只有一个浮点数，即ex的值，保留4位小数。

输入样例:
3.7


输出样例:
40.4473
*/

#include<stdio.h>
#include<math.h>
 
int main()
{
    double x,result,sum=1;
    scanf("%lf",&x);
    result=x;
    if(x==0)
    {
        printf("%.4lf",sum);
    }
    else
    {
        sum+=result;
        for(int i=2;fabs(result)>1e-8;i++)
        {
            result=result*x/i;
            sum+=result;
        }
        printf("%.4lf",sum);
    }
 
    return 0;
}