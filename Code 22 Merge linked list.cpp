#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
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

// Merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

// Display list
void display(struct Node* head) {
    struct Node* p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Main function (interactive)
int main() {
    struct Node *list1 = NULL, *list2 = NULL, *merged = NULL;
    int n, m, x;

    // First list
    printf("Enter number of elements in first list: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = insertEnd(list1, x);
    }

    // Second list
    printf("Enter number of elements in second list: ");
    scanf("%d", &m);

    printf("Enter %d sorted elements:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = insertEnd(list2, x);
    }

    // Merge
    merged = mergeLists(list1, list2);

    // Output
    printf("Merged Linked List:\n");
    display(merged);

    return 0;
}
