#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* prev;
    struct node* next;
};
int main()
{
    struct node* head, second, third, fourth, fifth;
    head = (struct node*) malloc (sizeof(struct node));
    second = (struct node*) malloc (sizeof(struct node));
    third = (struct node*) malloc (sizeof(struct node));
    head = (struct node*) malloc (sizeof(struct node));
    head = (struct node*) malloc (sizeof(struct node));
return 0;
}