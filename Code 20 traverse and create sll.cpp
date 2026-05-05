#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    struct Node *head = NULL, *temp, *newNode;

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Element [%d]: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Linked List:\n");
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
