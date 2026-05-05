#include <stdio.h>

int main() {
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &a[i]);
    }

    int max = a[0], min = a[0];

    for(i = 1; i < n; i++) {
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];
    }

    printf("Max: %d\n", max);
    printf("Min: %d", min);

    return 0;
}
