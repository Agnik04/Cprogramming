#include <stdio.h>
#include <stdlib.h>

typedef struct block
{
    char data;
    struct block *next;
} node;

void addbegin(node **head, char value)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    ptr->next = *head;
    *head = ptr;
}

void delbegin(node **head)
{
    if (*head == NULL)
        return;
    node *temp = *head;
    *head = temp->next;
    free(temp);
}

int check(node **head, char exp[])
{
    char ch;
    int i = 0;
    node *tmp = *head;

    if (exp[0] >= 'A' && exp[0] <= 'Z')
    {
        printf("Invalid.");
        return 0;
    }
    while ((ch = exp[i]) != '\0')
    {
        if (ch >= 'a' && ch <= 'z')
            addbegin(&tmp, ch);
        else if (ch >= 'A' && ch <= 'Z')
            break;
        i++;
    }
    i++;
    while ((ch = exp[i]) != '\0')
    {
        if (ch >= 'a' && ch <= 'z')
        {
            if (tmp->data == ch)
                delbegin(&tmp);
            else
                break;
        }
        else if (ch >= 'A' && ch <= 'Z')
            break;
        i++;
    }

    if (tmp == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    node *head = NULL;
    int c;
    char exp[100];

    printf("Enter an expression: ");
    scanf("%s", exp);

    c = check(&head, exp);

    if (c == 1)
        printf("Equal");
    else
        printf("not equal.");
    return 0;
}