#include<iostream>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        M[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at arr
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in arr
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // m is the point where the array is divided into two subarrays
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Merge the sorted subarrays
        merge(arr, left, mid, right);
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Display the menu
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Perform Merge Sort\n";
        cout << "2. Display Array\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                mergeSort(arr, 0, size - 1);
                cout << "Array sorted using Merge Sort.\n";
                break;
            case 2:
                cout << "Current Array: ";
                displayArray(arr, size);
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 3);

    return 0;
}

