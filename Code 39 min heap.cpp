#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert
void insert(int value) {
    if (size == MAX) {
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = value;
    heapifyUp(size);
    size++;

    printf("Inserted successfully\n");
}

// Delete Min
void deleteMin() {
    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted Min: %d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

// Display
void display() {
    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Min Heap Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete Min\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteMin();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
