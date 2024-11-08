#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30, 40, 50}; // Initialize an array with some elements and size
    int length = 5; // Current length of the array
    int element, position;

    // Print the original array
    printf("Original array:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input the element to be inserted and its position
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    printf("Enter the position where the element should be inserted (0 to %d): ", length);
    scanf("%d", &position);

    // Validate the position
    if (position < 0 || position > length) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", length);
        return 1;
    }

    // Shift elements to the right to create space for the new element
    for (int i = length; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the specified position
    arr[position] = element;
    length++;

    // Print the array after insertion
    printf("Array after insertion:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
