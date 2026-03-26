#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int data;
    struct stack* next;
}stack;
// stack *top; global pointer
int isempty(stack *top)
{
    if(top == NULL)
    return 1;
    return 0;
}
int isfull(stack *top)
{
    stack *n = (stack*) malloc(sizeof(stack));
    if(n == NULL)
    return 1;
    return 0;
}
stack* push(stack *top, int val)
{
    if(isfull(top))
    printf("stack overflow\n");
    else
    {
        stack *p = (stack*) malloc(sizeof(stack));
        p -> data = val;
        p -> next = top;
        top = p;
    }
    return top;
}
// we can use global variable to avoid **
int pop(stack **top)
{
    if(isempty(*top))
    {
        printf("stack underflow\n");
        return 0;
    }
    else
    {
        stack *p = (stack*) malloc(sizeof(stack));
        p = (*top);
        (*top) = (*top) -> next;
        int x = p -> data;
        free(p);
        return x;
    }
}
void peek(stack *top, int position)
{
    stack *p;
    p = top;
    int i = 0;
    while(i < position - 1 && p != NULL)
    {
        p = p -> next;
        i++;
    }
    if(p != NULL)
    printf("peeked value is :%d\n", p -> data);
    else
    printf("invalid position.\n");
}
void stacktop(stack *top)
{
    printf("topmost element :%d\n",top -> data);
}
void stackbottom(stack *top)
{
    stack *p;
    p = top;
    while(p -> next != NULL)
    {
        p = p -> next;
    }
    printf("bottommost element :%d\n",p -> data);
}
void printlinkedlist(stack *ptr)
{
    while(ptr != NULL){
    printf("%d\n", ptr->data);
    ptr = ptr->next;
    }
}
int main()
{
    stack *top;
    top = NULL;
    printf("%d", isempty(top));
    printf("\n");
    top = push(top,5);
    top = push(top,13);
    top = push(top,36);
    top = push(top,51);
    peek(top,6);
    stacktop(top);
    stackbottom(top);
    // printf("popped element : %d ", pop(&top));
    // printf("\n");
    // printlinkedlist(top);
    // top -> data = 5;
    // top -> next = second;
    // second -> data = 23;
    // second -> next = third;
    // third -> data = 56;
    // third -> next = fourth;
    // fourth -> data = 31;
    // fourth -> next = fifth;
    // fifth -> data = 22;
    // fifth -> next = NULL;
    // printf("\n");
    // printf("%d",isempty(top));
    // printf("\n");
    // printf("%d",isfull(top));
return 0;
}