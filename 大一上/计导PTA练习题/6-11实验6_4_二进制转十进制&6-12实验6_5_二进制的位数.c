// 6-11 实验6_4_二进制转十进制
int convert(int n)
{
    if(n==0)
        return 0;
    else
        return n%10+convert(n/10)*2;
}

// 6-12 实验6_5_二进制的位数
int countBinary(int n)
{
    if(n==0||n==1)
        return 1;
    else
        return countBinary(n/2)+1;
}