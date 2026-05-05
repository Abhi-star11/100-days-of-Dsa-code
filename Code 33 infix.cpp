#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop operation
char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

// Peek operation
char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}

// Function to return precedence
int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("Enter infix expression (single-character operands): ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        // If operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
