#include <stdio.h>
#define SIZE 10

typedef struct {
    int data[SIZE];       // Array to store data elements
    int next[SIZE];       // Array to store the index of the next element
    int head;             // Index of the head element
    int free;             // Index of the next free position
} ArrayLinkedList;

void initializeList(ArrayLinkedList* list) {
    list->head = -1; // -1 represents that the list is initially empty
    list->free = 0;  // Start with the first position free

    // Initialize the next array such that each element points to the next one
    for (int i = 0; i < SIZE - 1; i++) {
        list->next[i] = i + 1;
    }
    list->next[SIZE - 1] = -1; // Last position in 'next' is -1, indicating the end of free positions
}

int insert(ArrayLinkedList* list, int value) {
    if (list->free == -1) {
        printf("List is full!\n");
        return -1;
    }

    int new_index = list->free;       // Find a free position
    list->free = list->next[new_index]; // Update free position to the next available spot

    list->data[new_index] = value; // Insert value into data array
    list->next[new_index] = list->head; // Link new node to the current head
    list->head = new_index;       // Update head to new node index

    return new_index;
}

void delete(ArrayLinkedList* list, int index) {
    if (list->head == -1 || index < 0 || index >= SIZE) {
        printf("Invalid deletion!\n");
        return;
    }

    if (index == list->head) { // Deleting the head node
        list->head = list->next[index];
    } else { // Find the node before the node to delete
        int prev = list->head;
        while (prev != -1 && list->next[prev] != index) {
            prev = list->next[prev];
        }

        if (prev == -1) { // Index to delete was not found
            printf("Node not found!\n");
            return;
        }

        list->next[prev] = list->next[index];
    }

    // Add the deleted node back to free list
    list->next[index] = list->free;
    list->free = index;
}

void display(ArrayLinkedList* list) {
    int current = list->head;
    while (current != -1) {
        printf("%d -> ", list->data[current]);
        current = list->next[current];
    }
    printf("NULL\n");
}

int main() {
    ArrayLinkedList list;
    initializeList(&list);

    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);

    printf("Linked List after insertion: ");
    display(&list);

    delete(&list, list.head);
    printf("Linked List after deleting head: ");
    display(&list);

    return 0;
}
