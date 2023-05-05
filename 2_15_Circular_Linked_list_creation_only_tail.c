//creation of circularLL maintaining tail and head pointer
#include <stdio.h>
#include <stdlib.h>

// void display();
// struct node
// {
//     int data;
//     struct node *next;
// };
// struct node *head, *newnode, *tail, *temp;

// int main()
// {
//     //creation of circularLL maintaining tail and head pointer
//     head = 0;
//     int choice = 1;
//     while (choice)
//     {
//         newnode = (struct node *)malloc(sizeof(struct node));
//         printf("Enter Data:\n");
//         scanf("%d", &newnode->data);
//         newnode->next = 0;
//         if (head == 0)
//         {
//             head = tail = newnode;
//         }
//         else
//         {
//             tail->next = newnode; // newnode value assigned to next of 1st node
//             tail = newnode;       // temp moved to 2nd node
//         }
//         tail->next = head; // only this line makes it CircularLL
//         printf("Do you want to Continue enter 0: No or 1: Yes ?");
//         scanf("%d", &choice);
//     }
//     printf("The value in 1st node is %d\n", tail->next->data); // this proves we have created a circularLL
//     display();
// }
// void display()
// {
//     if (head == 0)
//     {
//         printf("List is empty");
//     }
//     else
//     {
//         temp = head;
//         printf("Your Linked list is : \n");
//         while (temp->next != head) // here we cant use temp!=0 as we did in singlyLL
//         {
//             printf("%d ", temp->data);
//             temp = temp->next;
//         }
//         printf("%d", temp->data); // to print last node value
//     }
// }
//creation of circularLL maintaining only tail pointer

struct node
{
    int data;
    struct node *next;
};
struct node *newnode, *tail, *temp;
void display();
int main()
{
    //creation of circularLL maintaining only tail pointer
    tail=0;
    int choice = 1;
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
            newnode->next=tail->next; // here we dont have head to store its address in last node so we first take address of 1st node
            tail->next = newnode;  
            tail=newnode;     
        }
       
        printf("Do you want to Continue enter 0: No or 1: Yes ?");
        scanf("%d", &choice);
    }
    printf("The value in 1st node is %d\n", tail->next->data); // this proves we have created a circularLL
    display();
}
//traverse the list with only tail pointer
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