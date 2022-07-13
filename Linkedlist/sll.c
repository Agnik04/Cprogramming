#include "sll.h"

Node* create_node(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->data = value;
    temp->next = NULL;

    return temp;
}

void add_begin(Node** head, int value)
{
    Node* temp = create_node(value);

    if(*head == NULL)
    {
        *head = temp;
        return;
    }
    
    temp->next = *head;
    *head = temp;
}

void append(Node** head, int value)
{
    Node* temp = create_node(value);
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

void traverse(Node* head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");   
}

void insert_after(Node* ptr, int value)
{
    Node* temp = create_node(value);

    temp->next = ptr->next;
    ptr->next = temp;
}

void delete_after(Node* ptr)
{
	Node* tmp;
	if(ptr == NULL)
		return;
	tmp = ptr->next;
	ptr->next = tmp->next;
	free(tmp);
}

void delete_begin(Node** ptrhead)
{
	Node* tmp;
	if(*ptrhead == NULL)
		return;
	tmp = (*ptrhead);
	*ptrhead = tmp->next;
	free(tmp);
}

void reverse(Node** head)
{
	Node* prev = NULL;
	Node* current = *head;
	Node* succ;
	
	if(*head == NULL)
		return;
	
	while(current != NULL)
	{
		succ = current->next;
		current->next = prev;
		prev = current;
		current = succ;
	}
	*head = prev;
}

void insertion_sort(Node** head)
{
	Node  * current;
	Node *prev;
	Node *p, *q;
	
	if(*head == NULL) 
		return;
	/*algorithm*/
	current = (*head)->next;
	prev = *head;
	while(current != NULL)
	{
		p = NULL;
		q = *head;		
		while(q->data < current->data && q != current)
		{
			p = q;
			q = q->next;
		}
		/*to be inserted between p and q*/
		if(q != current)
		{
			prev->next = current->next;
			current->next = q;
			/*curr is the samllest at this moment*/
			if(p == NULL)
			{
				*head = current;
			}
			else
			{/*between p&q*/	
				p->next = current;
			}
			current = prev->next;
			
		}
		/*curr is placed in its position*/
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

Node* search(Node* head, int n)
{
	int i = 1;
	
	
	if(head == NULL)
		return NULL;
	
	while(n>0 && head != NULL)
	{
		if(i == n)
			return head;
		else
		{
			head = head->next;
			i++;
		}
	}
	
	
}