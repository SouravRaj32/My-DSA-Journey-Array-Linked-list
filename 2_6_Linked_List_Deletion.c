// code for single linked list
#include <stdio.h>
#include <stdlib.h>

// Function declaration
void del_from_beg();
void del_at_end();
void del_form_pos(int);
void display();

struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *newnode;
struct node *temp;

;

// main()
int main()
{
    int choice = 1;
    head = 0;
    int count;
    int a;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = 0;
        printf("Enter the data you want to insert : \n");
        scanf("%d", &newnode->data);

        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode; //
        }

        printf("Do you want to continue (1 : Yes / 0 : No )? : ");
        scanf("%d", &choice);
    }
    temp = head;
    while (temp->next != 0) // temp!=0 may be wrong
    {
        temp = temp->next;
        count++; //-----> can be printed as length of the linked list
    }

    printf("Which operation do you want to perform ?\n press 1 ----> del from the beginning\n press 2 ----> del from the end\n press 3 ----> delete at specific position\n press 4 ----> To Display the Linked list\n");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        del_from_beg();
        display();
        break;
    case 2:
        del_at_end();
        display();
        break;
    case 3:
        del_form_pos(count);
        display();
        break;
    case 4:
        display();
        break;
    }
    return 0;
}
void del_from_beg()
{
    if (head->next == 0)
    {
        head = 0;
        free(temp);
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void del_at_end()
{
    struct node *prevnode;
    temp = head;
    while (temp->next != 0) // to move temp and prevnode to their respective position
    {
        prevnode = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = 0;
    }
    else
    {
        prevnode->next = 0;
    }
    free(temp);
}
void del_form_pos(int count)
{
    struct node *nextnode;
    int pos, i = 1;
    temp = head;
    printf("Enter Position: ");
    scanf("%d", &pos);
    while (i < pos - 1)
    {
        temp = temp->next; // to bring temp to its place
        i++;
    }
    nextnode = temp->next; // to bring nextnode to its place
    temp->next = nextnode->next;
    free(nextnode);
    
}
// Printing the Linked list
void display()
{
    temp = head;
    printf("Your Linked list is : \n");
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}