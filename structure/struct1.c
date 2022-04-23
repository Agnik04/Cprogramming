#include <stdio.h>

#define MAX 3
typedef struct 
{
    char Name[50];
    int roll;
    float marks;
} student;

int main()
{
    student s[MAX];
    int i;
    printf("Enter information of students:\n");

    for (i = 0; i < MAX; i++)
    {
        printf("Enter name: ");
        scanf("%s", s[i].Name);
        printf("Enter the roll: ");
        scanf("%d",&s[i].roll);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
    }
    printf("Displaying Information:\n\n");

    for (i = 0; i < MAX; i++)
    {
        printf("First name: ");
        puts(s[i].Name);
        printf("Roll: %d", s[i].roll);
        printf("Marks: %.1f", s[i].marks);
        printf("\n");
    }
    return 0;
}