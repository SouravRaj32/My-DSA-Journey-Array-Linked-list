#include <stdio.h>
#include <stdlib.h>
void ins_at_beginning();
void ins_at_end();
void ins_at_pos();
void ins_after_pos();
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
struct node *temp; // in ins at pos it is used to move to just a place before pos

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
    printf("Which operation do you want to perform ?\n press 1 ----> insert at the beginning\n press 2 ----> insert at the end\n press 3 ----> insert at specific position\n press 4 ----> insert after a specific position\n press 5 ---->To Display the Linked list\n");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        ins_at_beginning();
        display();
        break;
    case 2:
        ins_at_end();
        display();
        break;
    case 3:
        ins_at_pos();
        display();
        break;
    case 4:
        ins_after_pos();
        display();
        break;
    case 5:
        display();
        break;
    }
    return 0;
}
void ins_at_beginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for insert at the beginning : \n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    head->prev = newnode; // establish link
    newnode->next = head; // establish link
    head = newnode;       // head point to newly added node
}
void ins_at_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for insert at the End : \n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    tail->next = newnode; // establish link
    newnode->prev = tail; // establish link
    tail = newnode;       // tail point to newly added node
}
void ins_at_pos()
{
    int pos, i = 1;
    temp = head;

    printf("Enter the position where you want to insert : \n");
    scanf("%d", &pos);
    if (pos == 1)
    {
        ins_at_beginning();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for insert at a position : \n");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;
        while (i < pos - 1)
        {
            temp = temp->next; // used to to desired place to perform operations
            i++;
        }
        newnode->prev = temp;       // establish link
        newnode->next = temp->next; // establish link
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}
void ins_after_pos()
{
    int pos, i = 1;
    temp = head;

    printf("Enter the position where you want to insert : \n");
    scanf("%d", &pos);

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for insert at a position : \n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    while (i < pos)
    {
        temp = temp->next; // used to to desired place to perform operations
        i++;
    }
    newnode->prev = temp;       // establish link
    newnode->next = temp->next; // establish link
    temp->next = newnode;
    if (newnode->next != 0) // not inserting at the end
    {
        newnode->next->prev = newnode;
    }
    else // inserting at the end
    {
        tail = newnode;
    }
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