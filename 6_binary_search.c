#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // To avoid overflow

        // Check if the target is at the mid index
        if (arr[mid] == target) {
            return mid;
        }
        // If target is smaller, search the left half
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        // If target is larger, search the right half
        else {
            low = mid + 1;
        }
    }

    // Return -1 if the target is not found
    return -1;
}

int main() {
    int n, target;

    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];  // Declare an array of size 'n'

    // Input the elements of the array (must be sorted)
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target value to search
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Call binary search function
    int result = binarySearch(arr, n, target);

    // Output the result
    if (result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
