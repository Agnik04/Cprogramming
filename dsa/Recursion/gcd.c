#include <stdio.h>

int gcd(int a, int b)
{
    if(a > b)
        return gcd(a-b, b);
    else if(b > a)
        return gcd(a, b-a);
    else
        return a;
}

int main()
{
    int n1, n2;

    printf("Enter two positive numbers :");
    scanf("%d\n%d",&n1,&n2);

    printf("The G.C.D of %d and %d numbers is %d",n1,n2,gcd(n1,n2));
    
    return 0;
}