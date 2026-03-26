#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create_tree(int val)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void preorder(struct node *p)
{
    if (p != NULL)
    {
        printf("%d\n", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(struct node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d\n", p->data);
    }
}
void inorder(struct node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d\n", p->data);
        inorder(p->right);
    }
}
int search_tree_recur(struct node *p, int key)
{
    if (p == NULL)
        return 0;
    else if (p->data == key)
        return 1;
    else if (key > p->data)
        search_tree_recur(p->right, key);
    else
        search_tree_recur(p->left, key);
}
int search_tree_loop(struct node *p, int key)
{
    while(p != NULL){
        if (p->data == key)
        return 1;
        else if (key > p->data)
        p = p->right;
        else
        p = p->left;
    }
    return 0;
}
struct node* insert_node(struct node *p, int key)
{
    struct node *prev = NULL;
    struct node *ins;
    ins = create_tree(key);
    while(p != NULL)
    {
        prev = p;
        if(p->data < key)
        p = p->right;
        else if(p->data = key)
        {
            printf("value already exist can't be inserted.\n");
            return;
        }
        else 
        p = p->left;
    }
    if(prev->data < key)
    prev->right = ins;
    else
    prev->left = ins;
    printf("node inserted!\n");
    return p;
}
struct node* InOrderPred(struct node *p)
{
    p = p->left;
    while(p->right != NULL)
    {
        p = p->right;
    }
    return p;
}
struct node* delete_node(struct node *p, int key)
{
    if(p == NULL)
    {
        printf("NO BST exist!\n");
        return NULL;
    }
    else if(p->left == NULL && p->right == NULL)
    {
        return NULL;
    }
    struct node *ipre;
        if(p->data < key)
        p->right = delete_node(p->right,key);
        else if(p->data > key)
        p->left = delete_node(p->left,key);
        else
        {
            ipre = InOrderPred(p);
            p->data = ipre->data;
            p->left = delete_node(p->left,ipre->data);
        }
    return p;
}
int main()
{
    struct node *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10, *p11, *p;
    // p1 = create_tree(10);
    // p2 = create_tree(5);
    // p3 = create_tree(12);
    // p4 = create_tree(2);
    // p5 = create_tree(6);
    // p6 = create_tree(14);
    // p7 = create_tree(1);
    // p8 = create_tree(3);
    // p9 = create_tree(7);
    // p10 = create_tree(13);
    // p11 = create_tree(16);
    // p1->left = p2;
    // p1->right = p3;
    // p2->left = p4;
    // p2->right = p5;
    // p3->right = p6;
    // p4->left = p7;
    // p4->right = p8;
    // p5->right = p9;
    // p6->right = p11;
    // p6->left = p10;
    // preorder(p);
    // printf("\n");
    // postorder(p);
    // printf("%d", search_tree_recur(p, 15));
    // printf("%d", search_tree_loop(p, 5));
    struct node* root =create_tree(10);
    root = insert_node(root,12);
    root = insert_node(root,5);
    root = insert_node(root,1);
    inorder(root);
    // p = delete_node(p1,5);
    // printf("after deletion!\n");
    // inorder(p);
    return 0;
}