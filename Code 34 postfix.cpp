#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main() {
    char postfix[MAX];

    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        // If operand (digit)
        if (isdigit(ch)) {
            push(ch - '0');  // convert char to int
        }
        // If operator
        else {
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                default: 
                    printf("Invalid operator\n");
                    return 1;
            }
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}
