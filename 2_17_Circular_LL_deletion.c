#include <stdio.h>
#include <stdlib.h>

void del_from_beg();
void del_from_end();
void del_from_pos();
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
    printf("Which operation do you want to perform ?\n press 1 ----> delete at the beginning\n press 2 ----> delete at the end\n press 3 ----> delete at specific position\n press 4 ----> To Display the Linked list\n");
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
        del_from_pos();
        display();
        break;
    case 4:
        display();
        break;
    }
    return 0;
}
void del_from_beg(){
    temp=tail->next;
    if(tail==0){
        printf("List is empty");
    }
    else if(temp->next==temp){
        tail=0;
        free(temp);

    }
    else{
        tail->next=temp->next;
        free(temp);
    }
}
void del_from_end(){
    struct node *current, *previous;
    current=tail->next;
    if(tail==0){
        printf("List is empty");
    }
    else if(current->next != tail->next){
        while (current->next!=tail->next)
        {
            previous=current;
            current=current->next;
        }
        previous->next=tail->next;
        tail=previous;
        free(current);
        
    }
}
void del_from_pos(){
    struct node *current, *nextnode;
    int pos, i=1, l;
    current=tail->next;
    printf("Enter the position where you want to insert : \n");
    scanf("%d", &pos);
    l=getlength();
    if (pos < 0 || pos > l)
    {
        printf("Invalid Position");
    }
    else if (pos == 1)
    {
        del_from_beg();
    }
    else{
        while (i<pos-1)
        {
            current=current->next;
            i++;
        }
        nextnode=current->next;
        current->next=nextnode->next;
        free(nextnode);
        
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