#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    struct st *left, *right;
    int data, bfactor;
}Node;

Node* create_node(int value)
{
    Node* tmp = (Node*)malloc(sizeof(Node));

    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->bfactor = 0;
    
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

void updatefactor(Node* root)
{
    if(root != NULL)
        return;
    root->bfactor = depth(root->left) - depth(root->right);
}

void leftrotate(Node** root)
{
    if((*root) == NULL || (*root)->right == NULL)
        return;
    
    Node* tmp = (*root)->right->left;
    (*root)->right->left = (*root);
    (*root) = (*root)->right;
    (*root)->left->right = tmp;

    updatefactor(*root);
    updatefactor((*root)->left);
}

void rightrotate(Node** root)
{
    if((*root) == NULL || (*root)->left == NULL)
        return;
    
    Node* tmp = (*root)->left->right;
    (*root)->left->right = (*root);
    (*root) = (*root)->left;
    (*root)->right->left = tmp;

    updatefactor(*root);
    updatefactor((*root)->right);
}

void balancenode(Node** root)
{
    if(*root == NULL)
        return;
    if(*root)
    {
        updatefactor(*root);
        if((*root)->bfactor > 1)
        {
            if((*root)->left->bfactor < 0)
                leftrotate(&(*root)->left);
            rightrotate(root);
        }
        else if((*root)->bfactor < -1)
        {
            if((*root)->right->bfactor > 0)
                rightrotate(&(*root)->right);
            leftrotate(root);
        }
        else
            return;
    }
}

void insert(Node** root , int value)
{
    if(*root == NULL)
        *root = create_node(value);
    else
    {
        if(value < (*root)->data)
            insert(&(*root)->left , value);
        else
            insert(&(*root)->right , value);
        balancenode(root);
    }
}

void delnode(Node** root , int key)
{
    Node* tmp;
    if(*root == NULL)
        return;
    
    if(key < (*root)->data)
        delnode(&(*root)->left , key);
    else if(key > (*root)->data)
        delnode(&(*root)->right , key);
    else if(key == (*root)->data)
    {
        if((*root)->left == NULL && (*root)->right == NULL)
            *root = NULL;
        else if((*root)->left != NULL && (*root)->right == NULL)
        {
            tmp = *root;
            *root = (*root)->left;
            free(tmp);
        }
        else if((*root)->left == NULL && (*root)->right != NULL)
        {
            tmp = *root;
            *root = (*root)->right;
            free(tmp);
        }
        else
        {
            tmp = (*root)->right;
            while(tmp->left != NULL)
                tmp = tmp->left;
            (*root)->data = tmp->data;
            delnode(&(*root)->right , tmp->data);
        }
        if(*root != NULL)
            balancenode(root);
    }
}

void preorder(Node* root)
{
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(root == NULL)
        return;    
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL)
        return;    
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main()
{
    Node* root = NULL, *tmp;
    int ch, value;

    while(1)
    {
        printf("Press 1 to insert a node.\n");
        printf("Press 2 to delete a node.\n");
        printf("press 3 preorder traversal.\n");
        printf("press 4 inorder traversal.\n");
        printf("press 5 postorder traversal.\n");
        printf("press 6 to exit.\n\n");
        printf("Enter your choice.\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter a value to insert :");
                scanf("%d",&value);
                insert(&root , value);
                break;
            case 2:
                printf("Enter a value to be deleted :");
                scanf("%d",&value);
                delnode(&root , value);
                break;
            case 3:
                if(root == NULL)
                    printf("The tree is empty");
                else
                    preorder(root);
                printf("\n");
                break;
            case 4:
                if(root == NULL)
                    printf("The tree is empty");
                else
                    inorder(root);
                printf("\n");
                break;
            case 5:
                if(root == NULL)
                    printf("The tree is empty");
                else
                    postorder(root);
                printf("\n");
                break;
            case 6:
                return 0;
        }
    }
    return 0;
}