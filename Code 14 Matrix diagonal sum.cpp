#include <stdio.h>

int main() {
    int m, n, i, j, sum = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int a[m][n];

    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < m && i < n; i++) {
        sum += a[i][i];
    }

    printf("Sum of primary diagonal = %d", sum);

    return 0;
}
