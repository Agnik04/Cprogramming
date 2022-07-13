#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int* arr;
    int rear, front, size;    
}Queue;

void init(Queue *q, int size);
int isempty(Queue *q);
int isfull(Queue *q);
void enqueue(Queue *q , int value);
int dequeue(Queue *q);

void init(Queue *q, int size)
{
    q->arr = (int*)malloc(sizeof(int)*size);
    q->rear = -1;
    q->front = -1;
}

int isempty(Queue *q)
{
    if(q->front == -1)
        return 1;
    else
        return 0;
}

int isfull(Queue *q)
{
    if((q->front == 0 && q->rear == q->size-1) || (q->front == q->rear+1))
        return 1;
    else
        return 0;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void enqueue(Queue* q , int value)
{
    int child, parent;
    if(isfull(q))
        return;
    else
    {
        ++q->rear;
        q->arr[q->rear] = value;
        child = q->rear;
        while(child != 0)
        {
            parent = (child - 1)/2;

            if(q->arr[parent] < q->arr[child])
            {
                swap(&q->arr[parent], &q->arr[child]);
                child = parent;
            }
            else
                return;
            
        }
    }    
}

int dequeue(Queue* q)
{
    int child, parent, tmp;

    if(isempty(q))
        return;
    else
    {
        tmp = q->arr[0];
        q->arr[0] = q->arr[q->rear--];
        parent = 0;
        do
        {
            child = (2*parent) + 1;
            if(child > q->rear)//left child range
                break;
            
        } while ();
        
    }
    
}