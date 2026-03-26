#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isempty(struct stack *p)
{
    if(p -> top == -1)
    return 1;
    return 0;
}
int isfull(struct stack *p)
{
    if(p -> top == p -> size-1)
    return 1;
    return 0;
}
void pop(struct stack *s)
{
    if(isempty(s))
    printf("stack underflow");
    else
    {
        int a = s->arr[s->top];
        s->top--;
        printf("%d", a);
    }
}
void peek(struct stack* s, int p)
{
    if(s->top-p+1<0)
    {
        printf("position not valid");
    }
    else
    printf("value at %d position is %d\n", s->arr[s->top-p+1],p);
}
void push(struct stack *s,int value)
{
    if(isfull(s))
    printf("stack overflow");
    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
}
void stackTop(struct stack *s)
{
    printf("top most value is %d\n", s->arr[s->top]);
}
void stackBottom(struct stack *s)
{
    printf("bottom most value is %d\n", s->arr[0]);
}
int main()
{
    struct stack *s = (struct stack*) malloc(sizeof(struct stack));
    s -> size = 6;
    s -> top = -1;
    s -> arr = (int*) malloc((s->size)*sizeof(int));
    printf("enter elements :\n");
    while(s->top < 5)
    {
        s -> top++;
        scanf("%d", s->arr + s-> top);
    }
    // printf("elements are :\n");
    // for(int i = 1; i <= s->top + 1; i++)
    // {
    //     peek(s,i);
    // }
    // push(s,8);
    // pop(s);
    stackTop(s);
    stackBottom(s);
    free(s);
return 0;
}