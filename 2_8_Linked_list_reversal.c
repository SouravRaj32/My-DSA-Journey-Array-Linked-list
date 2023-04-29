#include <stdio.h>
#include <stdlib.h>

void reverse();
void display();


struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *newnode;
struct node *temp;


// main()
int main()
{
    int choice = 1;
    head = 0;
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
            temp = newnode;//
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



void reverse(){
    struct node *prevnode,*currentnode,*nextnode;
    prevnode=0;
    currentnode=nextnode=head;
    while(nextnode != 0){
        nextnode=nextnode->next;//before updating you update nextnode to next pos,when while loop run for 2nd time moves to next of next
        currentnode->next=prevnode;//break link store 0 , when while loop run for 2nd time it reverse linked list connection for 1st and 2nd node
        prevnode=currentnode;//prevnode point to 1st node now, when while loop run for 2nd time moved prevnode to 2nd node
        currentnode=nextnode;//move currentnode to next node , currentnode and next node both point to next node, when while loop run for 2nd time moved to next of next

    }
    head=prevnode;
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