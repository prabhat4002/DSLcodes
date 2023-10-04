#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


struct node* head = NULL;


void insert(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    
    if (head != NULL)
        temp->next = head;
    head = temp;
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    
    struct node* temp = head;
    head = head->next;
    free(temp);
}


void deleteEnd() {
    struct node* current = head;
    struct node* previous = NULL;

    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        // If there's only one node in the list
        head = NULL;
    } else {
        previous->next = NULL;
    }

    free(current);
}


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

void insertEnd(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

void delete(int n) {
    if (n <= 0) {
        printf("Invalid position. Cannot delete.\n");
        return;
    }

    if (n == 1) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct node* temp1 = head;
    for (int i = 0; i < n - 2; i++) {
        temp1 = temp1->next;
    }

    if (temp1 == NULL || temp1->next == NULL) {
        printf("Invalid position. Cannot delete.\n");
        return;
    }

    struct node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

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
