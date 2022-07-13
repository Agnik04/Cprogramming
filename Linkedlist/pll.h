#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    int coef, power;
    struct st* next;
}Node;

Node* create_node(int coef, int pow);
void append(Node** head, int coef, int pow);
Node* padd(Node* h1, Node* h2);
Node* pmult(Node* h1 , Node* h2);
void delist(Node** tmp);