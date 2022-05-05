/*Calculate the average using array*/
#include <stdio.h>

int main()
{
    int i,n;
    float arr[100],sum=0.0,avg;

    printf("Enter the number of elements :");
    scanf("%d",&n);

    while(n>100 || n<1)
    {
        printf("Enter the number of elements 1 to 100");
        scanf("%d",&n);
    }

    printf("Enter the array elements :");
    for(i=0;i<n;i++)
    {
        scanf("%f",&arr[i]);
    }

    for(i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }

    avg=sum/n;
    printf("The average is : %f",avg);

    return 0;
}
