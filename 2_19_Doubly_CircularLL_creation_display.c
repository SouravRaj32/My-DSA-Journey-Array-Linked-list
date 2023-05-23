#include <stdio.h>
#include <stdlib.h>

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
    int choice = 1;
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
    display();
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