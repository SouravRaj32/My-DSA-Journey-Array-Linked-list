#include <stdio.h>
#include <stdlib.h>

void getlength();
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
    

    printf("Which operation do you want to perform ?\n press 1 ----> To find Length of Linked List\n press 2 ----> To Display the Linked list\n ");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        getlength();
        display();
        break;
    
    case 2:
        display();
        break;
    }
    return 0;
}



void getlength(){
    int count=0;
    struct node *temp;
    temp=head;
    if(head==0){

    }
    else{
    while(temp!=0){
        count++;
        temp=temp->next;
    }
    printf("Length of Linked List is : %d\n",count);
    }
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