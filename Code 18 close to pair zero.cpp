#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

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

    qsort(a, n, sizeof(int), cmp);

    int l = 0, r = n - 1;
    int min_sum = abs(a[l] + a[r]);
    int x = a[l], y = a[r];

    while(l < r) {
        int sum = a[l] + a[r];

        if(abs(sum) < min_sum) {
            min_sum = abs(sum);
            x = a[l];
            y = a[r];
        }

        if(sum < 0)
            l++;
        else
            r--;
    }

    printf("%d %d", x, y);

    return 0;
}
