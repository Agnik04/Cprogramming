//splay,split,join
#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
    int data;
    struct st *left;
    struct st *right;
}tree;

tree* getnode(int val)
{
    tree* temp = (tree*)malloc(sizeof(tree));
    temp->data = val;
    temp->right = temp->left = NULL;

    return temp;
}

void preorder(tree* root)
{
    if(root == NULL)
        return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void zig(tree** ptr)//right rotation
{
    tree* temp;

    if(*ptr == NULL || (*ptr)->left == NULL)
        return;

    temp = (*ptr)->left->right;
    (*ptr)->left->right = *ptr;
    *ptr = (*ptr)->left;
    (*ptr)->right->left = temp;
}

void zag(tree** ptr)//left rotation
{
    tree* temp;

    if(*ptr == NULL || (*ptr)->right == NULL)
        return;

    temp = (*ptr)->right->left;
    (*ptr)->right->left = *ptr;
    *ptr = (*ptr)->right;
    (*ptr)->left->right = temp;
}
/*Move the key to the root if key is present.
For unsuccessful search,the last accessed item is moved to root*/
void splay(tree** ptr,int key)
{
    if(*ptr != NULL && (*ptr)->data == key)
        return;
    else if(key < (*ptr)->data)
    {
        if((*ptr)->left == NULL)//unsuccessful search
            return;
        if(key < (*ptr)->left->data)
        {
            splay(&(*ptr)->left->left,key);
            zig(ptr);//zig on grandp
        }
        else if(key > (*ptr)->left->data)
        {
            if((*ptr)->left->right != NULL)
            {
                splay(&(*ptr)->left->right,key);
                zag(&(*ptr)->left);
            }
        }
    }
    if((*ptr)->left != NULL)
        zig(ptr);
}
/*void lsplit(tree* root,int key)
{
    tree* temp;
    temp = root->right;
    
}*/

/*void insert(tree** ptr,int key)
{
    tree *temp;

    if(*ptr == NULL)
        *ptr = getnode(key);

    else
    {
        splay(&ptr,key);

        if(key < (*ptr)->data)
            insert(&(*ptr)->left,key);
        else if(key > (*ptr)->data )
            insert(&(*ptr)->right,key);
        else
            insert(&(*ptr),key);
    }
}*/
void Binsert(tree** root,int key)
{
    if(*root == NULL)
        *root = getnode(key);
    
    else if(key < (*root)->data)
        Binsert(&(*root)->left,key);
    
    else
        Binsert(&(*root)->right,key);
}
/*tree* delete(tree** ptr,int key)
{
    tree* temp;
    if(*ptr == NULL)
        return NULL;
    
    splay(ptr,key);

    if((*ptr)->data != key)
        return *ptr;
    if((*ptr)->left == NULL)//if there is no left child
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
    }
    else
    {
        temp = *ptr;
        splay(&(*ptr)->left,key);
        (*ptr)->right = temp->right;
    }
    free(temp);
    return *ptr;
}*/

int main()
{
    tree* root;
    
    Binsert(&root,12);
    Binsert(&root,5);
    Binsert(&root,21);
    Binsert(&root,2);
    Binsert(&root,7);
    Binsert(&root,19);
    Binsert(&root,32);

    printf("\nThe traversal of the tree before splaying\n");
    preorder(root);

    splay(&root,20);
    //splay(&root,21);
    printf("\nThe traversal of the tree after splaying\n");
    preorder(root);

    return 0;
}