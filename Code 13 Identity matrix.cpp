#include <stdio.h>

int main() {
    int n, i, j, flag = 1;

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j && a[i][j] != 1)
                flag = 0;
            if(i != j && a[i][j] != 0)
                flag = 0;
        }
    }

    if(flag == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
