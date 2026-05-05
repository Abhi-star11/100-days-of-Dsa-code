#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

int hashTable[TABLE_SIZE];

// Initialize hash table
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = EMPTY;
}

// Hash Function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Linear Probing - Insert
void insertLinear(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i) % TABLE_SIZE;

        if (hashTable[newIndex] == EMPTY || hashTable[newIndex] == DELETED) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
        i++;
    }

    printf("Hash Table is full! Cannot insert %d\n", key);
}

// Quadratic Probing - Insert
void insertQuadratic(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;

        if (hashTable[newIndex] == EMPTY || hashTable[newIndex] == DELETED) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
        i++;
    }

    printf("Hash Table is full! Cannot insert %d\n", key);
}

// Search
int search(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i) % TABLE_SIZE;

        if (hashTable[newIndex] == EMPTY)
            return -1;

        if (hashTable[newIndex] == key)
            return newIndex;

        i++;
    }

    return -1;
}

// Delete
void deleteKey(int key) {
    int index = search(key);

    if (index == -1) {
        printf("%d not found\n", key);
        return;
    }

    hashTable[index] = DELETED;
    printf("Deleted %d from index %d\n", key, index);
}

// Display
void display() {
    printf("\n--- Hash Table ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        if (hashTable[i] == EMPTY)
            printf("EMPTY");
        else if (hashTable[i] == DELETED)
            printf("DELETED");
        else
            printf("%d", hashTable[i]);
        printf("\n");
    }
}

int main() {
    int choice, key, method;

    initTable();

    printf("Choose probing method:\n");
    printf("1. Linear Probing\n");
    printf("2. Quadratic Probing\n");
    printf("Enter choice: ");
    scanf("%d", &method);

    while (1) {
        printf("\n--- Open Addressing Menu ---\n");
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
                if (method == 1)
                    insertLinear(key);
                else
                    insertQuadratic(key);
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
                deleteKey(key);
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
