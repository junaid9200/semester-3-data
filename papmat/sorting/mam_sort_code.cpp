#include<iostream>
using namespace std;

void swapValues(int *x, int *y) {
    int temporary = *x;
    *x = *y;
    *y = temporary;
}

void displayArrayContents(int arraySize, int array[]) {
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void performBubbleSort(int arraySize, int array[]) {
    int comparisonsCount = 0;
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            comparisonsCount++;
            if (array[j] > array[j + 1]) {
                swapValues(&array[j], &array[j + 1]);
            }
        }
    }

    displayArrayContents(arraySize, array);
    cout << "Bubble Sort Comparisons: " << comparisonsCount << endl;
}

void performInsertionSort(int arraySize, int array[]) {
    int i, key, j;
    for (i = 1; i < arraySize; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void performSelectionSort(int arraySize, int array[]) {
    int comparisonsCount = 0;
    for (int i = 0; i < arraySize - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arraySize; j++) {
            comparisonsCount++;
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swapValues(&array[i], &array[minIndex]);
    }

    cout << "Selection Sort Comparisons: " << comparisonsCount << endl;
    displayArrayContents(arraySize, array);
}

void mergeArrays(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArray[n1], rightArray[n2];
    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = array[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void recursivelyPerformMergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        recursivelyPerformMergeSort(array, left, mid);
        recursivelyPerformMergeSort(array, mid + 1, right);
        mergeArrays(array, left, mid, right);
    }
}

int recursiveBinarySearch(int array[], int left, int right, int key, int &comparisons) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (array[mid] == key) {
            return mid;
        } else if (array[mid] < key) {
            return recursiveBinarySearch(array, mid + 1, right, key, comparisons);
        } else {
            return recursiveBinarySearch(array, left, mid - 1, key, comparisons);
        }
    }
    return -1;
}

int iterativeBinarySearch(int array[], int arraySize, int key, int &comparisons) {
    int left = 0, right = arraySize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (array[mid] == key) {
            return mid;
        } else if (array[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arraySize;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    int array[arraySize];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < arraySize; i++) {
        cin >> array[i];
    }

    cout << "\nMenu:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Merge Sort\n";
    cout << "4. Binary Search (Recursive)\n";
    cout << "5. Binary Search (Iterative)\n";
    cout << "Enter your choice: ";
    int userChoice;
    cin >> userChoice;

    switch (userChoice) {
        case 1:
            performBubbleSort(arraySize, array);
            break;
        case 2:
            performSelectionSort(arraySize, array);
            break;
        case 3:
            recursivelyPerformMergeSort(array, 0, arraySize - 1);
            displayArrayContents(arraySize, array);
            break;
        case 4: {
            int key;
            cout << "Enter the value to find: ";
            cin >> key;
            int comparisons = 0;
            int result = recursiveBinarySearch(array, 0, arraySize - 1, key, comparisons);
            if (result != -1) {
                cout << "Element found at index " << result << endl;
            } else {
                cout << "Element not found\n";
            }
            cout << "Comparisons: " << comparisons << endl;
            break;
        }
        case 5: {
            int key;
            cout << "Enter the value to find: ";
            cin >> key;
            int comparisons = 0;
            int result = iterativeBinarySearch(array, arraySize, key, comparisons);
            if (result != -1) {
                cout << "Element found at index " << result << endl;
            } else {
                cout << "Element not found\n";
            }
            cout << "Comparisons: " << comparisons << endl;
            break;
        }
        default:
            cout << "Invalid choice\n";
    }

    return 0;
}

