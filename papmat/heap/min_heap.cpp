#include<iostream>
#include<vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] < heap[minIndex]) {
            minIndex = left;
        }

        if (right < heap.size() && heap[right] < heap[minIndex]) {
            minIndex = right;
        }

        if (i != minIndex) {
            swap(heap[i], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        int lastIndex = heap.size() - 1;
        heapifyUp(lastIndex);
    }

    void extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty. Cannot extract minimum.\n";
        } else {
            swap(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
            heapifyDown(0);
            cout << "Minimum element extracted from Min Heap.\n";
        }
    }

    void display() {
        if (heap.empty()) {
            cout << "Min Heap is empty.\n";
        } else {
            cout << "Min Heap: ";
            for (int i = 0; i < heap.size(); i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    MinHeap minHeap;

    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert into Min Heap\n";
        cout << "2. Extract Minimum from Min Heap\n";
        cout << "3. Display Min Heap\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert into Min Heap: ";
                cin >> value;
                minHeap.insert(value);
                cout << "Value " << value << " inserted into Min Heap.\n";
                break;
            case 2:
                minHeap.extractMin();
                break;
            case 3:
                minHeap.display();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

