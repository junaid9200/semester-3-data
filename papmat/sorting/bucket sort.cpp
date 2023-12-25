#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<float>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(vector<float>& bucket) {
    int n = bucket.size();
    for (int i = 1; i < n; ++i) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j = j - 1;
        }

        bucket[j + 1] = key;
    }
}

void bucketSort(vector<float>& arr) {
    const int n = arr.size();
    vector<vector<float> > buckets(n);

    // Put elements into buckets
    for (int i = 0; i < n; ++i) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < n; ++i) {
        insertionSort(buckets[i]);
    }

    // Concatenate the sorted buckets
	int index = 0;
	for (int i = 0; i < n; ++i) {
    	for (vector<float>::iterator it = buckets[i].begin(); it != buckets[i].end(); ++it) {
        	arr[index++] = *it;
    	}
	}
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<float> arr(n);

    cout << "Enter the elements (floating-point numbers between 0 and 1): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr);

    bucketSort(arr);

    cout << "Sorted array using Bucket Sort: ";
    printArray(arr);

    return 0;
}

