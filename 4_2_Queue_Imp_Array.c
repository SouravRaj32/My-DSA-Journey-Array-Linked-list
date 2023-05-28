#include <ctype.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#define N 5
int queue[N];

int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void display();
void peek();
 
void main()
{
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();
}

void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("Overflow: Queue is full");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("The dequeued Element is: %d\n", queue[front]);
        front++;
    }
}
void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("Empty Queue");
    }
    else
    {
        printf("Elements of Queue are:");
        for (i = front; i < rear + 1; i++)
        {
            printf(" %d\t", queue[i]);
        }
    }
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Empty Queue");
    }
    else
    {
        printf("Peek:%d\n", queue[front]);
    }
}