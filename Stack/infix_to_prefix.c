#include <stdio.h>
#include <string.h>

#define ITEM int
#define S 100
typedef struct
{
    ITEM arr[S];
    int tos;
}stack;

void init(stack *);
int isFull(stack *);
int isEmpty(stack *);
int push(stack *,ITEM);
ITEM pop(stack *);
ITEM peek(stack *);
int pred(char);
char* convert(char*);


int main()
{
    char ip[100] , *res;
    printf("\nEnter Infix: ");
    fgets(ip,sizeof(ip),stdin);
    strrev(ip);
    res = convert(ip);
    strrev(res);
    printf("\n\nPrefix: %s\n\n",res);
    return 0;
}

void init(stack *pts)
{
    pts->tos = -1;
}

int isFull(stack *pts)
{
    if(pts->tos == S-1)
        return 1;
    else
        return 0;
}

int isEmpty(stack *pts)
{
    if(pts->tos == -1)
        return 1;
    else
        return 0;
}

int push(stack *pts , ITEM data)
{
    if(isFull(pts)==1)
        return 0;
    pts->tos++;
    pts->arr[pts->tos] = data;
}

ITEM pop(stack *pts)
{
    ITEM tmp;
    if(isEmpty(pts)==1)
        return 0;
    tmp = pts->arr[pts->tos];
    pts->tos--;
    return tmp;
}

ITEM peek(stack *pts)
{
    if(isEmpty(pts)==1)
        return 0;
    return pts->arr[pts->tos];
}

int pred(char ch)
{
    if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else
        return 1;
}

char* convert(char ip[])
{
    stack s;
    int i , j , tmp;
    static char op[100];
    init(&s);

    for(i=0,j=0 ; ip[i]!='\0' ; i++)
    {
        if(ip[i]>='0' && ip[i]<='9')
            op[j++] = ip[i];
        else
        {
            if(ip[i] == ')')
                push(&s , ip[i]);
            else if(ip[i] == '(')
            {
                do{
                    tmp = pop(&s);
                    if(tmp != ')')
                        op[j++] = tmp;
                }
                while(tmp != ')');
            }
            else
            {
                while(!isEmpty(&s) && pred(peek(&s))>=pred(ip[i]))
                {
                    op[j++] = pop(&s);
                }
                push(&s , ip[i]);
            }
        }
    }
    while(!isEmpty(&s))
    {
        op[j++] = pop(&s);
    }
    op[j] = '\0';
    return op;
}
