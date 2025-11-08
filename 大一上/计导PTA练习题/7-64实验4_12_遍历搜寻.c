/*
已知整数a、b、c。你的任务是求出区间[a,b]内的整数，满足该数与“该数的所有因数（不包括本身但包括1,1的因数和按0处理）相加之和”的差的绝对值小于等于c的数字。例如27的因数是1、3、9。那么27与27的所有因数和的差为:27-(1+3+9)=14。

输入格式:
只有一行，为三个用空格分隔的整数，依次代表a、b、c。a、b代表所求区间范围，满足1<=a<=b<=10000，c代表限制条件，c>=0且小于10。

输出格式:
若干个整数，即满足条件的全部整数，每五个数为一行，整数之间用tab分隔，最后一个数后为换行符。当该区间没有符合条件的整数时，输出“There is no proper number in the interval.”。

输入样例一:
1 10000 0

输出样例一:
6	28	496	8128

输入样例二:
900 1000 0

输出样例二:
There is no proper number in the interval.
*/

#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,c,i,j,sum,count=0,i0=0;
    scanf("%d %d %d",&a,&b,&c);
    int arr[b];
    for(i=a;i<=b;i++)
    {
        sum=0;
        for(j=1;j<i;j++)
        {
            if(i%j==0)
            sum+=j;
        }
        if(fabs(sum-i)<=c)
        {
            arr[count]=i;
            count++;
        }
    }
    if(count==0)
    printf("There is no proper number in the interval.");
    else
    {
        for(;i0<count-1;i0++)
        {
            if((i0+1)%5!=0)
            printf("%d\t",arr[i0]);
            else
            printf("%d\n",arr[i0]);
        }
        printf("%d\n",arr[i0]);
    }
    return 0;
}