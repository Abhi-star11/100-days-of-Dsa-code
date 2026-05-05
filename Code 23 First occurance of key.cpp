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

// Delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;

    // Case 1: key is at head
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Traverse to find key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL) {
        printf("Key not found in list.\n");
        return head;
    }

    // Delete node
    prev->next = temp->next;
    free(temp);

    return head;
}

// Display list
void display(struct Node* head) {
    struct Node* p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Main (interactive)
int main() {
    struct Node* head = NULL;
    int n, x, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("Enter key to delete: ");
    scanf("%d", &key);

    head = deleteKey(head, key);

    printf("Linked List after deletion:\n");
    display(head);

    return 0;
}
