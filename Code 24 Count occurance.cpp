#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
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

// Count occurrences of key
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* p = head;

    while (p != NULL) {
        if (p->data == key)
            count++;
        p = p->next;
    }

    return count;
}

// Main function (interactive)
int main() {
    struct Node* head = NULL;
    int n, x, key, result;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("Enter element to count: ");
    scanf("%d", &key);

    result = countOccurrences(head, key);

    printf("Number of occurrences of %d = %d\n", key, result);

    return 0;
}
