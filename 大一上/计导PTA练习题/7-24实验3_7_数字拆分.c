/*
已知一个正整数n，n的范围是1—999999999。你的任务是把这个整数分解为单个数字，然后从左至右依次打印出每一个数字。例如将整数“12345”分解，得到“1 2 3 4 5”。

输入格式:
只有一个正整数。测试用例保证合法。

输出格式:
只有一行，为输入整数的拆分结果，相邻两个数字之间有一个空格，最后一个数字后是换行符。例如12345的拆分结果为：1 2 3 4 5。

输入样例:
12345
 

输出样例:
1 2 3 4 5
*/

​
#include<stdio.h>
 
int main()
{
    //高位开始分解
    int n;
    scanf("%d",&n);
    //求长度
    int num_len=0,num=n;
    while(num>0)
    {
        num_len++;
        num/=10;
    }
    //找除数
    int part=1;
    for(int i=0;i<num_len-1;i++)
    {
        part*=10;
    }
    //从最高位分解
    for(;part>=10;part/=10)
    {
        printf("%d ",n/part);
        n%=part;
    }
    printf("%d\n",n);
 
    /*低位开始分解
    long n;
    scanf("%ld",&n);
    int arr[100];
    int i;//不在for里设置，可以一直使用
    for(i=0;n>0;i++)
    {
        arr[i]=n%10;
        n/=10;
    }//先分别储存
    for(i--;i>0;i--)//先抵消上面循环的最后一次自增，同时i>0使得最后一次打印独立进行
    {
        printf("%d ",arr[i]);
    }
    printf("%d\n",arr[0]);
    */
 
/*错误案例：没有考虑结尾数字是零
 long n,s=0;//n太长啦
    scanf("%lld",&n);
    while(n>0)//先倒置
    {
        s=s*10+n%10;
        n/=10;
    }
    while(s>10)//打印
    {
        printf("%lld ",s%10);
        s/=10;
    }
    printf("%lld\n",s);//要求最后为换行符
*/
 
    return 0;
}