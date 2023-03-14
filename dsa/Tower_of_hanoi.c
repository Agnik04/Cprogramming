#include<stdio.h>
void toh(int n, char s, char a, char d)
{
    if(n>1)
        toh(n-1, s, d, a);
    printf("\n%d is moved from %c to %c.",n ,s,d);
    
    if(n>1)
        toh(n-1, a, s, d);
    
}
int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d",&n);
    toh(n,'S','A','D');
    
    return 0;
}