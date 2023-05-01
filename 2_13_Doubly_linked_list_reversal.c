#include <stdio.h>
#include <stdlib.h>

void reverse_dll();
void display();

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;
struct node *newnode;
struct node *tail;


int main()
{
    // creating of DLL while maintaining tail pointer
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
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode; // establish link
            newnode->prev = tail; // establish link
            tail = newnode;       // move temp to 2nd node
        }

        printf("Do you want to continue (1 : Yes / 0 : No )? : ");
        scanf("%d", &choice);
    }
    printf("Which operation do you want to perform ?\n press 1 ----> To reverse the doubly Linked List that you just entered \n press 2 ----> To Display the doubly Linked list\n ");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        reverse_dll();
        display();
        break;

    case 2:
        display();
        break;
    }
    return 0;
}
void reverse_dll()
{
    struct node *current, *nextnode;
    if (head == 0)
    {
        printf("List is empty");
    }
    else
    {
        current = head;
        while (current != 0)
        {
            nextnode = current->next;      // next value of 1st node stored in nextnode
            current->next = current->prev; // swapping of values in 1st node begins
            current->prev = nextnode;      // swapping for prev value in 1st node
            current = nextnode;            // swapping for 1st node done current moved to 2nd node where nextnode is also pointing
        }
        current=head;
        head=tail;
        tail=current;
    }
}
// Printing the Linked list
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