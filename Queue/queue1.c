#include <stdio.h>
#define S 4

typedef struct
{
    int arr[S];
    int rear, front;    
}queue;

void init(queue *q)
{
    q->rear = -1;
    q->front = -1;
}

int isempty(queue *q)
{
    if(q->rear == q->front)
        return 1;
    else
        return 0;
}

int isfull(queue *q)
{
    if((q->front == 0 && q->rear == S-1) || (q->front == q->rear+1))
        return 1;
    else
        return 0;
}

void enqueue(queue *q , int value)
{
    if(isfull(q) == 1)
        return;
    else{
        if(q->front == -1)
            q->front = 0;
        if(q->rear == S-1)
            q->rear = 0;
        else
            ++q->rear;

        q->arr[q->rear] = value;
    }
}

int dequeue(queue *q)
{
    int tmp;
    if(isempty(q) == 1)
        return 0;
    else
    {
        tmp = q->arr[q->front];

        if(q->front == q->rear)
            q->front = q->rear = -1;
        else if(q->front == S-1)
            q->front = 0;
        else
            q->front++;
        return tmp;
    }
}

int main()
{
    queue q;
    int data;
    int ch;

    init(&q);
    while(1)
    {
        printf("\n\n************** M E N U **************\n\n");
        printf("Press 1 check it's ful or not.\n");
        printf("Press 2 check it's empty or not.\n");
        printf("Press 3 to enter value\n");
        printf("Press 4 to delete.\n");
        printf("Press 5 to EXIT.\n");
        printf("Enter your choice: ");  
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:            
                if(isfull(&q)==1)
                    printf("\nQueue is Full.\n\n");
                else    
                    printf("\nQueue is not Full\n\n");
                break;
            case 2:
                if(isempty(&q)==1)
                    printf("\nQueue is Empty.\n\n");
                else
                    printf("\nQueue is not Empty.\n\n");
                break;
            case 3:
                if(isfull(&q)==1)
                    printf("\nOverflow\n");
                else
                {
                    printf("Enter the data you want to push into your stack :");
                            scanf("%d", &data);
                    enqueue(&q, data);                    
                }
                break;
            case 4:
                if(isempty(&q)==1)
                    printf("Underflow\n");
                else
                {
                    printf("The deleted element is = %d\n\n",dequeue(&q));
                }             
                break;
            case 5:
                return 0;
                break;
            default:
                printf("\nEnter a Valid Choice!\n");
        }
    }
    return 0;
}