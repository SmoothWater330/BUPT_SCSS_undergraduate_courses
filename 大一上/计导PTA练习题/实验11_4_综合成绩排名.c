/*
众所周知，计算机院要对申请转入计算机大类的学生进行考核，考核方式包括机试和面试。学生综合成绩采取百分制，其中50%由机试成绩核算，另50%由学生已获得的加权成绩核算。综合成绩优秀者可进入面试环节。现请你写一个根据学生成绩来确定综合成绩排名的程序。

输入：
第一行为一个整数n(0<n<100)，代表学生人数。
后边n行为学生信息，格式为，一个字符串代表学生学号（长度不超过15)，后边为两个整数，前边的代表机试成绩，后一个代表学生已获得的加权成绩。（两类成绩均在0到100之间）。

输出：
共n行，按综合成绩（机试成绩加加权成绩）从高到低每行输出每个学生的信息，如果综合成绩相同，则机试成绩高的学生在前。每行的格式为：一个字符串（学生学号）加三个整数(4个数据之间均用一个空格分隔)，这三个整数依次为综合成绩，机试成绩和加权成绩，测试用例保证输入合法且不存在成绩完全相同的学生。

程序中用的结构体定义及各成员含义如下：

typedef struct
{
    char    id[16]  ;    //学生账号 
    int    total ;    //综合成绩 
    int    ce ;    //机试成绩 
    int    ws ;    //加权成绩 
}STUDENT;

程序中用到3个函数，分别为：
void Swap(STUDENT * s1,STUDENT * s2) ;
其中参数s1,s2为指向两个结构体的指针，其功能是将这两个指针指向的结构体内的值互相交换。

int Comp(STUDENT * s1,STUDENT * s2) ;
其中参数s1,s2为指向两个结构体的指针，其功能是比较两个结构体， 如果s1>s2则返回1，否则返回0。这里s1>s2指的是s1的总分高，或者总分相同时指的是s1的机试成绩高。测试用例保证输入合法且不存在成绩完全相同的学生。

void Sort(STUDENT a[],int size) ;
其中参数a为待排序的结构体数组，size为数组中学生的数量。其功能是将a按题目指定规则排序。

函数接口定义：
本题中大家只需实现下边这一个函数，另外两个函数不需实现，函数接口如下： void Swap(STUDENT * s1,STUDENT * s2) ;

裁判测试程序样例：
#include <stdio.h>

typedef struct
{
    char    id[16]  ;//学生账号 
    int        total ;    //综合成绩 
    int        ce ;    //机试成绩 
    int        ws ;    //加权成绩 
}STUDENT;

void Sort(STUDENT a[],int size) ; 
void Swap(STUDENT * s1,STUDENT * s2) ;
int  Comp(STUDENT * s1,STUDENT * s2) ;

int main()
{
    STUDENT    stu[100] ;
    int        i , n ;
    
    
    scanf("%d",&n) ;
    for(i=0;i<n;i++)
    {
        scanf("%s%d%d",stu[i].id,&stu[i].ce,&stu[i].ws) ;
        stu[i].total = stu[i].ce+stu[i].ws ;
    }
            
    Sort(stu,n) ;
    for(i=0;i<n;i++)
        printf("%s %d %d %d\n",stu[i].id,stu[i].total,stu[i].ce,stu[i].ws) ;
    
    return 0;    
}

// 请在这里填写答案

输入样例：
3
bupt_2018210001 78 74
bupt_2018210002 95 71
bupt_2018210003 84 75


输出样例：
bupt_2018210002 166 95 71
bupt_2018210003 159 84 75
bupt_2018210001 152 78 74
*/

typedef struct
{
    char    id[16]  ;//学生账号 
    int        total ;    //综合成绩 
    int        ce ;    //机试成绩 
    int        ws ;    //加权成绩 
}STUDENT;

void Swap(STUDENT* s1,STUDENT* s2)
{
    STUDENT s=*s1;
    *s1=*s2;
    *s2=s;
}

int  Comp(STUDENT * s1,STUDENT * s2)
{
    if(s1->total>s2->total)
        return 1;
    else if(s1->total<s2->total)
        return 0;
    else
    {
        if(s1->ce>s2->ce)
            return 1;
        else
            return 0;
    }
}

void Sort(STUDENT a[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(Comp(&a[j],&a[j+1])==0)
                Swap(&a[j],&a[j+1]);
        }
    }
}