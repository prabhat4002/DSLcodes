#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void create(int number, Node** head) {
    if (number <= 0) {
        cout << "Invalid." << endl;
        return;
    }

    while (number--) {
        Node* newNode = new Node;
        cout << "Enter the value of new Node: ";
        cin >> newNode->data;
        newNode->next = nullptr;

        if (*head == nullptr) {
            *head = newNode;
        } else {
            Node* temp = *head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void add_start(Node** head) {
    Node* newNode = new Node;
    cout << "Enter the value of the new node: ";
    cin >> newNode->data;
    newNode->next = *head;
    *head = newNode;
}

void add_end(Node** head) {
    Node* newNode = new Node;
    cout << "Enter the value of the new node: ";
    cin >> newNode->data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void add_random(Node** head) {
    if (*head == nullptr) {
        cout << "Empty list." << endl;
        return;
    }

    cout << "Enter the position at which you want to add the new node: ";
    int pos;
    cin >> pos;

    if (pos <= 0) {
        cout << "Invalid position." << endl;
        return;
    }

    Node* newNode = new Node;
    cout << "Enter the value of the new node: ";
    cin >> newNode->data;
    newNode->next = nullptr;

    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int i;
    for (i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position." << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_start(Node** head) {
    if (*head == nullptr) {
        cout << "Empty List." << endl;
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

void delete_last(Node** head) {
    if (*head == nullptr) {
        cout << "Empty list." << endl;
        return;
    }

    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
        return;
    }

    Node* temp = *head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void reverse(Node** head) {
    if (*head == nullptr) {
        cout << "Empty list." << endl;
        return;
    }

    Node* current = *head;
    Node* prev = nullptr;
    Node* after = nullptr;
    while (current != nullptr) {
        after = current->next;
        current->next = prev;
        prev = current;
        current = after;
    }
    *head = prev;
}

void concatenate(Node** head, Node** head2) {
    if (*head == nullptr) {
        *head = *head2;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = *head2;
    }
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int len, size;
    cout << "Enter the size of the linked list: ";
    cin >> len;

    Node* head = nullptr;
    create(len, &head);

    int choice;
    while (true) {
        cout << "\nLinked List Operations:\n";
        cout << "1. Add at the beginning\n";
        cout << "2. Add at the end\n";
        cout << "3. Add at a specific position\n";
        cout << "4. Delete from the beginning\n";
        cout << "5. Delete from the end\n";
        cout << "6. Reverse the linked list\n";
        cout << "7. Concatenate with another linked list\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_start(&head);
                break;
            case 2:
                add_end(&head);
                break;
            case 3:
                add_random(&head);
                break;
            case 4:
                delete_start(&head);
                break;
            case 5:
                delete_last(&head);
                break;
            case 6:
                reverse(&head);
                break;
            case 7:
                cout << "Enter the size of the new linked list: ";
                cin >> size;

                Node* head2 = nullptr;
                create(size, &head2);
                concatenate(&head, &head2);
                break;
            case 8:
                display(head);
                break;
            case 9:
                exit(0);
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}
