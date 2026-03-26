#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void printlinkedlist(struct node *p)
{
    while(p != NULL){
    printf("%d\n", p->data);
    p = p->next;
    }
}
//case 1
struct node* insertatfirst(struct node *head, int data)
{
    struct node *ptr = (struct node*) malloc (sizeof(struct node));
    ptr -> data = data;
    ptr -> next = head;
    head = ptr;
    return head;
}
//case 2
struct node* insertatindex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node*) malloc (sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while(i < index - 1)
    {
        p = p -> next;
        i++;
    }
    ptr -> data = data;
    ptr -> next = p -> next; 
    p ->next = ptr;
    return head;
}
//case 3
struct node* insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node*) malloc (sizeof(struct node));
    struct node *p = head;
    while(p -> next != NULL)
    {
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> data = data;
    ptr -> next = NULL;
    return head;
}
//case 4
struct node* insertafter(struct node *head, struct node* p, int data)
{
    struct node *ptr = (struct node*) malloc (sizeof(struct node));
    ptr -> data = data;
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
};
//case 5
struct node* deleteatfirst(struct node* head)
{
    struct node *ptr = (struct node*) malloc (sizeof(struct node));
    ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}
//case 6
struct node* deleteatindex(struct node *head, int index)
{
    struct node* ptr = (struct node*) malloc (sizeof(struct node));
    struct node* p = head;
    int i = 0;
    while(i != index - 1)
    {
        p = p -> next;
        i++;
    }
    ptr = p -> next;
    p -> next  = ptr -> next;
    free(ptr);
    return head;
}
//case 7
//try using while loop
struct node* deleteatend(struct node *head)
{
    struct node* ptr = (struct node*) malloc (sizeof(struct node));
    struct node* p = head;
    while(ptr -> next != NULL)
    {
        p = p -> next;
        ptr = p -> next;
    }
    p -> next = NULL;
    free(ptr);
    return head;
}
//case 8
struct node* deleteafter(struct node *head, struct node *p)
{
    struct node* ptr = (struct node*) malloc (sizeof(struct node));
    ptr = p;
    ptr = p -> next;
    p -> next = ptr -> next;
    free(ptr);
    return head;
}
//case 9
struct node* deleteatvalue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head -> next;
    while(q -> data != value && q -> next != NULL)
    {
        p = p -> next;
        q = q -> next;
    }
    if(q -> data == value)
    {
        p -> next = q -> next;
        free(q);
    }
    return head;
}
int main()
{   
    struct node *head, *second, *third, *fourth, *ptr;
    head = (struct node*) malloc (sizeof(struct node));
    second = (struct node*) malloc (sizeof(struct node));
    third = (struct node*) malloc (sizeof(struct node));
    fourth = (struct node*) malloc (sizeof(struct node));
    head -> data = 12;
    head -> next = second;
    second -> data = 8;
    second -> next = third;
    third -> data = 22;
    third -> next = fourth;
    fourth -> data =9;
    fourth -> next = NULL;
    printlinkedlist(head);
    head = deleteatvalue(head,22);
    printf("\n");
    printlinkedlist(head);
return 0;
}