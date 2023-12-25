#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void display(int size, int arr[]){
    for(int i=0; i<size; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void bubbleSort(int size, int arr[]){
    int comparisons = 0;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            comparisons++;
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
        cout << "After Swaping: ";
        display(size, arr);
    }
    cout << "Bubble Sort Comparisons: " << comparisons << endl;
}

void selectionSort(int size, int arr[]){
    int comparisons = 0;
    for(int i=0; i<size-1; i++){
        int min_Index = i;
        for(int j=i+1; j<size; j++){
            comparisons = comparisons + 1;
            if(arr[j] < arr[min_Index]){
                min_Index = j;
            }
        }
        swap(&arr[min_Index], &arr[i]);
        cout << "After Swaping: ";
        display(size, arr);
    }
    cout << "Selection Sort Comparisons: " << comparisons << endl;
}

// Merge two subarrays L and M into arr
void merge(int arr[], int left, int mid, int right){
    int no_of_elements_t1 = mid-left+1; // elements in left t-array 
    int no_of_elements_t2 = right-mid; // elements in right t-array

    int Left_array[no_of_elements_t1];
	int Right_array[no_of_elements_t2];

    for(int j=0; j<no_of_elements_t2; j++){
        Right_array[j] = arr[mid+1+j];
    }
    for(int i=0; i<no_of_elements_t1; i++){
        Left_array[i] = arr[left+i];
    }

    int temp1 = 0;
    int temp2 = 0;
    int temp3 = left;

    while(temp1<no_of_elements_t1 && temp2<no_of_elements_t2){
        if(Left_array[temp1] <= Right_array[temp2]){
            arr[temp3] = Left_array[temp1];
            temp1++;
        }
		else{
            arr[temp3] = Right_array[temp2];
            temp2++;
        }
        temp3++;
    }

    while(temp1<no_of_elements_t1){
        arr[temp3] = Left_array[temp1];
        temp1++;
        temp3++;
    }

    while(temp2<no_of_elements_t2){
        arr[temp3] = Right_array[temp2];
        temp2++;
        temp3++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int binarySearchRecursive(int arr[], int left, int right, int key, int &comparisons){
    if(left <= right){
        int mid = left+(right-left)/2; // right = size-1
        if(arr[mid] == key){
            comparisons++;
            return mid;
        }
        if(arr[mid]>key){
            comparisons++;
            return binarySearchRecursive(arr, left, mid-1, key, comparisons);
        }
        if(arr[mid]<key){
        	comparisons++;
        	return binarySearchRecursive(arr, mid+1, right, key, comparisons);
		}
    }
    return -1;
}

int binarySearchIterative(int arr[], int size, int key, int &comparisons) {
    int left = 0;
    int right = size-1;
    while(left <= right){
        int mid = left+(right-left)/2;
        if(arr[mid] == key){
            comparisons++;
            return mid;
        }
        if(arr[mid]>key){
            comparisons++;
            right = mid-1;
        }
		else if(arr[mid]<key){
            comparisons++;
            left = mid+1;
        }
    }
    return -1;
}

int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array:\n";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    // Display the menu
    cout << "\nMenu:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Merge Sort\n";
    cout << "4. Binary Search (Recursive)\n";
    cout << "5. Binary Search (Iterative)\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            bubbleSort(size, arr);
            break;
        case 2:
            selectionSort(size, arr);
            break;
        case 3:
            mergeSort(arr, 0, size-1);
            display(size, arr);
            break;
        case 4: {
            int key;
            cout << "Enter the value to find: ";
            cin >> key;
            int comparisons = 0;
            int result = binarySearchRecursive(arr, 0, size-1, key, comparisons);
            if(result != -1){
                cout << "Element found at index " << result << endl;
            }
			else{
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
            int result = binarySearchIterative(arr, size, key, comparisons);
            if (result != -1) {
                cout << "Element found at index " << result << endl;
            }
			else{
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
