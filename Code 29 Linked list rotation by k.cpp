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

    if (head == NULL)
        return temp;

    struct Node* p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;

    int n = getLength(head);
    k = k % n;

    if (k == 0)
        return head;

    struct Node* p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = head;

    int steps = n - k;
    struct Node* newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, x, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    printf("Rotated Linked List:\n");
    display(head);

    return 0;
}
