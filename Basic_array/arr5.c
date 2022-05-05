/*Multiplication of 2D matrix*/

#include <stdio.h>

int main()
{
    int arr1[10][10],arr2[10][10],mul[10][10];
    int r,c,i,j,k;

    printf("Enter the number of row :");
    scanf("%d",&r);
    printf("Enter the number of column :");
    scanf("%d",&c);

    printf("********Enter the 1st matrix elements*********\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            scanf("%d",&arr1[i][j]);
    }

    printf("\n*********Enter the 2nd matrix elements*********\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            scanf("%d",&arr2[i][j]);
    }

    printf("\nThe 1st matrix is");
    for(i=0;i<r;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
            printf("%d ",arr1[i][j]);
    }

    printf("\nThe 2nd matrix is");
    for(i=0;i<r;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
            printf("%d ",arr2[i][j]);
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            mul[i][j]=0;
            for(k=0;k<c;k++)
                mul[i][j] += arr1[i][k] * arr2[k][j];
        }
    }

    printf("\nThe multiplication of result :");
    for(i=0;i<r;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
             printf("%d ",mul[i][j]);
    }

    return 0;
}

