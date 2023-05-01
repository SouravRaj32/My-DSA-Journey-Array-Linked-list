
#include <stdio.h>
#include <stdlib.h>

// Function declaration
void del_from_beg();
void del_from_end();
void del_form_pos();
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
struct node *temp; // in ins at pos it is used to move at place of pos

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
    printf("Which operation do you want to perform ?\n press 1 ----> delete at the beginning\n press 2 ----> delete at the end\n press 3 ----> delete at specific position\n press 4 ---->To Display the doubly Linked list\n");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        del_from_beg();
        display();
        break;
    case 2:
        del_from_end();
        display();
        break;
    case 3:
        del_form_pos();
        display();
        break;

    case 4:
        display();
        break;
    }
    return 0;
}
void del_form_beg()
{

    if (head == 0)
    {
        printf("List is Empty");
    }
    else if (head == tail)
    {
        head = tail = 0;
        free(temp);
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = 0;
        free(temp);
    }
}
void del_from_end()
{
    struct node *temp;
    if (tail == 0)
    {
        printf("List is empty");
    }
    else if (head == tail)//to check if there is only one node in the list: 
    {
        head = tail = 0;
        free(temp);
    }
    else
    {
        temp = tail;
        tail->prev->next = 0; // dont write it for alternate method instead
        tail = tail->prev;    // this line then tail->next=0; in next line
        free(temp);
    }
}
void del_from_pos()
{
    int pos, i = 1;
    temp = head;
    printf("Enter Position: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        del_form_beg();
    }
    else
    {
        while (i < pos)
        {
            temp = temp->next; // to bring temp to its place
            i++;
        }
        if (temp->next == 0)//we will check whether the node you want to delete is last node or not by writing:
        {
            tail = tail->prev;
            tail->next = 0;
            free(temp);
        }
        else
        {
            temp->prev->next = temp->next; // establish link
            temp->next->prev = temp->prev; // establish link
            free(temp);
        }
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