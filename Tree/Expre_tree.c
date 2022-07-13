#include<stdio.h>
#include<stdlib.h>
#define S 100

typedef struct st
{
    struct st* left;
    struct st* right;
    int data;
}Node;

#define ITEM Node*

typedef struct st1
{
    ITEM arr[S];
    int tos;
}Stack;

void init(Stack *pts)
{
    pts->tos = -1;
}

int isFull(Stack *pts)
{
    if(pts->tos == S-1)
        return 1;
    else
        return 0;    
}

int isEmpty(Stack *pts)
{
    if(pts->tos == -1)
        return 1;
    else
        return 0;
}

int push(Stack *pts , ITEM data)
{
    if(isFull(pts) == 1)
        return 0;
    pts->tos++;
    pts->arr[pts->tos] = data;
}

ITEM pop(Stack *pts)
{
    ITEM tmp;
    if(isEmpty(pts) == 1)
        return NULL;
    tmp = pts->arr[pts->tos];
    pts->tos--;
    return tmp;
}

ITEM peek(Stack *pts)
{
    if(isEmpty(pts) == 1)
        return NULL;
    return pts->arr[pts->tos];
}

Node* create_node(int value)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = value;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void pop_n_push(Stack *op , Stack *tree)
{
    Node* tmp;
    tmp = pop(op);
    tmp->right = pop(tree);
    tmp->left = pop(tree);
    push(tree , tmp);
}

int pred(char ch)
{
    if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else
        return 1;
    
}

Node* convert(char arr[])
{
    int i;
    Stack op , tree;
    init(&op);
    init(&tree);
    for(i=0; arr[i] != '\0'; i++)
    {
        if(arr[i]>='0' && arr[i]<='9')
            push(&tree , create_node(arr[i]));
        else
        {
            switch(arr[i])
            {
                case '(':
                    push(&op , create_node(arr[i]));
                    break;
                case ')':
                    while(peek(&op)->data != '(')
                        pop_n_push(&op , &tree);
                    pop(&op);
                    break;
                default:
                    while(!isEmpty(&op) && pred(peek(&op)->data) >= pred(arr[i]))
                    {
                        pop_n_push(&op , &tree);
                    }
                    push(&op , create_node(arr[i]));
            }
        }        
    }
    while(!isEmpty(&op))
    {
        pop_n_push(&op , &tree);
    }
    return pop(&tree);
}

void preorder(Node* root)
{
    if(root == NULL)
        return;
    printf("%c ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(root == NULL)
        return;    
    inorder(root->left);
    printf("%c ",root->data);
    inorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL)
        return;    
    postorder(root->left);
    postorder(root->right);
    printf("%c ",root->data);
}

int main()
{
    Node* root = NULL;
    char ip[100];
    printf("\nEnter Infix: ");
    fgets(ip , sizeof(ip) , stdin);
    
    root = convert(ip);

    preorder(root);
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}