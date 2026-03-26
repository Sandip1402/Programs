#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void printlist(struct node *head)
{
    struct node *p = head;
    do
    {
        printf("element : %d\n", p->data);
        p = p -> next;
    } while (p != head);
}
struct node* insertnewhead(struct node* head, int data)
{
    struct node* ptr = (struct node*) malloc (sizeof(struct node));
    struct node* p;
    p = head -> next;
    ptr -> data = data;
    while(p -> next != head)
    {
        p = p -> next;
    }
    ptr -> next = p -> next;
    p -> next = ptr;
    head = ptr;
    return head;
}
int main()
{
    struct node *head, *second, *third, *fourth, *fifth;
    head = (struct node*) malloc (sizeof(struct node));
    second = (struct node*) malloc (sizeof(struct node));
    third = (struct node*) malloc (sizeof(struct node));
    fourth = (struct node*) malloc (sizeof(struct node));
    fifth = (struct node*) malloc (sizeof(struct node));
    head -> data = 43;
    head -> next = second;
    second -> data = 22;
    second -> next = third;
    third -> data = 6;
    third -> next = fourth;
    fourth -> data = 73;
    fourth -> next = fifth;
    fifth -> data = 17;
    fifth -> next = head;
    printlist(head);
    printf("after insertion : \n");
    // head = insertnewhead(head, 44);
    // head = insertnewhead(head, 23);
    printlist(head);
return 0;
}