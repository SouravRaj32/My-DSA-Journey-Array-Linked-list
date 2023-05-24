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
    printf("Which operation do you want to perform ?\n press 1 ----> Delete from the beginning\n press 2 ----> Delete from the end\n press 3 ----> Delete from specific position\n press 4 ----> To Display the Linked list\n");
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
    struct node *temp;
    temp=head;
    if(head==0){
        printf("List is empty");
    }
    else if(head->next==head){
        head=tail=0;
        free(temp);

    }
    else{
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
        
    }
}
void del_from_end(){
    struct node *temp;
    temp=tail;
    if(head==0){
        printf("List is empty");
    }
    else if(head->next==head){
        head=tail=0;
        free(temp);

    }
    else{
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        
        free(temp);

    }
}
void del_from_pos()
{
    struct node *temp;
    temp = head;
    int pos, l, i = 1;

    printf("Enter the position where you want to delete: ");
    scanf("%d", &pos);
    l = getlength();
    if (pos < 1 || pos > l)
    {
        printf("Invalid Position\n");
    }
    else if (pos == 1)
    {
        del_from_beg();
    }
   
    else
    {
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        if (temp->next == head)
        {
            tail = temp->prev;
            free(temp);
        }
        else
        {
            free(temp);
        }
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