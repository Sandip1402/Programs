#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create_tree(int val)
{
    struct node *p = (struct node*) malloc(sizeof(struct node));
    p->data = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void preorder(struct node* p)
{
    if(p!= NULL)
    {
        printf("%d\n",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(struct node* p)
{
    if(p!= NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d\n",p->data);
    }
}
void inorder(struct node* p)
{
    if(p!= NULL)
    {
        inorder(p->left);
        printf("%d\n",p->data);
        inorder(p->right);
    }
}
int main()
{
    struct node *p, *p1, *p2, *p3, *p4;
    p = create_tree(4);
    p1 = create_tree(5);
    p2 = create_tree(1);
    p3 = create_tree(2);
    p4 = create_tree(3);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p2->right = p4;
    // preorder(p);
    printf("\n");
    postorder(p);
    // printf("\n");
    // inorder(p);
return 0;
}