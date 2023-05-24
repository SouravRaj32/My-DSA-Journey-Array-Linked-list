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
    struct node *prev;
};
struct node *head, *tail, *newnode;


int main()
{
    
    head = 0;
    int choice = 1,a;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d", &newnode->data);
        if (head == 0)
        {
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
        printf("Do you want to Continue enter 0: No or 1: Yes ?");
        scanf("%d", &choice);
    }
    printf("Data in last node: %d\n", tail->next->data);
    printf("Data in first node: %d\n", head->prev->data);
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
void ins_at_beg(){
    
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data that is to be inserted at beginning:");
    scanf("%d", &newnode->data);
    if(head==0){
        head=tail=newnode;
        newnode->prev=tail;
        newnode->next=head;

    }
    else{
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=tail;
        tail->next=newnode;
        head=newnode;
    }
}
void ins_at_end(){
    
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data that is to be inserted at End:");
    scanf("%d", &newnode->data);
    if(head==0){
        head=tail=newnode;
        newnode->prev=tail;
        newnode->next=head;

    }
    else{
        newnode->prev=tail;
        tail->next=newnode;
        newnode->next=head;
        head->prev=newnode;
        tail=newnode;
    }
}
void ins_at_pos(){
    struct node *temp;
    int pos,l,i=1;
    temp=head;
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
        
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
    }
    
    
}
int getlength()
{
    struct node *temp1;
    int count = 0;
    temp1 = tail->next;
    if (tail == 0)
    {
        printf("empty list");
    }
    else
    {
        while (temp1->next != tail->next)
        {
            count++;
            temp1 = temp1->next;
        }
        printf("Length of Linked List is : %d\n", count);
    }
    return count;
}
void display(){
    struct node *temp;
    temp=head;
    if(head==0){
        printf("List is empty");
    }
    else{
        while (temp!=tail)
        {
            printf("%d\t",temp->data);
            temp=temp->next;

        }
        printf("%d",temp->data);
    }
}