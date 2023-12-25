#include <iostream>

void merge(int arr1[], int size1, int arr2[], int size2, int mergedArr[]) {
    int i = 0, j = 0, k = 0;

    // Traverse both arrays and merge elements into the mergedArr
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1, if any
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2, if any
    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }
}

int main() {
    const int size1 = 5, size2 = 4;
    int arr1[size1] = {5, 2, 9, 1, 7};
    int arr2[size2] = {4, 8, 3, 6};

    int mergedSize = size1 + size2;
    int mergedArr[size1 + size2];

    // Merge the unsorted lists into a sorted list
    merge(arr1, size1, arr2, size2, mergedArr);

    // Output the sorted list
    std::cout << "Merged Sorted List:" << std::endl;
    for (int i = 0; i < mergedSize; ++i) {
        std::cout << mergedArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

