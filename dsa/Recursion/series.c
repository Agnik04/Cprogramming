//1+2+3+...+n

#include <stdio.h>

int series(int n , int i)
{
    if(n == 0)
        return i;
    else
        return series(n-1 , i+n);
}

int main()
{
    int n;

    printf("Enter the range :");
    scanf("%d",&n);

    printf("The sum of the series is %d",series(n , 0));

    return 0;
}