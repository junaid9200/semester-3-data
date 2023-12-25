#include <stdio.h>

void deleteKeyFromArray(int *arr, int *size, int key) {
    int newSize = 0; // Variable to store the new size of the array after deletion
    
    // Iterate through the array and remove occurrences of the key
    for (int i = 0; i < *size; i++) {
        if (arr[i] != key) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    // Update the size of the array after deletion
    *size = newSize;
}

int main() {
    int size = 10; // Size of the array
    int arr[] = {1, 2, 3, 4, 3, 6, 3, 8, 9, 3}; // Sample array
    int key = 3; // Key to be deleted
    
    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    deleteKeyFromArray(arr, &size, key); // Call the function to delete key from array
    
    printf("Array after deleting %d: ", key);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

