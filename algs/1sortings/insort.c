#include <stdio.h>
#include <stdlib.h>
int insort(int *a,int n)
{
    for(int i=1;i<n;i++)
    {
        int ins_indx=i;
        int j=i-1;
        int curr_val=a[i];
        while(j>=0 && a[j]>curr_val)
        {
            a[j+1]=a[j];
            ins_indx=j;
            j--;
        }a[ins_indx]=curr_val;
    }
}
int main(){

    int n;
    printf("enter size for your array: ");
    scanf("%d",&n);
    printf("\n");
    int *arr=(int *) malloc(n * sizeof(int));

    if (arr == NULL) {
    printf("Memory allocation failed\n");
    return 1; 
}
    for(int i=0;i<n;i++)
    {
        printf("enter array element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
        insort(arr,n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}