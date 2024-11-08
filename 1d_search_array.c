#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50}; // Initialize an array with some elements
    int length = sizeof(arr) / sizeof(arr[0]); // Calculate the length of the array
    int element, position = -1;

    // Print the array
    printf("Array elements are:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input the element to be searched
    printf("Enter the element to be searched: ");
    scanf("%d", &element);

    // Search the element in the array
    for (int i = 0; i < length; i++) {
        if (arr[i] == element) {
            position = i;
            break;
        }
    }

    // Print the result
    if (position == -1) {
        printf("Element %d not found in the array.\n", element);
    } else {
        printf("Element %d found at position %d.\n", element, position);
    }

    return 0;
}
