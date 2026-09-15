#include <stdio.h>

int main() {
    int r, c, i, j;
    int a[100][100], b[100][100], sum[100][100];

    scanf("%d", &r);
    scanf("%d", &c);

    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            scanf("%d", &a[i][j]);

    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            scanf("%d", &b[i][j]);

    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            sum[i][j] = a[i][j] + b[i][j];

    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j)
            printf("%d ", sum[i][j]);
        printf("\n");
    }

    return 0;
}

