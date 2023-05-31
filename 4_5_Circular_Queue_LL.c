#include <ctype.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
// implement circular queue basically circular LL is used
// This LL should follow the property of circular queue prop 1: FIFO prop 2: enqueue dequeue ops should take 0(1)
// need to maintain tail to get O(1) in enqueue

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int x);
void dequeue();
void peek();
void display();

int main()
{
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    display();
    dequeue();
    peek();
    
    return 0;
}

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode; // establish link with new node
        rear = newnode;       // Moved rear to new node
        rear->next = front;   // Made it a circular linked list
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;

    if (front == NULL && rear == NULL)
    {
        printf("Empty Queue");
    }
    else if (front == rear)
    {
        front = rear = NULL;
        free(temp);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("Empty Queue");
    }
    else
    {
        printf("%d\n", front->data);
    }
}

void display()
{
    // cant move front so take temp
    struct node *temp;
    temp = front;

    if (front == NULL && rear == NULL)
    {
        printf("Empty Queue");
    }
    else
    {
        while (temp->next != front)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}