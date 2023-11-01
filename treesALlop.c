#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to perform a pre-order traversal
void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to perform a post-order traversal
void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Function to perform an in-order traversal
void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to perform a recursive search
struct node* RecurSearch(struct node* root, int key) {
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;
    else if (root->data > key)
        return RecurSearch(root->left, key);
    else
        return RecurSearch(root->right, key);
}

// Function to perform an iterative search
struct node* ItSearch(struct node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// Function to insert a new element into the tree
void insert(struct node* root, int key) {
    struct node* prev = NULL;
    while (root != NULL) {
        prev = root;
        if (root->data == key) {
            printf("ROOT ALREADY EXIST!\n");
            return;
        } else if (root->data < key) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    struct node* new_node = createNode(key);
    if (prev->data > key) {
        prev->left = new_node;
    } else {
        prev->right = new_node;
    }
}

// Function to check if a tree is a Binary Search Tree (BST)
int isBST(struct node* root) {
    static struct node* prev = NULL;
    if (root != NULL) {
        if (!isBST(root->left))
            return 0;
        if (prev != NULL && root->data >= prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    } else {
        return 1;
    }
}

// Function to find the in-order predecessor
struct node* inOrderPredecessor(struct node* root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to delete a node from the tree
struct node* deleteNode(struct node* root, int key) {
    struct node* iPre;
    if (root == NULL) {
        return NULL;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int main() {
    struct node* root = NULL;
    int choice;
    int data, key;
    struct node* result;

    do {
        printf("\nBinary Tree Operations Menu:\n");
        printf("1. Create Tree\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Recursive Search\n");
        printf("6. Iterative Search\n");
        printf("7. Insert Element\n");
        printf("8. Delete Element\n");
        printf("9. Check if Tree is a Binary Search Tree (BST)\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create the tree
                root = createNode(4);
                root->left = createNode(1);
                root->right = createNode(6);
                root->left->left = createNode(5);
                root->left->right = createNode(2);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the key to search recursively: ");
                scanf("%d", &key);
                result = RecurSearch(root, key);
                if (result != NULL)
                    printf("Element found: %d\n", result->data);
                else
                    printf("Element not found\n");
                break;
            case 6:
                printf("Enter the key to search iteratively: ");
                scanf("%d", &key);
                result = ItSearch(root, key);
                if (result != NULL)
                    printf("Element found: %d\n", result->data);
                else
                    printf("Element not found\n");
                break;
            case 7:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(root, data);
                break;
            case 8:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 9:
                if (isBST(root))
                    printf("The tree is a Binary Search Tree (BST).\n");
                else
                    printf("The tree is not a BST.\n");
                break;
            case 10:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 10);

    return 0;
}
