#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* temp = createNode(data);

    if (head == NULL) {
        temp->next = temp;
        return temp;
    }

    struct Node* p = head;

    while (p->next != head)
        p = p->next;

    p->next = temp;
    temp->next = head;

    return head;
}

void display(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* p = head;

    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
}

int main() {
    struct Node* head = NULL;
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("Circular Linked List:\n");
    display(head);

    return 0;
}
