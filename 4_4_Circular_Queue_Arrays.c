#include <ctype.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x);
void dequeue();
void display();
void peek();

void main()
{
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
}
void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % N == front)
    {
        printf("Queue is Full");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == 0 && rear == 0)
    {
        printf("Queue is Empty");
    }
    else if (front == rear)
    {
        // only one element after deletion queue became Empty
        // insertion - rear
        // deletion - front
        front = rear = -1;
    }
    else
    {
        printf("Dequeued: %d", queue[front]);
        front = (front + 1) % N;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Queue is:");
        while (i != rear)
        {
            printf("%d\t", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[rear]);
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