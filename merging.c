#include <stdio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i, j;
    for (i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    for (j = 0; j < size2; j++) {
        merged[size1 + j] = arr2[j];
    }
}

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int size1 = 3;
    int size2 = 3;
    int merged[6];

    mergeArrays(arr1, size1, arr2, size2, merged);

    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    
    return 0;
}
