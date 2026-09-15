#include <stdio.h>

void traverse(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert(int arr[], int size, int capacity, int element, int pos) {
    if (size >= capacity || pos < 0 || pos > size) {
        return size;
    }
    for (int i = size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = element;
    return size + 1;
}

int delete(int arr[], int size, int pos) {
    if (pos < 0 || pos >= size) {
        return size;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

int main() {
    int capacity = 10;
    int arr[10] = {1, 2, 4, 5};
    int size = 4;

    printf("Initial array: ");
    traverse(arr, size);

    size = insert(arr, size, capacity, 3, 2);
    printf("After insertion: ");
    traverse(arr, size);

    size = delete(arr, size, 1);
    printf("After deletion: ");
    traverse(arr, size);

    return 0;
}
