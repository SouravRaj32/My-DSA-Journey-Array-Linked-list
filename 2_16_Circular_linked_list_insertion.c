// insertion maintaining tail pointer only
#include <stdio.h>
#include <stdlib.h>
void ins_at_beg();
void ins_at_end();
void ins_at_pos();
int getlength();
void display();

struct node
{
    int data;
    struct node *next;
};
struct node *newnode, *tail, *temp;

int main()
{
    // creation of circularLL maintaining only tail pointer
    tail = 0;
    int choice = 1;
    int a;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data:\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (tail == 0)
        {
            tail = newnode; // newnode value assigned to next of 1st node
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next; // here we dont have head to store its address in last node so we first take address of 1st node
            tail->next = newnode;
            tail = newnode;
        }

        printf("Do you want to Continue enter 0: No or 1: Yes ?");
        scanf("%d", &choice);
    }
    printf("The value in 1st node is %d\n", tail->next->data); // this proves we have created a circularLL
    printf("Which operation do you want to perform ?\n press 1 ----> insert at the beginning\n press 2 ----> insert at the end\n press 3 ----> insert at specific position\n press 4 ----> To Display the Linked list\n");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        ins_at_beg();
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
        display();
        break;
    }
    return 0;
}

void ins_at_beg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for insert at a position : \n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
    printf("The value in 1st node is %d\n", tail->next->data);
}
void ins_at_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for insert at a position : \n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
    printf("The value in 1st node is %d\n", tail->next->data);
}
void ins_at_pos()
{
    int pos, i = 1, l;
    printf("Enter the position where you want to insert : \n");
    scanf("%d", &pos);
    l = getlength();
    if (pos < 0 || pos > l)
    {
        printf("Invalid Position");
    }
    else if (pos == 1)
    {
        ins_at_beg();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for insert at a position : \n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        temp = tail->next;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

int getlength()
{
    int count = 0;
    temp = tail->next;
    if (tail == 0)
    {
        printf("empty list");
    }
    else
    {
        while (temp->next != tail->next)
        {
            count++;
            temp = temp->next;
        }
        printf("Length of Linked List is : %d\n", count);
    }
    return count;
}
// traverse the list with only tail pointer
void display()
{
    if (tail == 0)
    {
        printf("List is empty");
    }
    else
    {
        temp = tail->next;
        printf("Your Linked list is : \n");
        while (temp->next != tail->next)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data); // to print last node value
    }
}