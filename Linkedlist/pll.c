#include "pll.h"

Node* create_node(int coef, int pow)
{
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->coef = coef;
    temp->power = pow;
    temp->next = NULL;

    return temp;
}

void append(Node** head, int coef, int pow)
{
    Node* temp = create_node(coef, pow);
    Node* current = *head;

    if(*head == NULL)
    {
        *head = temp;
        return;
    }

    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = temp;
}

Node* padd(Node* h1, Node* h2)
{
    Node* h3 = NULL;

    while(h1 != NULL && h2 != NULL)
    {
        if(h1->power > h2->power)
        {
            append(&h3, h1->coef, h1->power);
            h1 = h1->next;
        }
        else if(h2->power > h1->power)
        {
            append(&h3, h2->coef, h2->power);
            h2 = h2->next;
        }
        else{
            append(&h3, h1->coef + h2->coef, h1->power);
            h1 = h1->next;
            h2 = h2->next;
        }
    }

    while(h1 != NULL)
    {
        append(&h3, h1->coef, h1->power);
        h1 = h1->next;
    }

    while(h2 != NULL)
    {
        append(&h3, h2->coef, h2->power);
        h2 = h2->next;
    }

    return h3;
}

void dellist(Node** tmp)
{
    Node* ptr = *tmp;

    if(*tmp == NULL)
        return;
    while((*tmp)->next != NULL)
    {
        ptr = *tmp;
        *tmp = (*tmp)->next;
        free(ptr);
    }
    free(*tmp);
}

Node* pmult(Node* h1 , Node* h2)
{
    Node* h3 = NULL , *tmp = NULL , *ptr;

    while(h2 != NULL)
    {
        ptr = h1;
        while(h1 != NULL)
        {
            append(&tmp , ptr->coef * h2->coef , ptr->power + h2->power);
            ptr = ptr->next;
        }
        h3 = padd(h3 , tmp);
        h2 = h2->next;
        dellist(&tmp);
    }
    return h3;
}