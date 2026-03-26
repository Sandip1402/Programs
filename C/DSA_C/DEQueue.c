#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int fr;
    int re;
    int data;
    int *arr;
    int size;
}queue;

void enqueueF(queue *q, int val)
{
    if(q->fr >= 0)
    {
        int val;
        printf("enter value to enqueue at front :");
        scanf("%d", &val);
        q->arr[q->fr] = val;
        q->fr--;
    }
    else
    {
        printf("Enqueue at front not possible!\n");
    }
}

void enqueueR(queue *q, int val)
{
    if(q->re < q->size-1)
    {  
        int val;
        printf("enter value to enqueue at rear:");
        scanf("%d", &val);
        q->re++;
        q->arr[q->re] = val;
    }
    else
    {
        printf("enqueue at rear not possible!\n");
    }
}

void dequeueF(queue *q)
{
    if(q->fr != q->re)
    {
        int a;
        a = q->arr[q->fr+1];
        q->fr++;
        printf("dequeued element : %d\n",a);
    }
    else
    {
        printf("Dequeue at front not possible!\n");
    }
}

void dequeueR(queue *q)
{
    if(q->re <= q->size-1)
    {
        int a;
        a = q->arr[q->re];
        q->re--;
        printf("dequeued element : %d\n",a);
    }
    else
    {
        printf("Dequeue at rear not possible!\n");
    }
}

void display(queue *q)
{
    int i = q->fr+1;
    printf("start index : %d\n", i);
    while(i <= q->re)
    {
        printf("%d ",q->arr[i]);
        i++;
    }
    printf("\nend index : %d\n", i-1);
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
        printf("1.enqueueR\n2.enqueueF\n3.dequeueF\n4.dequeueR\n5.display\n6.exit\n");
        scanf("%d", &choice);
        switch(choice)
        { 
            case 1: enqueueR(&a, val);
                    break;
            case 2: enqueueF(&a, val);
                    break;
            case 3: dequeueF(&a);
                    break;
            case 4: dequeueR(&a);
                    break;
            case 5: display(&a);
                    break;
            case 6: exit(1);
        }
    }    
return 0;
}