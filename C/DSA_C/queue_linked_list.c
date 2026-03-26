#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int data;
    struct NODE* next;
}NODE;
NODE *f = NULL;
NODE *r = NULL;
void enqueue(int val)
{
    NODE *n = (NODE*) malloc(sizeof(NODE));
    if(n == NULL)
    {printf("queue overflow\n");}
    else
    {
        if(f == NULL)
        {
            f ->next = n; // ????
        }
        n->data = val;
        n->next = NULL;
        r->next = n;
        r = n;
        printf("enqued element %d\n",r->data);
    }
}
void dequeue()
{
    if(f == NULL)
    printf("queue underflow\n");
    else
    {
        NODE *n = f;
        f = f->next;
        printf("dequeued element - %d\n",f->data);
        free(n);
    }
}
void display()
{
    NODE *i = f;
    while(i!= NULL)
    {
        printf("%d ", i->data);
        i = i->next;
    }
}
int main()
{
    int val,choice;
    while(1)
    {
        printf("enter choice :\n");
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("enter value to enqueue :\n");
                    scanf("%d", &val);
                    enqueue(val);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: 
                    exit(1);
                    break;
        }
    }
return 0;
}