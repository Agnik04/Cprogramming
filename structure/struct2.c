#include <stdio.h>

typedef struct 
{
    float inch;
    int feet;
}Distance;

int main()
{
    Distance d1 , d2 , add;

    printf("Enter the feet: ");
    scanf("%d",&d1.feet);
    printf("Enter the inch: ");
    scanf("%f",&d1.inch);

    printf("Enter the feet: ");
    scanf("%d",&d2.feet);
    printf("Enter the inch: ");
    scanf("%f",&d2.inch);

    add.feet = d1.feet + d2.feet;
    add.inch = d1.inch + d2.inch;

    printf("\nSum of distances = %d\'%.1f\"", add.feet, add.inch);
    return 0;
}