#include <stdio.h>

#define MAX 100
#define TABLE_SIZE 10

// Hash Table using Chaining (Linked List)
struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[TABLE_SIZE];

// Hash Function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Initialize hash table
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;
}

// Insert into hash table
void insert(int key) {
    int index = hashFunction(key);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    printf("Inserted %d at index %d\n", key, index);
}

// Search in hash table
int search(int key) {
    int index = hashFunction(key);

    struct Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->data == key)
            return index;
        temp = temp->next;
    }

    return -1;
}

// Delete from hash table
void delete(int key) {
    int index = hashFunction(key);

    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL)
                hashTable[index] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Deleted %d from index %d\n", key, index);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("%d not found in hash table\n", key);
}

// Display hash table
void display() {
    printf("\n--- Hash Table ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key;

    initTable();

    while (1) {
        printf("\n--- Hash Table Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int result = search(key);
                if (result != -1)
                    printf("%d found at index %d\n", key, result);
                else
                    printf("%d not found\n", key);
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
