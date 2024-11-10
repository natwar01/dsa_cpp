#include <stdio.h>
#include <stdlib.h>
int bubbl_srt(int* arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){

    int n;
    printf("\nenter size for your array: ");
    scanf("%d",&n);
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

    bubbl_srt(arr,n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}