#include <stdio.h>
#include <stdlib.h>

#define item int

typedef struct st
{
    item* arr;
    int size;
    int rear;
}Heap;

void init(Heap *hp , int size)
{
    hp->arr = (item*)malloc(sizeof(item)*size);
    hp->size = size;
    hp->rear = -1;
}

void swap(item *a , item *b)
{
    item c = *a;
    *a = *b;
    *b = c;
}

void add_maxheap(Heap *hp , int value)
{
    int parent , child;

    if(hp->rear == hp->size-1)
        return;
    
    ++hp->rear;
    hp->arr[hp->rear] = value;

    child = hp->rear;

    while(child != 0)
    {
        parent = (child - 1)/2;

        if(hp->arr[child] > hp->arr[parent])
            swap(&(hp->arr[child]) , &(hp->arr[parent]));
        
        child = parent;
    }
}

void add_minheap(Heap *hp , int value)
{
    int parent , child;

    if(hp->rear == hp->size-1)
        return;
    
    ++hp->rear;
    hp->arr[hp->rear] = value;

    child = hp->rear;

    while(child != 0)
    {
        parent = (child - 1)/2;

        if(hp->arr[child] < hp->arr[parent])
            swap(&(hp->arr[child]) , &(hp->arr[parent]));
        
        child = parent;
    }
}

void delete(Heap *hp)
{
    int child, parent;

    swap(&(hp->arr[0]) , &(hp->arr[hp->rear]));
    free(&(hp->arr[hp->rear]));
    --hp->rear;

    child = hp->rear;

    while(child != 0)
    {
        parent = (child - 1)/2;

        if(hp->arr[child] < hp->arr[parent])
            swap(&(hp->arr[child]) , &(hp->arr[parent]));
        
        child = parent;
    }
}

void display(Heap hp)
{
    int i;

    for(i=0; i<hp.size; ++i)
    {
        printf("%d ",hp.arr[i]);
    }
    printf("\n");
}

int main()
{
    Heap h1, h2;

    init(&h1, 7);
    init(&h2, 7);

    add_maxheap(&h1, 52);
    add_maxheap(&h1, 41);
    add_maxheap(&h1, 96);
    add_maxheap(&h1, 36);
    add_maxheap(&h1, 78);
    add_maxheap(&h1, 96);
    add_maxheap(&h1, 14);

    display(h1);
    //delete(&h1);

    add_minheap(&h2, 52);
    add_minheap(&h2, 41);
    add_minheap(&h2, 96);
    add_minheap(&h2, 36);
    add_minheap(&h2, 78);
    add_minheap(&h2, 96);
    add_minheap(&h2, 14);

    display(h2);
    return 0;
}