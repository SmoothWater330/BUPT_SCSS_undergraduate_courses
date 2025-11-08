/*
学生的属性包括姓名、学号、5门课程的成绩、平均成绩与总成绩。已知一个学生的姓名、学号与5门课程的成绩，你的任务是计算该学生的平均成绩与总成绩，并将该学生的5门课程成绩按照从高到底进行排序，最后将这个同学的完整信息输出。学生的姓名中只能包含大小写字母与空格字符，不会超过20个字符；学生的学号是个长度不会超过20的字符串，只包含数字字符；课程成绩均为0—100的整数。

要求：
1.在本题中，你要设计一个结构来存储学生的信息。在此结构中，需要有一个字符数组来存储姓名；一个字符数组来存储学号；一个长度为5的整型数组来存储5门课程的成绩；一个双精度浮点型变量存储平均成绩，一个整型变量存储总成绩。
2.在对结构变量的成员进行赋值与排序的时候，你要使用“结构变量名+‘.’+结构成员名”这种方式访问变量，如“student.score”；而在输出学生信息时，你要用一个结构指针指向该结构，然后用结构指针访问结构中的变量，即“结构指针名+‘->’+结构成员名”，如“ptr->score”。

输入格式:
学生信息的输入按照姓名、学号、5门课程成绩的顺序输入，共占三行，具体格式见样例。

输出格式:
姓名占一行；学号占一行；5门成绩中间用空格分开，最后一个成绩后是换行符，从高到底进行排序，占一行；平均成绩与总成绩用空格分隔，占一行，平均成绩保留两位小数。

输入样例:
Liu Mengmeng
0821131666666
88 90 93 91 85

输出样例:
Name:Liu Mengmeng
ID:0821131666666
Score:93 91 90 88 85
average:89.40 total:447
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

//排序
void sort(int arr[])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4-i;j++)
        {
            if(arr[j]<arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    struct Student s1;
    struct Student* p=&s1;
    gets(p->name);
    scanf("%s",&p->number);
    p->sum=0;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&p->score[i]);
        p->sum+=p->score[i];
    }
    sort(p->score);
    s1.average=(double)p->sum/5;
    printf("Name:");
    puts(p->name);
    printf("ID:%s\n",p->number);
    printf("Score:%d",p->score[0]);
    for(int i=1;i<5;i++)
        printf(" %d",p->score[i]);
    printf("\n");
    printf("average:%.2lf total:%d",p->average,p->sum);

    return 0;
}