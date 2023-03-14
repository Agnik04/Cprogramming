#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

/*typedef struct st
{
    struct st* prev;
    struct st* next;
    char* data;
}Node;*/

typedef struct st
{
    int front , rear, size;
    char* arr;
}Queue;

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

void enqueue(Queue *q , char* value)
{
    if(isfull(q) == 1)
        return;
    else{
        if(q->front == -1)
            q->front = 0;
        if(q->rear == q->size-1)
            q->rear = 0;
        else
            ++q->rear;

        q->arr[q->rear] = value;
    }
}

int dequeue(Queue *q)
{
    int tmp;
    if(isempty(q) == 1)
        return 0;
    else
    {
        tmp = q->arr[q->front];

        if(q->front == q->rear)
            q->front = q->rear = -1;
        else if(q->front == q->size-1)
            q->front = 0;
        else
            q->front++;
        return tmp;
    }
}

void display(Queue *q, int n)
{
    do
    {
        printf("%s ",q->arr[q->rear]);
    }while(1);
}

/*Node* create_node(char value)
{
    Node* tmp = (Node*)malloc(sizeof(Node));

    tmp->prev = tmp->next = tmp;
    tmp->data = strdup(value);

    return tmp;
}

void append(Node** head, char* value)
{
    Node* tmp = create_node(value);

    if(*head == NULL)
    {
        *head = tmp;
        return;
    }

    tmp->prev = (*head)->prev;
    tmp->next = *head;
    (*head)->prev->next = tmp;
    (*head)->prev = tmp;
}

Node* search_track(Node* head , int position)
{
    int i = 1, count = 1;
    Node* temp = head;

    if(head == NULL)
        return NULL;

    if(position <= 0)
        return NULL;

    while(temp->next != head)
    {
        temp = temp->next;
        count++;
    }

    if(position > count)
        return NULL;

    for(i=1; i<position; i++)
    {
        head = head->next;
    }

    return head;
}

void traverse(Node* head)
{
    Node* current = head;

    if(head == NULL)
        return;
    do
    {
        printf("%s", current->data);
        current = current->next;
    }while (current != head);
    printf("\n");
}

void delete(Node **head, int pos)
{
    Node *position = NULL, *tmp = NULL;

    if (pos == 1)
    {
        tmp = *head;
        (*head)->next->prev = (*head)->prev;
        (*head) = (*head)->next;
        free(tmp);
    }
    else
    {
        position = search_track(*head, pos);

        tmp = position->prev;
        tmp->next = position->next;
        position->next->prev = tmp;
        free(position);
    }
}*/

int main()
{
    //Node* head = NULL;
    int size, ch, n;
    char str[40];
    Queue q, q1, q2;

    printf("Enter the size of train seats :");
    scanf("%d",&size);
    init(&q, size);
    init(&q1, 100);
    init(&q2, size);

    while(1)
    {
        printf("Press 1 to book railway ticket.\n");
        printf("Press 2 for cancel booking.\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                /*printf("Enter the number of reservation :");
                scanf("%d",&n);*/

                if(isfull(&q) == 1)
                {
                    printf("Seat Full\n");
                    printf("Enter the name : ");
                    fgets(str,sizeof(str),stdin);
                    enqueue(&q1 , str);
                }
                else
                {
                    printf("Enter the name : ");
                    fgets(str,sizeof(str),stdin);
                    enqueue(&q , str);
                }
        }
    }

    return 0;
}