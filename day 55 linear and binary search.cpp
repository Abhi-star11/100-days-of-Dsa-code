#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search (Iterative)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Binary Search (Recursive)
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
}

// Bubble sort for preparing binary search input
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Linear Search
    result = linearSearch(arr, n, key);
    if (result != -1)
        printf("\nLinear Search: %d found at index %d\n", key, result);
    else
        printf("\nLinear Search: %d not found\n", key);

    // Sort for binary search
    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Binary Search (Iterative)
    result = binarySearch(arr, n, key);
    if (result != -1)
        printf("Binary Search (Iterative): %d found at index %d\n", key, result);
    else
        printf("Binary Search (Iterative): %d not found\n", key);

    // Binary Search (Recursive)
    result = binarySearchRecursive(arr, 0, n - 1, key);
    if (result != -1)
        printf("Binary Search (Recursive): %d found at index %d\n", key, result);
    else
        printf("Binary Search (Recursive): %d not found\n", key);

    return 0;
}
