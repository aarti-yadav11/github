#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Error: Columns of first matrix must equal rows of second matrix.\n");
        return 1;
    }

    int a[r1][c1];
    int b[r2][c2];
    int result[r1][c2];

    printf("\nEnter elements of matrix 1:\n");
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of matrix 2:\n");
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < c1; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nResultant Matrix:\n");
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
