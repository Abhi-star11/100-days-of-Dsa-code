#include <stdio.h>

int main() {
    int m, n;

    printf("Enter rows: ");
    scanf("%d", &m);

    printf("Enter columns: ");
    scanf("%d", &n);

    int matrix1[m][n], matrix2[m][n], sum[m][n];

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            printf("Enter element of matrix1: ");
            scanf("%d", &matrix1[i][j]);
        }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            printf("Enter element of matrix2: ");
            scanf("%d", &matrix2[i][j]);
        }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            sum[i][j] = matrix1[i][j] + matrix2[i][j];

    printf("Result matrix:\n");

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }

    return 0;
}
