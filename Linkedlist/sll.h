#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    int data;
    struct st* next;
}Node;

Node* create_node(int value);
void add_begin(Node** head, int value);
void append(Node** head, int value);
void traverse(Node* head);
void insert_after(Node* ptr, int value);
void delete_after(Node* ptr);
void delete_begin(Node** ptrhead);
void reverse(Node** head);
void insertion_sort(Node** head);
Node* search(Node* head, int n);