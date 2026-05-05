#include <stdio.h>
#include <stdlib.h>
/* node structure */
struct Node {
    int data;
    struct Node *next;
};
/* create a new node */
struct Node* newNode(int val) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}
/* count nodes in the list */
int countNodes(struct Node *head) {
    int count = 0;
    struct Node *cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}
int main() {
    int n;
    scanf("%d", &n);
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node *node = newNode(val);
        if (head == NULL) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    /* traverse and print */
    struct Node *cur = head;
    while (cur != NULL) {
        if (cur != head) printf(" ");
        printf("%d", cur->data);
        cur = cur->next;
    }
    printf("\n");
    return 0;
}
