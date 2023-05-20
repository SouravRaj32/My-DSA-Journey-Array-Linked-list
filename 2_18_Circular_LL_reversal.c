#include <stdio.h>
#include <stdlib.h>

void reverse();
void display();

struct node
{
    int data;
    struct node *next;
};

struct node *tail;
struct node *newnode;
struct node *temp;

// main()
int main()
{
    int choice = 1;
    tail = 0;
    int a;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = 0;
        printf("Enter the data you want to insert : \n");
        scanf("%d", &newnode->data);

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

        printf("Do you want to continue (1 : Yes / 0 : No )? : ");
        scanf("%d", &choice);
    }

    printf("Which operation do you want to perform ?\n press 1 ----> To reverse the Linked List that you just entered \n press 2 ----> To Display the Linked list\n ");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        reverse();
        display();
        break;

    case 2:
        display();
        break;
    }
    return 0;
}

void reverse()
{
    struct node *prev, *current, *nextnode;
    current = tail->next;
    nextnode = current->next;
    if (tail == 0)
    {
        printf("Empty list");
    }
    else if (tail->next == tail)
    {
        display();
    }
    else
    {
        while (current != tail)
        {
            prev = current;
            current = nextnode; // extra line
            nextnode = current->next;
            current->next = prev;
        }
        nextnode->next = tail;
        tail = nextnode;
    }
}
// Printing the Linked list
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