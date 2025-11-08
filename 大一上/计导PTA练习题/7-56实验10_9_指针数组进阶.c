/*
已知正整数n，n的范围是1—100。你要从键盘读入n个字符串，每个字符串的长度不确定，但是n个字符串的总长度不超过100000。你要利用字符指针数组将这n个字符串按照ASCII码顺序进行升序排序，然后再打印到屏幕上。字符串中可能包含ASCII码中的任意字符，每个字符串以换行符结束输入。

要求：不允许定义如char str[100][100000];这样的二维数组，因为会极大的浪费内存空间。你应定义char str[100000];这样的存储空间，将n个字符串连续的存储在一维字符空间内，然后将这n个字符串的起始位置保存在字符指针数组中，再进行排序操作。

输入格式:
输入一个正整数n，代表待排序字符串的个数，n不超过100，然后是n个字符串，每个字符串的长度不确定，但至少包含1个字符。n个字符串的总长度不会超过100000。

输出格式:
排序后的n个字符串，每个字符串占一行。

输入样例:
4
Where there is hope ,there is a way.
Welcome Beijing.
Nice idea.
Have fun.


输出样例:
Have fun.
Nice idea.
Welcome Beijing.
Where there is hope ,there is a way.
*/

#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    char** ptr=(char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++)
    {
        ptr[i]=(char*)malloc(sizeof(char)*100000);
    }
    for(int i=0;i<n;i++)
    {
        gets(ptr[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(strcmp(ptr[j],ptr[j+1])>0)
            {
                char* pp=ptr[j];
                ptr[j]=ptr[j+1];
                ptr[j+1]=pp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%s\n",ptr[i]);
    }


    return 0;
}