#include <stdio.h>

int lab(int,int);

int main() 
{
    int days, n, result;
    printf("Enter days number: ");
    scanf("%d", &days);
    printf("Enter the number of bacteria taken(positive integer): ");
    scanf("%d", &n);
    result = lab(days, n);
    printf("The number of bacteria at last %d",result);
    
    return 0;
}

int lab(int days, int n)
 {
    if (days == 0)
        return n;
    else
        return lab((days - 1), n*2);
    
}