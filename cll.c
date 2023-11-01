#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node* next;
};

// Declare the global head pointer
struct node* head = NULL;

// Function to insert a node at the beginning
void insert(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    
    if (head == NULL) {
        temp->next = temp; // Point to itself to create a circular link
        head = temp;
    } else {
        struct node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        temp->next = head; // Make the new node point to the head
        last->next = temp; // Make the last node point to the new node
        head = temp; // Update the head to the new node
    }
}

// Function to delete a node at the beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    
    struct node* temp = head;
    if (temp->next == head) {
        head = NULL; // If there's only one node, set head to NULL
    } else {
        struct node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next; // Move the head to the next node
        last->next = head; // Update the last node's next pointer
    }
    free(temp);
}

// Function to delete a node at the end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    
    struct node* current = head;
    struct node* previous = NULL;

    if (current->next == head) {
        head = NULL; // If there's only one node, set head to NULL
    } else {
        while (current->next != head) {
            previous = current;
            current = current->next;
        }

        if (previous == NULL) {
            // If there are more than one node in the list
            head = head->next;
        } else {
            previous->next = head;
        }
    }

    free(current);
}

// Function to search for a value in the list
int search(int target) {
    struct node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == target) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

// Function to sort the list using Bubble Sort
void bubbleSort() {
    int swapped;
    struct node* ptr1;
    struct node* lptr = NULL;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to reverse the list
void reverseList() {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
}

// Function to insert a node at a specified position
void insertAtPos(int data, int n) {
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = data;
    temp1->next = NULL;

    if (n == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }

    struct node* temp2 = head;
    for (int i = 0; i < n - 2; i++) {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

// Function to insert a node at the end
void insertEnd(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    
    if (head == NULL) {
        temp->next = temp; // Point to itself to create a circular link
        head = temp;
    } else {
        struct node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        temp->next = head; // Make the new node point to the head
        last->next = temp; // Make the last node point to the new node
    }
}

// Function to delete a node at a specified position
void delete(int n) {
    if (n <= 0) {
        printf("Invalid position. Cannot delete.\n");
        return;
    }

    if (n == 1) {
        struct node* temp = head;
        if (temp->next == head) {
            head = NULL; // If there's only one node, set head to NULL
        } else {
            struct node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next; // Move the head to the next node
            last->next = head; // Update the last node's next pointer
        }
        free(temp);
        return;
    }

    struct node* temp1 = head;
    for (int i = 0; i < n - 2; i++) {
        temp1 = temp1->next;
    }

    if (temp1 == NULL || temp1->next == head) {
        printf("Invalid position. Cannot delete.\n");
        return;
    }

    struct node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

// Function to print the circular list
void print() {
    struct node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("LIST IS: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int main() {
    int choice, x, n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Delete at the beginning\n");
        printf("3. Delete at the end\n");
        printf("4. Search for a value\n");
        printf("5. Bubble Sort\n");
        printf("6. Reverse List\n");
        printf("7. Insert at a specified position\n");
        printf("8. Insert at the end\n");
        printf("9. Delete at a specified position\n");
        printf("10. Print List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Taking input from the user for the number of nodes and their data
                printf("Enter the number of nodes to create: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter the data for node %d: ", i + 1);
                    scanf("%d", &x);
                    insert(x);
                }
                printf("Nodes inserted at the beginning\n");
                break;
            case 2:
                deleteBeginning();
                printf("Node deleted from the beginning\n");
                break;
            case 3:
                deleteEnd();
                printf("Node deleted from the end\n");
                break;
            case 4:
                printf("Enter the value to search for: ");
                scanf("%d", &x);
                int position = search(x);
                if (position != -1) {
                    printf("Value %d found at position %d\n", x, position);
                } else {
                    printf("Value %d not found in the list\n", x);
                }
                break;
            case 5:
                bubbleSort();
                printf("List sorted using Bubble Sort\n");
                break;
            case 6:
                reverseList();
                printf("List reversed\n");
                break;
            case 7:
                printf("Enter the position to insert at: ");
                scanf("%d", &n);
                printf("Enter the data to insert: ");
                scanf("%d", &x);
                insertAtPos(x, n);
                printf("Node inserted at position %d\n", n);
                break;
            case 8:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &x);
                insertEnd(x);
                printf("Node inserted at the end\n");
                break;
            case 9:
                printf("Enter the position to delete: ");
                scanf("%d", &n);
                delete(n);
                printf("Node deleted from position %d\n", n);
                break;
            case 10:
                print();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}