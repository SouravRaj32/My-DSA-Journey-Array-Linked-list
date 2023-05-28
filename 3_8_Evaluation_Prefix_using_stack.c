#include <ctype.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

struct Stack {
    double data;
    struct Stack* next;
};

typedef struct Stack Stack;

Stack* createNode(double value) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(Stack** top, double value) {
    Stack* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}

double pop(Stack** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }

    Stack* temp = *top;
    double value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

double evaluatePrefix(char* prefixExp) {
    Stack* operandStack = NULL;
    int size = strlen(prefixExp);

    for (int i = size - 1; i >= 0; i--) {
        if (isdigit(prefixExp[i])) {
            push(&operandStack, prefixExp[i] - '0');
        } else {
            double o1 = pop(&operandStack);
            double o2 = pop(&operandStack);

            if (prefixExp[i] == '+')
                push(&operandStack, o1 + o2);
            else if (prefixExp[i] == '-')
                push(&operandStack, o1 - o2);
            else if (prefixExp[i] == '*')
                push(&operandStack, o1 * o2);
            else if (prefixExp[i] == '/') {
                if (o2 != 0)
                    push(&operandStack, o1 / o2);
                else {
                    printf("Invalid Expression: Division by zero\n");
                    return -1;
                }
            } else {
                printf("Invalid Expression\n");
                return -1;
            }
        }
    }

    return pop(&operandStack);
}

int main() {
    char prefixExp[] = "*+69-31";
    printf("The result of evaluation of expression %s is %.2f\n", prefixExp, evaluatePrefix(prefixExp));
    return 0;
}
