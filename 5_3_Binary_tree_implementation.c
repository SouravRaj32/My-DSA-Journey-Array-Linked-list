#include <ctype.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *left, *right;
};
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
void display(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Display the current node's data
    printf("%d ", root->data);

    // Display the left subtree
    printf("(left: ");
    if (root->left == NULL)
    {
        printf("NULL");
    }
    else
    {
        display(root->left);
    }
    printf(") ");

    // Display the right subtree
    printf("(right: ");
    if (root->right == NULL)
    {
        printf("NULL");
    }
    else
    {
        display(root->right);
    }
    printf(") ");
}

void main()
{
    struct node *root;
    root = 0;
    root = create();
    printf("Binary Tree: ");
    display(root);
}