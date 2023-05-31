#include <ctype.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#define N 5
int deque[N];
int f = -1, r = -1;
void enqueuefront(int x);
void enqueuerear(int x);
void display();
void getfront();
void getrear();
void dequeuefront();
void dequeuerear();

void main()
{
    enqueuefront(2);
    enqueuefront(5);
    enqueuerear(-1);
    enqueuerear(0);
    enqueuefront(7);
    enqueuefront(4);
    display();
}
void enqueuefront(int x)
{
    if ((f == 0 && r == N - 1) || (f == r + 1))
    {
        printf("Queue is full\n");
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        deque[f] = x;
    }
    else if (f == 0)
    {
        f = N - 1;
        deque[f] = x;
    }
    else
    {
        f--;
        deque[f] = x;
    }
}
void enqueuerear(int x)
{
    if ((f == 0 && r == N - 1) || (f == r + 1))
    {
        printf("Queue is full");
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        deque[r] = x;
    }
    else if (r == N - 1)
    {
        r = 0;
        deque[r] = x;
    }
    else
    {
        r++;
        deque[r] = x;
    }
}
void display()
{
    // print data between f and r
    if (f == -1 && r == -1)
    {
        printf("Empty");
    }
    int i = f;
    while (i != r)
    {
        printf("%d\t", deque[i]);
        i = (i + 1) % N;
    }
    printf("%d", deque[r]);
}
void getfront()
{
    if (f == -1 && r == -1)
    {
        printf("Empty");
    }
    else
    {
        printf("%d", deque[f]);
    }
}
void getrear()
{
    if (f == -1 && r == -1)
    {
        printf("Empty");
    }
    else
    {
        printf("%d", deque[r]);
    }
}
void dequeuefront()
{
    if (f == -1 && r == -1)
    {
        printf("Empty");
    }
    else if (f == r)
    {
        f = r = -1;
    }
    else if (f == N - 1)
    {
        printf("%d", deque[f]);
        f=0;
    }
    else
    {
        printf("%d", deque[f]);
        f++;
    }
}
void dequeuerear()
{
    if (f == -1 && r == -1)
    {
        printf("Empty");
    }
    else if (f == r)
    {
        f = r = -1;
    }
    else if (r == 0)
    {
        printf("%d", deque[r]);
        r = N - 1;
    }
    else
    {
        printf("%d", deque[r]);
        r--;
    }
}