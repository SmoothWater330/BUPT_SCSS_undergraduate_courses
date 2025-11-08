/*
1、设计函数char ** create1( int n ) ;，根据整数n创建一个长度为n的字符指针型动态一维数组，并返回动态数组第一个元素的地址。
2、设计函数char * create2( int n ) ;，根据整数n创建一个长度为n的字符型动态一维数组，并返回动态数组第一个元素的地址。
3、设计函数void sort( char** strArray , int size ) ; ，该函数可将字符指针数组strArray所指向的所有字符串按从小到大排列。
*/

char** create1(int n)
{
    char** p;
    p=(char**)malloc(sizeof(char*)*n);
    return p;
}

char* create2(int n)
{
    char* p;
    p=(char*)malloc(sizeof(char)*n);
    return p;
}

void sort( char** strArray , int size )
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(strcmp(strArray[j],strArray[j+1])>0)//比较两字符串大小
            {
                char* p=strArray[j];
                strArray[j]=strArray[j+1];
                strArray[j+1]=p;
            }
        }
    }
}