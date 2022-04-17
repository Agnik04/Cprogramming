#include<stdio.h>
void printName(char* name,int n)
{
    if(n != 0)
    {
        printf("%s \n",name);
        printName(name,n-1);
    }
    else
        return;
}
int main()
{
    char name[50];
    int n;  
    printf("\nEnter you name :"); 
    scanf("%s",name); 
    printf("\nNumber of times to print :");
    scanf("%d",&n);
    printName(name,n); 
    return 0; 
}