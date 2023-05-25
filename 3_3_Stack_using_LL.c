// push-O(n) have to traverse, so we push pop from beginning only to get O(1)
// pop-O(n)
#include <stdio.h>
#include <stdlib.h>




void push();
void display();
void pop();
void peek();
struct node
{
    int data;
    struct node *link;
}; struct node *top = 0;
int main(){
    push(2);
    push(3);
    push(10);
    display();
    peek();
    pop();
    peek();
    display();

}
void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}
void display()
{
    struct node *temp;
    temp = top;
    if (top == 0)
    {
        printf("Empty stack");
    }
    else
    {
        while (temp != 0)
        {
            printf("%d", temp->data);
            temp = temp->link;
        }
    }
}
void peek()
{
    if (top == 0)
    {
        printf("Empty stack");
    }
    else
    {
        printf("Top Element(Peek) is : %d\n", top->data);
    }
}
void pop(){
     struct node *temp;
     temp=top;
     if (top == 0)
    {
        printf("Empty stack");
    }
    else
    {
        printf("Top Element (Poped) : %d\t", top->data);
        top=top->link;
        free(temp);
    }
}