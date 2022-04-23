#include<stdio.h>

typedef struct{
    int hour;
    int minute;
    int second;
}time;

time sub(time t1,time t2)
{
    time d;
    if(t1.second<t2.second){
        t1.second=t1.second+60;
        d.second=t1.second-t2.second;
        t1.minute--;
    }
    else{
        d.second=t1.second-t2.second;
    }
    if(t1.minute<t2.minute){
        t1.minute=t1.minute+60;
        d.minute=t1.minute-t2.minute;
        t1.hour--;
    }
    else{
        d.minute=t1.minute-t2.minute;
    }
    d.hour=t1.hour-t2.hour;
    
        
    return d;
}
int main()
{
    time t1,t2;
    time difference;

    printf("enter the hour ");
    scanf("%d",&t1.hour);

    printf("enter the minute ");
    scanf("%d",&t1.minute);

    printf("enter the second ");
    scanf("%d",&t1.second);

    printf("enter the hour ");
    scanf("%d",&t2.hour);

    printf("enter the minute ");
    scanf("%d",&t2.minute);

    printf("enter the second ");
    scanf("%d",&t2.second);

    difference=sub(t1,t2);

    printf("the hour %d ",difference.hour);
    printf("the minute %d ",difference.minute);
    printf("the second %d ",difference.second);
    return 0;
}