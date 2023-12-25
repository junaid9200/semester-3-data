#include<iostream>
#include<vector>
using namespace std;

class MaxHeap {
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
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }

        if (right < heap.size() && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        int lastIndex = heap.size() - 1;
        heapifyUp(lastIndex);
    }

    void extractMax() {
        if (heap.empty()) {
            cout << "Heap is empty. Cannot extract maximum.\n";
        } else {
            swap(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
            heapifyDown(0);
            cout << "Maximum element extracted from Max Heap.\n";
        }
    }

    void display() {
        if (heap.empty()) {
            cout << "Max Heap is empty.\n";
        } else {
            cout << "Max Heap: ";
            for (int i = 0; i < heap.size(); i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    MaxHeap maxHeap;

    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert into Max Heap\n";
        cout << "2. Extract Maximum from Max Heap\n";
        cout << "3. Display Max Heap\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert into Max Heap: ";
                cin >> value;
                maxHeap.insert(value);
                cout << "Value " << value << " inserted into Max Heap.\n";
                break;
            case 2:
                maxHeap.extractMax();
                break;
            case 3:
                maxHeap.display();
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

