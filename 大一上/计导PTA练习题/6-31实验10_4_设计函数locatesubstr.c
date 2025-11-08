/*
设计函数 char *locatesubstr(char *str1,char *str2)，查找str2指向的字符串在str1指向的字符串中首次出现的位置，返回指向该位置的指针。若str2指向的字符串不包含在str1指向的字符串中，则返回空指针NULL。
注意这里必须使用指针而不是数组下标来访问字符串。

函数接口定义：
char *locatesubstr(char *str1,char *str2);
其中 str1 和 str2 都是用户传入的参数，其含义如题面所述 。若查找成功则返回指向该位置的指针，若失败则返回空指针。

裁判测试程序样例：

#include <stdio.h>

char *locatesubstr(char *str1,char *str2);
int main()
{
    char str1[505],str2[505];
    char *p;
    gets(str1);
    gets(str2);
    p=locatesubstr(str1,str2);
    
    if(p==NULL)    printf("NULL!\n");
    else    puts(p);
    
    return 0;
}

// 请在这里填写答案

输入样例：
didjfsd dabcxxxxxx
abc

输出样例：
abcxxxxxx
*/

char *locatesubstr(char *str1,char *str2)
{
    int i;
    if(*str2!='\0')
    {
        while(*str1!='\0')
        {
            for(i=0;*(str1+i)==*(str2+i);i++)
            {
                if(*(str2+i+1)=='\0')
                    return str1;
            }
            str1++;
        }
        return NULL;
    }
    else
        return NULL;
}