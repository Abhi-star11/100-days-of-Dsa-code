#include <stdio.h>

#define MAX 100

struct Element {
    int data;
    int priority;
};

struct Element queue[MAX];
int size = 0;

// Insert element
void enqueue(int data, int priority) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    queue[size].data = data;
    queue[size].priority = priority;
    size++;

    printf("Element inserted successfully!\n");
}

// Delete highest priority element
void dequeue() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return;
    }

    int highest = 0;

    // Find highest priority
    for (int i = 1; i < size; i++) {
        if (queue[i].priority > queue[highest].priority) {
            highest = i;
        }
    }

    printf("Deleted element: %d (Priority: %d)\n",
           queue[highest].data, queue[highest].priority);

    // Shift elements
    for (int i = highest; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }

    size--;
}

// Display queue
void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("\nElements in Priority Queue:\n");
    for (int i = 0; i < size; i++) {
        printf("Value: %d | Priority: %d\n",
               queue[i].data, queue[i].priority);
    }
}

int main() {
    int choice, data, priority;

    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue Highest Priority)\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
