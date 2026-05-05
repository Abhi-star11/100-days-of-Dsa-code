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

// Get length of list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection point
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *p1 = head1, *p2 = head2;

    // Move pointer of longer list ahead
    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            p1 = p1->next;
    } else {
        for (int i = 0; i < diff; i++)
            p2 = p2->next;
    }

    // Traverse both together
    while (p1 != NULL && p2 != NULL) {
        if (p1 == p2)   // intersection by address
            return p1->data;

        p1 = p1->next;
        p2 = p2->next;
    }

    return -1; // No intersection
}

// Display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Main (interactive)
int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int n, m, x, intersectPos;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = insertEnd(list1, x);
    }

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);

    printf("Enter elements:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = insertEnd(list2, x);
    }

    // OPTIONAL: create intersection manually for testing
    printf("Enter position in first list where second list should intersect (0 for no intersection): ");
    scanf("%d", &intersectPos);

    if (intersectPos > 0) {
        struct Node* p1 = list1;
        for (int i = 1; i < intersectPos && p1 != NULL; i++)
            p1 = p1->next;

        struct Node* p2 = list2;
        while (p2->next != NULL)
            p2 = p2->next;

        if (p1 != NULL)
            p2->next = p1; // create intersection
    }

    int result = findIntersection(list1, list2);

    if (result == -1)
        printf("No Intersection\n");
    else
        printf("Intersection Point: %d\n", result);

    return 0;
}
