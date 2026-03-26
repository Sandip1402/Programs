#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int size; 
    int fr;
    int re;
    int *arr;
}queue;
int full(queue q)
{
    if(q.re == q.size-1)
    return 1;
    return 0;
}
int empty(queue q)
{
    if(q.fr == q.re)
    return 1;
    return 0;
}
void enqueue(queue *q, int val)
{
    if(full(*q))
    printf("queue overflow\n");
    else
    {
        q->re++;
        q->arr[q->re] = val;
    }
}
void dequeue(queue *q)
{
    if(empty(*q))
    printf("queue underflow\n");
    else
    {
        int a;
        a = q->arr[q->fr+1];
        q->fr++;
    }
}
void display(queue q)
{
    if(!empty(q))
    {
        for(int i=q.fr+1; i<=q.re; i++)
        printf("%d ", q.arr[i]);
        printf("\n");
    }
    else
    printf("queue empty\n");
}
void peek(queue q, int pos)
{
    printf("peeked value : %d\n", q.arr[pos-1]);
}
int main()
{
    queue a;
    a.fr = a.re = -1;
    printf("enter size of queue :\n");
    scanf("%d", &a.size);
    a.arr = (int*) malloc(a.size*sizeof(int));
    int choice;
    while(1)
    {
        int val, pos;
        printf("enter choice :\n");
        printf("1.enqueue\n2.dequeue\n3.display\n4.peek\n5.exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("enter value to enqueue :\n");
                    scanf("%d", &val);
                    enqueue(&a, val);
                    break;
            case 2: dequeue(&a);
                    break;
            case 3: display(a);
                    break;
            case 4: printf("enter position to peek :\n");
                    scanf("%d", &pos);
                    peek(a,pos);
                    break;
            case 5: exit(1);
        }
    }
return 0;
}