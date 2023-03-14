#include<stdio.h>
#define N 5

int check(int arr[][N],int r, int c)
{
    int i,j;
    for(i=r,j=c;j<N;j++)
    {
        if(arr[i][j])
            return 0;
    }
    /*for(i=c,j=r;j<N;j++)
    {
        if(arr[i][j])
            return 0;

    }*/
    for(i=r,j=c;i>=0;i--)
    {
        if(arr[i][j])
            return 0;
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(r-c==i-j && arr[i][j])
                return 0;
            if(r+c==i+j && arr[i][j] )
                return 0;

        }
    }
    return 1;
}
int nqueens(int arr[][N],int i)
{
    int j;
    for(j=0;j<N;j++)
    {
        
        
            if(check(arr,i,j) )
            {
                arr[i][j]=1;
                if(nqueens(arr,i+1))
                    return 1;
                if(i==N-1)
                    return 1;
                else
                    arr[i][j]=0;
            }
            

    }
    return 0;
}
int main()
{
    int i,j,arr[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            arr[i][j]=0;
        }
    }
    nqueens(arr,0);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
    
}