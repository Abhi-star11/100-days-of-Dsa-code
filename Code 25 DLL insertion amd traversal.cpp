#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* temp = createNode(data);

    // If list is empty
    if (head == NULL)
        return temp;

    struct Node* p = head;

    // Traverse to last node
    while (p->next != NULL)
        p = p->next;

    // Link nodes
    p->next = temp;
    temp->prev = p;

    return head;
}

// Display forward
void display(struct Node* head) {
    struct Node* p = head;

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Main function (interactive)
int main() {
    struct Node* head = NULL;
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("Doubly Linked List (Forward Traversal):\n");
    display(head);

    return 0;
}
