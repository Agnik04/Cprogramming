#include <stdio.h>
int fact(int n , int res)
{
    if(n <= 1)
        return res;
    else
        return fact(n-1 , res*n);
}

int main()
{
    int n;

    printf("Enter the number for factorial :");
    scanf("%d",&n);

    printf("The factorial of %d is %d",n,fact(n , 1));

    return 0;
}