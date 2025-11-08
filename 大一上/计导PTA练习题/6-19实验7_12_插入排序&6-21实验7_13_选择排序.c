void print(int a[],int n)
{
    for(int i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
}
 
void InsertSort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=a[i];
        for(;j>=0&&a[j]>key;j--)
            a[j+1]=a[j];//前面大数依次覆盖后面的
        a[j+1]=key;//j+1为了抵消上一步最后的自减
        print(a,n);
    }
}

int findMin(int data[], int startLoc, int endLoc)
{
    int min=startLoc;
    for(int j=startLoc;j<endLoc;j++)
    {
        if(data[j]<data[min])
        {
            min=j;
        }
    }
    return min;
}
 
//选择排序
void selectSort(int data[],int elementCount)
{
    for(int i=0;i<elementCount;i++)
    {
        int min=findMin(data,i,elementCount);
        int temp=data[i];
        data[i]=data[min];
        data[min]=temp;
        if(i!=elementCount-1)
            outputData(data,elementCount);
    }
}