//冒泡排序
void bubbleSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

//辅助函数
void outputData(int data[],int elementCount)
{
    for(int i=0;i<elementCount-1;i++)
        printf("%d ",data[i]);
    printf("%d\n",data[elementCount-1]);
}