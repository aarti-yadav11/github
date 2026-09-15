#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int numbers[] = {12, 34, 10, 6, 40};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int key = 6;
    
    int index = linearSearch(numbers, size, key);
    
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}
