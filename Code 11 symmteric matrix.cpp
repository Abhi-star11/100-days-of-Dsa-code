#include <stdio.h>

int main() {
    int m, n;

    printf("Enter rows: ");
    scanf("%d", &m);

    printf("Enter columns: ");
    scanf("%d", &n);

    int matrix[100][100];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Enter element: ");
            scanf("%d", &matrix[i][j]);
        }
    }

    if(m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix");

    return 0;
}
