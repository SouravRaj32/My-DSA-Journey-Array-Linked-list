#include <ctype.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#define N 5

int s1[N], s2[N];
int top1 = -1, top2 = -1;

int count = 0;

void push1(int data);
void push2(int data);
int pop1();
int pop2();
void enqueue(int x);
void dequeue();
void display();

void main()
{
    enqueue(5);
    enqueue(2);
    enqueue(-1);
    dequeue();

    enqueue(7);
    display();
}
void push1(int data)
{
    if (top1 == N - 1)
    {
        printf("Queue is full");
    }
    else
    {
        top1++;
        s1[top1] = data;
    }
}
void push2(int data)
{
    if (top2 == N - 1)
    {
        printf("Queue is full");
    }
    else
    {
        top2++;
        s2[top2] = data;
    }
}
int pop1()
{
    return s1[top1--];
}
int pop2()
{
    return s2[top2--];
}
void enqueue(int x)
{
    push1(x);
    count++;
}

void dequeue()
{
    int i, a, b;
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            a = pop1();
            push2(a);
        }
        b = pop2();
        printf("Dequeued: %d", b);
        count--;
        for (i = 0; i < count; i++)
        {
            a = pop2();
            push1(a);
        }
    }
}
void display()
{
    int i;
    printf("\nQueue contains: ");
    for (i = 0; i <= top1; i++)
    {
        printf("%d\t", s1[i]);
    }
}