#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30, 40, 50}; // Initialize an array with some elements and size
    int length = 5; // Current length of the array
    int position;

    // Print the original array
    printf("Original array:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input the position of the element to be deleted
    printf("Enter the position of the element to be deleted (0 to %d): ", length - 1);
    scanf("%d", &position);

    // Validate the position
    if (position < 0 || position >= length) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", length - 1);
        return 1;
    }

    // Shift elements to the left to fill the gap
    for (int i = position; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrease the length of the array
    length--;

    // Print the array after deletion
    printf("Array after deletion:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
