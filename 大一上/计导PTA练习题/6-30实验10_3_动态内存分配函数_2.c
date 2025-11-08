/*
1、设计函数char ** create1(int n) ;，根据整数n创建一个长度为n的字符型指针动态一维数组，并返回动态数组第一个元素的地址。
2、设计函数void create2( char ** strPtr , int n ) ;，为字符型指针动态一维数组strPtr中的每一个元素创建一个长度为n+1字符型动态一维数组。参数n为字符型指针动态一维数组strPtr的长度。
3、设计函数void fill(char ** strPtr , int n) ;按要去将相应的字符填入二维动态数组strPtr中。具体格式见样例。
输入只有一行，为一个整数n（0<=n<=40）。
输出共2*n+1行，具体见样例。

函数接口定义一：
char ** create1(int n) ;
其中 n 是用户传入的参数，代表字符型指针动态一维数组的长度。 函数须返回动态数组第一个元素的地址。

函数接口定义二：
void create2( char ** strPtr , int n ) ;
其中 strPtr 和 n 都是用户传入的参数,strPtr 为指向字符型指针动态一维数组的指针；n 代表字符型指针动态一维数组的长度。 函数没有返回值。

函数接口定义三：
void fill(char ** strPtr , int n);
其中 strPtr 和 n 都是用户传入的参数,strPtr 为指向字符型指针动态一维数组的指针；n 要填充的字符的阶数，n阶时要填充2*n+1行，具体格式见样例。 函数没有返回值。

输入样例一：
1

输出样例一：
 X
X X
 X


输入样例二：
5

输出样例二：
     X
    / \
   /   \
  /     \
 /       \
X         X
 \       /
  \     /
   \   /
    \ /
     X


输入样例三：
8

输出样例三：
        X
       / \
      /   \
     /     \
    /       \
   /         \
  /           \
 /             \
X               X
 \             /
  \           /
   \         /
    \       /
     \     /
      \   /
       \ /
        X

*/

char** create1(int n)
{
    char** p;
    p=(char**)malloc(sizeof(char*)*n);
    return p;
}

void create2( char ** strPtr , int n )
{
    for(int i=0;i<n;i++)
    {
        strPtr[i]=(char*)malloc(sizeof(char)*(n+1));
    }
}

void fill(char ** strPtr , int n)
{
    for(int i=0;i<n;i++)
    {
        strPtr[0][i]=' ';
    }
    strPtr[0][n]='X';

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            strPtr[i][j]=' ';
        }
        strPtr[i][n-i]='/';
        for(int j=n-i+1;j<n+i;j++)
        {
            strPtr[i][j]=' ';
        }
        strPtr[i][n+i]='\\';
    }

    strPtr[n][0]=strPtr[n][2*n]='X';
    for(int j=1;j<2*n;j++)
    {
        strPtr[n][j]=' ';
    }

    for(int i=n+1;i<2*n;i++)
    {
        for(int j=0;j<i-n;j++)
        {
            strPtr[i][j]=' ';
        }
        strPtr[i][i-n]='\\';
        for(int j=i-n+1;j<3*n-i;j++)
        {
            strPtr[i][j]=' ';
        }
        strPtr[i][3*n-i]='/';
    }

    for(int i=0;i<n;i++)
    {
        strPtr[2*n][i]=' ';
    }
    strPtr[2*n][n]='X';

}