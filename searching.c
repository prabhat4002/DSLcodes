#include <stdio.h>

int binaryIterative(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int binaryRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            return binaryRecursive(arr, mid + 1, right, target);
        } else {
            return binaryRecursive(arr, left, mid - 1, target);
        }
    }
    return -1;
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int linearRecursive(int arr[], int start, int end, int target) {
    if (start > end) {
        return -1;
    }
    if (arr[start] == target) {
        return start;
    }
    return linearRecursive(arr, start + 1, end, target);
}

int main() {
    int choice, target;
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose a searching technique:\n");
    printf("1. Binary Iterative\n");
    printf("2. Binary Recursive\n");
    printf("3. Linear Iterative\n");
    printf("4. Linear Recursive\n");
    printf("Enter your choice (1/2/3/4): ");
    scanf("%d", &choice);

    printf("Enter the target value: ");
    scanf("%d", &target);

    int result = -1;

    switch (choice) {
        case 1:
            result = binaryIterative(arr, size, target);
            break;
        case 2:
            result = binaryRecursive(arr, 0, size - 1, target);
            break;
        case 3:
            result = linearSearch(arr, size, target);
            break;
        case 4:
            result = linearRecursive(arr, 0, size - 1, target);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
