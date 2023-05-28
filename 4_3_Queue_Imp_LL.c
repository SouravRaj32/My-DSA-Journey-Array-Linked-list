#include <ctype.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

void enqueue(int x);
void dequeue();
void display();
void peek();

struct node
{
    int data;
    struct node *next;
};

struct node *front;
struct node *rear;

void main()
{
    enqueue(5);
    enqueue(0);
    enqueue(-3);
    display();
    dequeue();
    peek();
}
void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if (front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void display()
{
    struct node *temp;
    if (front == 0 && rear == 0)
    {
        printf("Queue is Empty");
    }
    else
    {
        temp = front;
        while (temp != 0)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        
    }
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Dequed: %d\n", front->data);
        front = front->next;
        free(temp);
    }
}
void peek()
{
    if (front == 0 && rear == 0)
    {
        printf("Queue is Empty");
    }
    else{
        printf("Peek: %d",front->data);
    }
}