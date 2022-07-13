#include <stdio.h>
#include <Stdlib.h>

typedef struct st
{
    struct st *left, *right;
    int data;
}Node;

Node* create_node(int value)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    return tmp;
}

void insert(Node** root , int value)
{
    if(*root == NULL)
        *root = create_node(value);
    else if( value < (*root)->data )
        insert(&(*root)->left , value);
    else
        insert(&(*root)->right , value);
}

Node* b_search(Node* root , int value)
{
    if(root == NULL)
        return NULL;
    
    if(root->data == value)
        return root;
    else if(root->data > value)
        return b_search(root->left , value);
    else
        return b_search(root->right , value);
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
        printf("Press 2 to search a node.\n");
        printf("Press 3 to delete a node.\n");
        printf("press 4 preorder traversal.\n");
        printf("press 5 inorder traversal.\n");
        printf("press 6 postorder traversal.\n");
        printf("press 7 to exit.\n\n");
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
                printf("Enter a value to be searched :");
                scanf("%d",&value);
                tmp = b_search(root , value);

                if(tmp != NULL)
                    printf("The number is present.");
                else
                    printf("The number is not present.");
                break;
            case 3:
                printf("Enter a value to be deleted :");
                scanf("%d",&value);
                delnode(&root , value);
                break;
            case 4:
                if(root == NULL)
                    printf("The tree is empty");
                else
                    preorder(root);
                printf("\n");
                break;
            case 5:
                if(root == NULL)
                    printf("The tree is empty");
                else
                    inorder(root);
                printf("\n");
                break;
            case 6:
                if(root == NULL)
                    printf("The tree is empty");
                else
                    postorder(root);
                printf("\n");
                break;
            case 7:
                return 0;
        }
    }
    return 0;
}