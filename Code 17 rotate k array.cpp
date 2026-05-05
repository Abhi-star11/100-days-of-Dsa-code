#include <stdio.h>

int main() {
    int n, i, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n;

    int temp[k];

    for(i = 0; i < k; i++) {
        temp[i] = a[n - k + i];
    }

    for(i = n - 1; i >= k; i--) {
        a[i] = a[i - k];
    }

    for(i = 0; i < k; i++) {
        a[i] = temp[i];
    }

    printf("Rotated array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
