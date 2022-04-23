#include <stdio.h>
#include <stdlib.h>

//Program to Store Data in Structures Dynamically


typedef struct
{
    int marks;
    char grade;
}info;


int main()
{
    info *arr;
    int size;
    int i;
    info temp;
    char buffer;

    printf("Enter the number of students: ");
    scanf("%d", &size);
    

    arr = (info*)malloc(size * sizeof(info));

    for (i = 0; i < size; i++)
    {
        scanf("%c", &buffer);
        printf("Enter the grade of sudent %d: ", i + 1);
        scanf("%c", &temp.grade);
        
        printf("Enter the marks of student %d: ", i+1);
        scanf("%d", &temp.marks);

        arr[i] = temp;
    }


    for (i = 0; i < size; i++)
    {
        printf("The marks of student %d is %d and the grade is %c\n", i+1, arr[i].marks, arr[i].grade);
    }
    return 0;
}