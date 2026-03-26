#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int size;
    int top;
    char *arr;
}stack;
int isfull(stack *p)
{
    if(p -> top == p -> size-1)
    return 1;
    return 0;
}
char pop(stack *s)
{
        char a = s->arr[s->top];
        s->top--;
        return a;
}
void push(stack *s,char value)
{
        s->top++;
        s->arr[s->top] = value;
}
int isempty(stack *p)
{
    if(p->top == -1)
    return 1;
    return 0;
}
int parenthesis(char a[])
{
    stack *p;
    p -> size = 100;
    p -> top = -1;
    p -> arr = (char*)malloc(p->size*sizeof(char));
    int i;
    for(i = 0; a[i] != '\0'; i++)
    {
        if(a[i] == '(')
        push(p,a[i]);
        if(a[i] == ')')
        {
            if(isempty(p))
            return 0;
            pop(p);
        }
    }
    if(isempty(p))
    return 1;
    return 0;
}
int main()
{
    int size;
    char a[] = "(6*)3(438+53)";
    if(parenthesis(a))
    printf("equation balanced.");
    else
    printf("equation not balanced.");
return 0;
}