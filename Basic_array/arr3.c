/*Calculate Standard diviation*/

#include <stdio.h>

int main()
{
    int i;
    float arr[10],SD=0.0,mean,sum=0.0,f=0.0;

    printf("Enter 10 elements :");
    for(i=0;i<10;i++)
    {
        scanf("%f",&arr[i]);
    }

    for(i=0;i<10;i++)
    {
        sum+=arr[i];
    }
    mean=sum/10;
    for(i=0;i<10;i++)
    {
        f+=pow(arr[i] - mean,2);
    }

    SD=sqrt(f/10);

    printf("The Standard diviation is %f",SD);
    return 0;
}
