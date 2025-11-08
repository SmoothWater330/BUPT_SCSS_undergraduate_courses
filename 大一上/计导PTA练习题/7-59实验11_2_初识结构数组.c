/*
有n名学生，每个学生的信息包括姓名、学号、5门课程的成绩，平均成绩与总成绩。已知学生的姓名、学号与5门课程的成绩，你的任务是计算每个学生的平均成绩与总成绩，并将它们输出。学生的姓名中只能包含大小写字母与空格字符，不会超过20个字符；学生的学号是个长度不会超过20的字符串，只包含数字字符；课程成绩均为0—100的整数。

要求：在本题中，你要设计一个结构来存储一个学生的信息。在此结构中，需要有一个字符数组来存储姓名；一个字符数组来存储学号；一个长度为5的整型数组来存储5门课程的成绩；一个双精度浮点型变量存储平均成绩，一个整型变量存储总成绩。然后，你要设计一个结构数组来存储n名学生的信息。

输入格式:
输入首先是一个正整数n，代表学生的数量，1<=n<=100；每名学生的信息按照姓名、学号、5门课程成绩的顺序输入，共占三行。输入具体格式见样例。

输出格式:
姓名占一行；学号占一行；5门课程成绩中间用空格分开，最后一个成绩后是换行符，占一行；平均与总成绩用空格分隔，占一行，平均成绩保留两位小数；每名同学的信息后都再输出一个空行。
注意：每名同学的信息后都再输出一个空行。

输入样例:
4
xiaowang
0821131699999
87 98 79 90 68
Liu Mengmeng
0821131666666
88 90 93 91 85
Albert Einstein
0821131477777
75 87 100 66 64
Bill Gates
0821131588888
65 58 77 60 61

输出样例:
Name:xiaowang
ID:0821131699999
Score:87 98 79 90 68
average:84.40 total:422

Name:Liu Mengmeng
ID:0821131666666
Score:88 90 93 91 85
average:89.40 total:447

Name:Albert Einstein
ID:0821131477777
Score:75 87 100 66 64
average:78.40 total:392

Name:Bill Gates
ID:0821131588888
Score:65 58 77 60 61
average:64.20 total:321
*/

#include<stdio.h>

//学生结构体
struct Student
{
    char name[50];
    char number[50];
    int score[10];
    int sum;
    double average;
};

int main()
{
    int n;
    scanf("%d",&n);
    struct Student arr_s[100];
    for(int q=0;q<n;q++)
    {
        getchar();
        struct Student s1;
        struct Student* p=&s1;
        arr_s[q]=s1;
        gets(p->name);
        scanf("%s",&p->number);
        p->sum=0;
        for(int i=0;i<5;i++)
        {
            scanf("%d",&p->score[i]);
            p->sum+=p->score[i];
        }
        s1.average=(double)p->sum/5;
        printf("Name:");
        puts(p->name);
        printf("ID:%s\n",p->number);
        printf("Score:%d",p->score[0]);
        for(int i=1;i<5;i++)
            printf(" %d",p->score[i]);
        printf("\n");
        printf("average:%.2lf total:%d",p->average,p->sum);
        printf("\n\n");
    }

    return 0;
}