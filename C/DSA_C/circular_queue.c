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
    if((q.re +1)%q.size ==  q.fr)
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
    printf("queue is already full\n");
    else{
    q->re = (q->re + 1) % q->size;
    q->arr[q->re] = val;
    }
    printf("%d %d\n", q->fr, q->re);
}
void dequeue(queue *q)
{
    if(empty(*q))
    printf("queue underflow\n");
    else
    {
        int a;
        q->fr = (q->fr + 1) % q->size;
        a = q->arr[q->fr+1];
    }
    printf("%d %d\n", q->fr, q->re);
}
void display(queue q)
{
    if(!empty(q))
    {
        int i = q.fr+1;
        while(i!=q.re)
        {
            printf("%d ", q.arr[i]);
            printf("\n");
            i = (i+1)%q.size;
        } 
    }  
    else
    printf("queue empty\n");
}
int main()
{
    queue a;
    a.fr = a.re = 0;
    printf("enter size of queue :\n");
    scanf("%d", &a.size);
    a.arr = (int*) malloc(a.size*sizeof(int));
    int choice;
    while(1)
    {
        int val;
        printf("enter choice :\n");
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
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
            case 4: exit(1);
        }
    }   
return 0;
}