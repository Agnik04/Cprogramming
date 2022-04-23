#include <stdio.h>

typedef struct
{
    int real;
    int imaginary;
}complex;

int main()
{
    complex c1 ,c2 ,add;

    printf("Enter the real number of 1st complex number: ");
    scanf("%d",&c1.real);
    printf("Enter the imaginary number of 1st complex number: ");
    scanf("%d",&c1.imaginary);

    printf("Enter the real number of 2nd complex number: ");
    scanf("%d",&c2.real);
    printf("Enter the imaginary number of 2nd complex number: ");
    scanf("%d",&c2.imaginary);

    add.real = c1.real + c2.real;
    add.imaginary = c1.imaginary + c2.imaginary;

    printf("Sum of complex number is %d + i%d",add.real,add.imaginary);
    
    return 0;
}
