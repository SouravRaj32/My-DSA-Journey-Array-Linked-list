#include <stdio.h>
#include <stdlib.h>

void display();
struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp;

int main()
{

    head = 0;
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data:\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode; // newnode value assigned to next of 1st node
            temp = newnode;       // temp moved to 2nd node
        }
        temp->next = head; // only this line makes it CircularLL
        printf("Do you want to Continue enter 0: No or 1: Yes ?");
        scanf("%d", &choice);
    }
    printf("The value in 1st node is %d\n", temp->next->data); // this proves we have created a circularLL
    display();
}
void display()
{
    if (head == 0)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;
        printf("Your Linked list is : \n");
        while (temp->next != head) // here we cant use temp!=0 as we did in singlyLL
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data); // to print last node value
    }
}