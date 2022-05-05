/*Program to find largest element in array*/

#include <stdio.h>

int main()
{
    int arr[100],i,n;
    int l;

    printf("Enter the number of array elements :");
    scanf("%d",&n);

    while(n>100 || n<1)
    {
        printf("Enter the number of elements 1 to 100");
        scanf("%d",&n);
    }

    printf("Enter the array elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    l=arr[0];

    for(i=1;i<n;i++)
    {
        if(arr[i]>l)
            l=arr[i];
    }

    printf("The largest number of the array is %d",l);
    return 0;
}
