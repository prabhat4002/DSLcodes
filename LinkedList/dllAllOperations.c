#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Declare the global head pointer
struct node* head = NULL;

// Function to create a new node
struct node* getnode(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// Function to insert a node at the beginning
void InsertAtHead(int x) {
    struct node* newnode = getnode(x);
    if (head == NULL) {
        head = newnode;
        return;
    }
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

// Function to insert a node at the end
void InsertAtEnd(int x) {
    struct node* newnode = getnode(x);
    if (head == NULL) {
        head = newnode;
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

// Function to insert a node at a specified position
void InsertAtNthPosition(int x, int position) {
    struct node* newnode = getnode(x);
    if (position == 1 || head == NULL) {
        newnode->next = head;
        if (head != NULL) {
            head->prev = newnode;
        }
        head = newnode;
        return;
    }
    struct node* temp = head;
    int current_position = 1;
    while (temp != NULL && current_position < position - 1) {
        temp = temp->next;
        current_position++;
    }
    if (temp == NULL) {
        printf("Position exceeds the length of the list. Insertion at the end.\n");
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    } else {
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
    }
}

// Function to delete a node at the beginning
void DeleteAtBeginning() {
    struct node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

// Function to delete a node at the end
void DeleteAtEnd() {
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Function to delete a node at a specified position
void DeleteAtNthPosition(int position) {
    if (position == 1) {
        struct node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }
    struct node* temp = head;
    int current_position = 1;
    while (temp != NULL && current_position < position) {
        temp = temp->next;
        current_position++;
    }
    if (temp == NULL) {
        printf("Position exceeds the length of the list. No deletion performed.\n");
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Function to search for a value in the list
int Search(int target) {
    struct node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == target) {
            return position; // Element found at this position
        }
        temp = temp->next;
        position++;
    }
    return -1; // Element not found in the list
}

// Function to sort the list using Bubble Sort
void BubbleSort() {
    if (head == NULL || head->next == NULL) {
        // The list is already sorted or empty.
        return;
    }
    int swapped;
    struct node* temp;
    struct node* last = NULL;
    while (1) {
        swapped = 0;
        temp = head;
        while (temp->next != last) {
            if (temp->data > temp->next->data) {
                // Swap the data of the two nodes.
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = 1;
            }
            temp = temp->next;
        }
        if (!swapped) {
            // If no swaps were made in this pass, the list is sorted.
            break;
        }
        last = temp;
    }
}

// Function to reverse print the list
void reversePrint() {
    struct node* temp = head;
    if (temp == NULL) {
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("REVERSE PRINT: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to print the list
void print() {
    struct node* temp = head;
    printf("LIST IS: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, x, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specified position\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at a specified position\n");
        printf("7. Search for a value\n");
        printf("8. Bubble Sort\n");
        printf("9. Print List\n");
        printf("10. Reverse Print List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &x);
                InsertAtHead(x);
                printf("Node inserted at the beginning\n");
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &x);
                InsertAtEnd(x);
                printf("Node inserted at the end\n");
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &x);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                InsertAtNthPosition(x, position);
                break;
            case 4:
                DeleteAtBeginning();
                printf("Node deleted from the beginning\n");
                break;
            case 5:
                DeleteAtEnd();
                printf("Node deleted from the end\n");
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                DeleteAtNthPosition(position);
                break;
            case 7:
                printf("Enter the value to search for: ");
                scanf("%d", &x);
                int result = Search(x);
                if (result != -1) {
                    printf("Value %d found at position %d\n", x, result);
                } else {
                    printf("Value %d not found in the list\n", x);
                }
                break;
            case 8:
                BubbleSort();
                printf("List sorted using Bubble Sort\n");
                break;
            case 9:
                print();
                break;
            case 10:
                reversePrint();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
