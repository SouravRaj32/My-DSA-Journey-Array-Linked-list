#include <stdio.h>
#include <stdlib.h>


#define N 5
int stack[N];
int top = -1;

void push();
void display();
void pop();
void peek();

int main()
{
    int ch = 1, a;
    while (ch)
    {
        printf("Which operation do you want to perform ?\n press 1 ----> Push\n press 2 ----> Pop\n press 3 ----> Peek\n press 4 ----> To Display the Stack\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            peek();
            display();
            break;
        case 4:
            display();
            break;
        default:
            printf("Invalid Choice");
        }
        printf("Do you want to Continue enter 0: No or 1: Yes ?");
        scanf("%d", &ch);
    }
    return 0;
}
void push()
{
    int x;
    printf("Enter the Data in Stack: ");
    scanf("%d", &x);
    if (top == N - 1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    int item;
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {
        item = stack[top];
        top--;
        printf("This item has been poped:%d\t", item);
    }
}
void peek()
{
    if (top == -1)
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("Element at top is:%d\t", stack[top]);
    }
}
void display()
{
    int i;
    printf("Elements in Stack are:");
    for (i = top; i >= 0; i--)
    {
        printf("%d\t ", stack[i]);
    }
}