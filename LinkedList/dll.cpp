#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
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
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (*head == nullptr) {
            *head = newNode;
        } else {
            Node* temp = *head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void add_start(Node** head) {
    Node* newNode = new Node;
    cout << "Enter the value of the new node: ";
    cin >> newNode->data;
    newNode->prev = nullptr;

    if (*head == nullptr) {
        newNode->next = nullptr;
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void add_end(Node** head) {
    Node* newNode = new Node;
    cout << "Enter the value of the new node: ";
    cin >> newNode->data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        newNode->prev = nullptr;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
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
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (pos == 1) {
        newNode->next = *head;
        (*head)->prev = newNode;
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
    newNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void delete_start(Node** head) {
    if (*head == nullptr) {
        cout << "Empty List." << endl;
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    if (*head != nullptr) {
        (*head)->prev = nullptr;
    }
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
    Node* temp = nullptr;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) {
        *head = temp->prev;
    }
}

void concatenate(Node** head, Node** head2) {
    if (*head == nullptr) {
        *head = *head2;
        return;
    }

    if (*head2 != nullptr) {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = *head2;
        (*head2)->prev = temp;
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
        cout << "\nDoubly Linked List Operations:\n";
        cout << "1. Add at the beginning\n";
        cout << "2. Add at the end\n";
        cout << "3. Add at a specific position\n";
        cout << "4. Delete from the beginning\n";
        cout << "5. Delete from
