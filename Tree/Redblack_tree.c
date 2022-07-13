#include <stdio.h>
#include <Stdlib.h>

typedef struct st
{
    struct st *left, *right, *parent;
    int data;
    char colour;
}Node;

Node* create_node(int value)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->left = tmp->right = tmp->parent = NULL;
    tmp->data = value;
    tmp->colour = 'r';
    return tmp;
}

int depth(Node* root)
{
    int lh, rh;
    if(root == NULL)
        return 0;
    lh = depth(root->left);
    rh = depth(root->right);
    return (lh>rh)? lh+1 : rh+1;
}

void leftrotate(Node** root)
{
    if((*root) == NULL || (*root)->right == NULL)
        return;
    
    Node* tmp = (*root)->right->left;
    (*root)->right->left = (*root);
    (*root) = (*root)->right;
    (*root)->left->right = tmp;
}

void rightrotate(Node** root)
{
    if((*root) == NULL || (*root)->left == NULL)
        return;
    
    Node* tmp = (*root)->left->right;
    (*root)->left->right = (*root);
    (*root) = (*root)->left;
    (*root)->right->left = tmp;
}

void insert(Node** root , int value)
{
    if(*root == NULL)
    {
        *root = create_node(value);
        (*root)->colour = 'b';
        return;
    }
    else if( value < (*root)->data )
    {
        insert(&(*root)->left , value);
    }
    else
        insert(&(*root)->right , value);
}