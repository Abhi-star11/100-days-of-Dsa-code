#include <stdio.h>

int main() {
    int p, q;
    printf("Enter the size of first log: ");
    scanf("%d", &p);
    int a[p];
    for (int i = 0; i < p; i++) {
    	printf("Enter an element: ");
        scanf("%d", &a[i]);
    }
    printf("Enter the size of second log: ");
    scanf("%d", &q);
    int b[q];
    for (int i = 0; i < q; i++) {
    	printf("Enter an element: ");
        scanf("%d", &b[i]);
    }
    int i = 0, j = 0;
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }
    while (i < p) {
        printf("%d ", a[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}

