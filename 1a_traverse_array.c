#include <stdio.h>

int main() {
    // Initialize an array with some elements
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);

    // Traverse the array and print each element
    printf("Array elements are:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
