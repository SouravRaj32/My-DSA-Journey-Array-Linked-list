#include <stdio.h>
#include <stdlib.h>
//creation of DLL without maintaining tail pointer
void display();

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;
struct node *newnode;
struct node *temp;

int main()
{
    head = 0;
    int choice = 1;
    int a;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = 0;
        printf("Enter the data you want to insert : \n");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;

        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode; // establish link
            newnode->prev = temp; // establish link
            temp = newnode;       // move temp to 2nd node
        }

        printf("Do you want to continue (1 : Yes / 0 : No )? : ");
        scanf("%d", &choice);
    }
    display();
}
void display()
{
    struct node *temp;
    temp = head;
    printf("Your doubly Linked list is : \n");
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}