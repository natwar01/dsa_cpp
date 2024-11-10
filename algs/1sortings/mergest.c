#include <stdio.h>
#include <stdlib.h>
int conquer(int arr[],int si,int mi,int ei)
{
    int ma[(ei-si)+1];
    int n=sizeof(ma)/sizeof(ma[0]);
    int idx1=si;
    int idx2=mi+1;
    int x=0;
    while(idx1<=mi && idx2<=ei)
    {
        if(arr[idx1]<=arr[idx2])
        {
            ma[x++]=arr[idx1++];
        }
        else
        {
            ma[x++]=arr[idx2++];
        }
    }
    while(idx1<=mi)
    {
        ma[x++]=arr[idx1++];
    }
    while(idx2<=ei)
    {
        ma[x++]=arr[idx2++];
    }
    for(int i=0,j=si;i<n;i++,j++)
    {
        arr[j]=ma[i];
    }
}
int divide(int arr[],int si,int ei)
{
    if(si>=ei)
    {
        return 0;
    }
    int mi=si+(ei-si)/2;
    divide(arr,si,mi);
    divide(arr,mi+1,ei);
    conquer(arr,si,mi,ei);
}


int main()
{
    int arr[]={30,24,12,35,8,26,15,10};
    int n= sizeof(arr)/sizeof(arr[0]);
    divide(arr,0,n-1);


    printf("sorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}