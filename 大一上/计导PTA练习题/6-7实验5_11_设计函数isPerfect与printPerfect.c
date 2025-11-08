/*
如果一个整数的各因子（包括1但不包括该整数本身)值之和等于该整数，则该整数称为“完全数”（perfect number)。例如，6是一个完全数，因为6=1+2+3。你的任务是设计函数isPerfect和printPerfect，判断并打印出区间[a,b]（1<=a<b<=20000）内的所有完全数，并统计完全数的总个数。

isPerfect函数原型：int isPerfect(int n);

用于判断正整数n是否为完全数，若是，则返回值为1，否则为0。

printPerfect函数原型：void printPerfect(int n);

用于打印出一个完全数n的所有因子，当执行printPerfect(6)时，打印效果为：6=1+2+3。

输入与输出要求：
输入两个正整数a和b，输出区间[a,b]内的所有完全数及完全数的总个数。

函数接口定义：
void printPerfect(int n);

其中 n 是用户传入的参数。 函数没有返回值。

int isPerfect(int n);

其中 n 是用户传入的参数。如果 n是完全数，则函数须返回 1，否则返回0 。

输入样例：
1 10000

输出样例：
6=1+2+3
28=1+2+4+7+14
496=1+2+4+8+16+31+62+124+248
8128=1+2+4+8+16+32+64+127+254+508+1016+2032+4064
The total number is 4.
*/

//判断
int isPerfect(int n)
{
    if(n==1)
        return 0;
    int flag,sum=1;
    for(int k=2;k*k<n;k++)//防止超时，只需要遍历一半
    {
        if(n%k==0)
            sum=sum+k+n/k;//每次发现因子时同时加上两个因子
    }
    if(sum==n)
        return 1;
    else
        return 0;

}



void printPerfect(int n)
{
    printf("%d=1",n);
    for(int k=2;k<n;k++)
    {
        if(n%k==0)
            printf("+%d",k);
    }
    printf("\n");
}