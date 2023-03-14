#include <stdio.h>

int fibbo(int n , int x , int y)
{
    if(n == 1)
        return x;
    else if(n == 2)
        return y;
    else
        return fibbo(n-1 , y , x+y);
}

int main()
{
    int n, x, y;

    printf("Enter the range :");
    scanf("%d",&n);

    printf("Enter the 1st and 2nd number :");
    scanf("%d %d",&x,&y);

    printf("The sum of the fibbonacci series is %d",fibbo(n , x , y));

    return 0;
}