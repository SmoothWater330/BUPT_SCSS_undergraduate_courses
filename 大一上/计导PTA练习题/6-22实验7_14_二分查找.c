//循环实现
int BinarySearch(int a[],int n,int key)
{
    int l=0;//左侧标识
    int r=n-1;//右侧标识
    int flag;//中间标识
    while(l<=r)//一半一半查，缩小到最小范围
    {
        flag=(l+r)/2;
        if(a[flag]<key)
            l=flag+1;
        else if(a[flag]>key)
            r=flag-1;
        else
            return flag;
    }
    return -1;
}
 
//递归实现
int RecurBinarySearch( int a[] , int key , int left , int right )
{
    int flag=(left+right)/2;
 
    if(left>right)
        return -1;
    if(key<a[flag])
        return RecurBinarySearch(a,key,left,flag-1);
    else if(key>a[flag])
        return RecurBinarySearch(a,key,flag+1,right);
    else
        return flag;
    
}