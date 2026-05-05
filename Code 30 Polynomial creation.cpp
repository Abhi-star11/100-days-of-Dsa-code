#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int c, int e) {
    struct Node* temp = createNode(c, e);

    if (head == NULL)
        return temp;

    struct Node* p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}

void display(struct Node* head) {
    struct Node* p = head;

    while (p != NULL) {
        if (p->exp == 0)
            printf("%d", p->coeff);
        else if (p->exp == 1)
            printf("%dx", p->coeff);
        else
            printf("%dx^%d", p->coeff, p->exp);

        if (p->next != NULL)
            printf(" + ");

        p = p->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, c, e;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        head = insertEnd(head, c, e);
    }

    printf("Polynomial:\n");
    display(head);

    return 0;
}
