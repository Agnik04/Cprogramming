#include<stdio.h>
#include <stdlib.h>

#define ITEM char
#define S 10
typedef struct 
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

void push(Stack *pts , ITEM data)
{
    if(isFull(pts)==1)
        return;
    pts->tos++;
    pts->arr[pts->tos] = data;
}

ITEM pop(Stack *pts)
{
    ITEM tmp;
    if(isEmpty(pts)==1)
        return 0;
    tmp = pts->arr[pts->tos];
    pts->tos--;
    return tmp;
}

ITEM peek(Stack *pts)
{
    if(isEmpty(pts)==1)
        return 0;
    return pts->arr[pts->tos];
}

int match(char temp, char exp)
{
    if (temp == '[' && exp == ']')
        return 1;
    if (temp == '{' && exp == '}')
        return 1;
    if (temp == '(' && exp == ')')
        return 1;
    return 0;
}

int check(Stack *pts, FILE *exp)
{
    char temp;
    char ch;
    while ((ch = fgetc(exp)) != EOF)
    {

        if (ch == '(' || ch == '{' || ch == '[')
            push(pts, ch);
        if (ch == ')' || ch == '}' || ch == ']')
        {
            if (pts->tos == -1)
                return 0;
            else
            {
                temp = pop(pts);
                if (!match(temp, ch))
                    return 0;
            }
        }
    }

    if (pts->tos == -1)
        return 1;
    else
        return 0;
}

int main()
{
    FILE *fp;
    Stack s;
    init(&s);
    int c;
    fp = fopen("code.c", "r");
    c = check(&s, fp);
    if (c == 1)
        printf("Properly parenthesized\n");
    else
        printf("\nNot Properly parenthesized\n");
    fclose(fp);

    return 0;
    
}