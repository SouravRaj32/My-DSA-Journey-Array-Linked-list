#include <ctype.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create();
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);

void main()
{
    struct node *root;

    root = 0;
    root = create();
    printf("Preorder is : ");
    preorder(root);
    printf("Inorder is : ");
    inorder(root);
    printf("Postorder is : ");
    postorder(root);
}
struct node *create()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data (-1 for no Node): ");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter Left child of %d", x);
    newnode->left = create();
    printf("Enter Right child of %d", x);
    newnode->right = create();
    return newnode;
}
void preorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        printf("%d", root->data);
        preorder(root->left);
        postorder(root->right);
    }
}
void inorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}