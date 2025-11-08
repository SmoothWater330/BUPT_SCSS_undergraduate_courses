/*
设计函数int numConvert(int number,int n,int m)，用于将n进制的数number转化为m进制的数并返回，其中2<=n<=10，2<=m<=10。
例如将二进制数110转化为三进制时，即调用numConvert(110,2, 3)，函数返回值为20。

测试用例保证输入及返回值都在int型变量范围内。

输入与输出要求：
输入三个正整数number、n和m，三个整数的意义如题目叙述。输出转化后的结果。
*/

int numConvert(int number,int n,int m)
{
    int temp_10=0;
    int p=1;
    while(number!=0)//转为十进制
    {
        temp_10+=number%10*p;
        p*=n;
        number/=10;
    }
 
    //十进制转其他
    p=1;
    int result=0;
    while(p/m<=temp_10)//最大的部分
        p*=m;
    while(p>=1)
    {
        result=temp_10/p+result*10;//留整数部分作为最高位数字
        temp_10%=p;//去除该部分
        p/=m;//减小一次部分
    }
    return result;
}