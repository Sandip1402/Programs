#include<stdio.h>
struct stack
{
    int top;
    char arr[];
}s;
int pd(char ch)
{
    if(ch == "*" || "/")
    return 1;
    if(ch == "+" || "-")
    return 0;
}
int operator(char ch)
{
    if((int)ch == 42 || 43 || 45 || 47)
    return 1;
    return 0;
}
int empty(struct stack s)
{
    if(s.top == -1)
    return 1;
    return 0;
}
char* in_po(char exp[])
{
    int i = 0;
    int j = 0; 
    char pos[40];
    s.top = -1;
    s.arr[30];
    while(exp[i] != '\0')
    {
        if(!operator(exp[i]))
        pos[j++] = exp[i];
        else
        {
            if(empty(s))
            {
                s.top++;
                s.arr[s.top] = exp[i];
            }
            else if(pd(exp[i]) > pd(s.arr[s.top]))
            {
                s.top++;
                s.arr[s.top] = exp[i];
            }
            else if(pd(exp[i] == pd(s.arr[s.top])))
            {
                pos[j++] = exp[i];
                pos[j++] = s.arr[s.top];
                s.top--;
            }
            else
            {
                pos[j++] = s.arr[s.top];
                s.arr[s.top] = exp[i];
            }
        }
        i++;
    }
    pos[j] = '\0';
    return pos;
}
int main()
{
    int i;
    char exp[40];
    printf("enter size of expression :\n");
    for(i = 0; exp[i] != '\n'; i++)
    scanf("%c", &exp[i]);
    exp[i] = '\0';
    char* postfix = (char*) malloc(40*sizeof(char));
    postfix = in_po(exp);
    printf("%s", postfix[i]);
return 0;
}