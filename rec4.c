#include <stdio.h>

int power(int,int);

int main() 
{
    int base, n, result;
    printf("Enter base number: ");
    scanf("%d", &base);
    printf("Enter power number(positive integer): ");
    scanf("%d", &n);
    result = power(base, n);
    printf("%d^%d = %d", base, n, result);
    return 0;
}

int power(int base, int n)
 {
    if (n != 0)
        return (base * power(base, n - 1));
    else
        return 1;
}