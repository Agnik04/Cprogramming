#include <stdio.h>
#include <string.h>

#define ITEM int
#define S 100
typedef struct
{
    ITEM arr[S];
    int tos;
}stack;

//void init(stack *);
//int isFull(stack *);
//int isEmpty(stack *);
//int push(stack *,ITEM);
//ITEM pop(stack *);
//ITEM peek(stack *);
//int evaluate(char * pt);

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
            if(ip[i] == '(')
                push(&s , ip[i]);
            else if(ip[i] == ')')
            {
                do{
                    tmp = pop(&s);
                    if(tmp != '(')
                        op[j++] = tmp;
                }
                while(tmp != '(');
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


float calc(float l,float r,char op)
{
    if(op == '+')
        return l+r;
    else if(op == '-')
        return l-r;
    else if(op == '*')
        return l*r;
    else
        return l/r;

}

float eval(char arr[])
{
    stack s;
    float r,l,res;
    init(&s);
    ITEM i;
    for(i=0; arr[i]!='\0'; i++)
    {
        if(arr[i] >= '0' && arr[i] <= '9')
            push(&s,arr[i]-'0');
        else
        {
            r=pop(&s);
            l=pop(&s);

            res = calc(l,r,arr[i]);

            push(&s,res);
        }
    }

    return pop(&s);
}

int main()
{
    char ip[S],*res;
    printf("\nEnter Infix: ");
    scanf("%s",ip);
    puts(ip);
    res = convert(ip);
    puts(res);
    
    printf("\nThe evaluated expression is %d",eval(res));
    return 0;
}