#include <stdio.h>
#define MAX 10  // Define the maximum size of the linked list

int values[MAX];       // Array to store values of nodes
int next[MAX];         // Array to store indices of the next nodes
int head = -1;         // Start of the linked list (index of the first node)
int freeIndex = 0;     // Points to the first free index for new elements

// Initialize the `next` array for managing free space
void initializeFreeList() {
    for (int i = 0; i < MAX - 1; i++) {
        next[i] = i + 1;
    }
    next[MAX - 1] = -1;  // Last element points to -1
}

// Function to insert a value at the end of the linked list
void insert(int value) {
    if (freeIndex == -1) {
        printf("Linked List Overflow! No space left to insert %d.\n", value);
        return;
    }

    int newIndex = freeIndex;
    freeIndex = next[freeIndex];  // Update free index to the next free space

    values[newIndex] = value;  // Insert the value
    next[newIndex] = -1;  // New node points to -1 (end of list)
    if (head == -1) {
        head = newIndex;  // If list is empty, new node becomes the head
    } else {
        int temp = head;
        while (next[temp] != -1) {
            temp = next[temp];
        }
        next[temp] = newIndex;  // Link the last node to the new node
    }
    printf("Inserted %d at index %d.\n", value, newIndex);
}

// Function to delete the first occurrence of a value from the linked list
void delete(int value) {
    if (head == -1) {
        printf("Linked List Underflow! The list is empty.\n");
        return;
    }

    int temp = head, prev = -1;

    while (temp != -1 && values[temp] != value) {
        prev = temp;
        temp = next[temp];
    }

    if (temp == -1) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    if (temp == head) {
        head = next[head];
    } else {
        next[prev] = next[temp];
    }

    next[temp] = freeIndex;
    freeIndex = temp;

    printf("Deleted %d from index %d.\n", value, temp);
}

// Function to count the number of nodes in the linked list
int count() {
    int temp = head, count = 0;
    while (temp != -1) {
        count++;
        temp = next[temp];
    }
    return count;
}

// Function to delete the entire list
void deleteList() {
    while (head != -1) {
        int temp = head;
        head = next[head];
        next[temp] = freeIndex;
        freeIndex = temp;
    }
    printf("The linked list has been deleted.\n");
}

// Function to find the Nth node in the linked list
void findNthNode(int n) {
    int temp = head, index = 0;
    while (temp != -1 && index < n) {
        temp = next[temp];
        index++;
    }
    if (temp == -1) {
        printf("Node %d does not exist in the list.\n", n);
    } else {
        printf("The %dth node value is: %d\n", n, values[temp]);
    }
}

// Function to display the linked list
void display() {
    if (head == -1) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    int temp = head;
    while (temp != -1) {
        printf("%d ", values[temp]);
        temp = next[temp];
    }
    printf("\n");
}

// Main function
int main() {
    initializeFreeList();  // Initialize free list

    int choice, value, n;
    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Count\n");
        printf("5. Delete List\n");
        printf("6. Find Nth Node\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("The number of nodes in the list: %d\n", count());
                break;
            case 5:
                deleteList();
                break;
            case 6:
                printf("Enter the node number (0-based index): ");
                scanf("%d", &n);
                findNthNode(n);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
