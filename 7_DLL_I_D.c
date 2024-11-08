#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct ListNode {
    int data;
    struct ListNode *next;
    struct ListNode *prev;
};

// Function to insert a new node at the beginning of the list
struct ListNode* insertAtHead(struct ListNode *head, int data) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    return head;
}

// Function to insert a new node at the end of the list
struct ListNode* insertAtEnd(struct ListNode *head, int data) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }
    struct ListNode *current = head;

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        return newNode; // New node becomes the head if the list is empty
    }

    // Traverse to the end of the list
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;

    return head;
}

// Function to insert a new node after a given position
struct ListNode* insertAfter(struct ListNode *head, int position, int data) {
    if (position < 0) {
        printf("Invalid position.\n");
        return head;
    }

    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }
    struct ListNode *current = head;
    int i;

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    // Traverse to the position
    for (i = 0; current != NULL && i < position; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position %d is out of bounds.\n", position);
        free(newNode);
        return head;
    }

    // Insert the new node after the current node
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    return head;
}

// Function to delete the node at the beginning of the list
struct ListNode* deleteAtHead(struct ListNode *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    struct ListNode *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);

    return head;
}

// Function to delete the node at the end of the list
struct ListNode* deleteAtEnd(struct ListNode *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    struct ListNode *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        head = NULL; // The list had only one node
    }
    free(current);

    return head;
}

// Function to delete the node at a given position
struct ListNode* deleteAtPosition(struct ListNode *head, int position) {
    if (position < 0 || head == NULL) {
        printf("Invalid position or empty list.\n");
        return head;
    }

    struct ListNode *current = head;
    int i;

    // Traverse to the position
    for (i = 0; current != NULL && i < position; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position %d is out of bounds.\n", position);
        return head;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next; // Deleting the head node
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);

    return head;
}

// Function to print all elements in the list
void printList(struct ListNode *head) {
    struct ListNode *current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the doubly linked list
void freeList(struct ListNode *head) {
    struct ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct ListNode *head = NULL;
    int data, position, choice;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at a position\n");
        printf("7. Print list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtHead(head, data);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter the position to insert after: ");
                scanf("%d", &position);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = insertAfter(head, position, data);
                break;
            case 4:
                head = deleteAtHead(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 7:
                printf("Current list: ");
                printList(head);
                break;
            case 8:
                freeList(head);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
