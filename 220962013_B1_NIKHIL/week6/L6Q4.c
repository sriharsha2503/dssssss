#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

struct Stack {
    char data[MAX_SIZE];
    int top;
};

void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char* postfixToPrefix(char* postfix) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    
    int length = strlen(postfix);
    char* prefix = (char*)malloc((length + 1) * sizeof(char));
    
    int i, j = 0;
    for (i = 0; i < length; i++) {
        if (isOperator(postfix[i])) {
            char operand2 = pop(stack);
            char operand1 = pop(stack);
            
            prefix[j++] = postfix[i];
            prefix[j++] = operand1;
            prefix[j++] = operand2;
            
            push(stack, postfix[i]);
        } else {
            push(stack, postfix[i]);
        }
    }
    
    prefix[j] = '\0';
    return prefix;
}

int main() {
    char postfix[MAX_SIZE];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    
    char* prefix = postfixToPrefix(postfix);
    
    printf("Prefix expression: %s\n", prefix);
    
    free(prefix);
    
    return 0;
}
