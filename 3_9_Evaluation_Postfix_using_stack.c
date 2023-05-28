#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
// int top = -1, stack [100];
// main ( ){
//    char a[50], ch;
//    int i,op1,op2,res,x;
//    void push (int);
//    int pop( );
//    int eval (char, int, int);
//    printf("enter a postfix expression:");
//    gets (a);
//    for(i=0; a[i]!='\0'; i++){
//       ch = a[i];
//       if (ch>='0' && ch<='9')
//          push('0');
//       else{
//          op2 = pop ( );
//          op1 = pop ( );
//          res = eval (ch, op1, op2);
//          push (res);
//       }
//    }
//    x = pop ( );
//    printf("evaluated value = %d", x);
//    getch ( );
// }
// void push (int n){
//    top++;
//    stack [top] = n;
// }
// int pop ( ){
//    int res ;
//    res = stack [top];
//    top--;
//    return res;
// }
// int eval (char ch, int op1, int op2){
//    switch (ch){
//       case '+' : return (op1+op2);
//       case '-' : return (op1-op2);
//       case '*' : return (op1*op2);
//       case '/' : return (op1/op2);
//    }
// }
void push(int);
int pop();
void display();

int s[25]={0};
int top=-1;
int ch;

void main(){
    //to input postfix char
    char postfix[25]={'\0'},ele;
    int i,num1,num2,ans;
    printf("Enter Postfix Exp:");
    scanf("%s", &postfix);
    printf("\n Postfix Expression: %s",postfix);
    i=0;
    while (i<=strlen(postfix)-1)
    {
        ele=postfix[i];
        if(isdigit(ele)){
            push(ele-'0');//to avoid pushing ASCII value such that if 0 then 48 -48 return 0 ultimately
        }
        else{
            num1=pop();
            num2=pop();
            switch (ele)
            {
            case '^':
                ans = pow(num2,num1);
                break;
            case '/':
                ans = num2/num1;
                break;
            case '*':
                ans = num2*num1;
                break;
            case '+':
                ans = num2+num1;
                break;
            case '-':
                ans = num2-num1;
                break;
            
            
            
            default:
                break;
            }
            push(ans);
        }
        display();
        i++;
    }
    printf("\n Answer =%d",pop());
    
}

void push(int ele){
    if(top==24){
        printf("\n Stack is full");
    }
    else{
        top++;
        s[top]=ele;
    }
}
int pop(){
    if(top==-1){
        printf("\n Stack is empty");
    }
    else{
        ch=s[top];
        top--;
    }
    return ch;
}
void display(){
    int i;
    printf("\n Stack is: ");
    for(i=0;i<=top;i++){
        printf("| %d",s[i]);
    }
}
//limitation 123^+ cant tell if its 1 and 2 or 12 works for only single number