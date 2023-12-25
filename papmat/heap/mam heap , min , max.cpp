#include<iostream>
#include <vector>
using namespace std;

class Heap {
public:
    vector<int> heapTree;

    int getParent(int child) {
        int parent = (child - 1) / 2;

        if (child == 0) {
            return -1;
        } else {
            return parent;
        }
    }

    int getLeft(int parent) {
        int leftChild = 2 * parent + 1;
        if (leftChild < heapTree.size()) {
            return leftChild;
        } else {
            return -1;
        }
    }

    int getRight(int parent) {
        int rightChild = 2 * parent + 2;
        if (rightChild < heapTree.size()) {
            return rightChild;
        } else {
            return -1;
        }
    }

    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node) {
        int parent = getParent(node);
        if (node >= 0 && parent >= 0 && compare(heapTree[parent], heapTree[node])) {
            swap(&heapTree[node], &heapTree[parent]);
            heapifyUp(getParent(node));
        }
    }

    void heapifyDown(int node) {
        int leftChild = getLeft(node);
        int rightChild = getRight(node);
        int dominant = node;

        if (leftChild >= 0 && compare(heapTree[leftChild], heapTree[dominant])) {
            dominant = leftChild;
        }

        if (rightChild >= 0 && compare(heapTree[rightChild], heapTree[dominant])) {
            dominant = rightChild;
        }

        if (dominant != node) {
            swap(&heapTree[node], &heapTree[dominant]);
            heapifyDown(dominant);
        }
    }

    virtual bool compare(int a, int b) = 0;

    void insert(int value) {
        heapTree.push_back(value);
        heapifyUp(heapTree.size() - 1);
    }

    void del() {
        if (heapTree.empty()) {
            cout << "Heap is empty. Cannot delete.\n";
        } else {
            swap(&heapTree[0], &heapTree[heapTree.size() - 1]);
            heapTree.pop_back();
            heapifyDown(0);
        }
    }

    void display() {
        for (int i = 0; i < heapTree.size(); i++) {
            cout << heapTree[i] << " ";
        }
        cout << endl;
    }
};

class MaxHeap : public Heap {
public:
    virtual bool compare(int a, int b) {
        return a < b;
    }
};

class MinHeap : public Heap {
public:
    virtual bool compare(int a, int b) {
        return a > b;
    }
};

int main() {
    MaxHeap maxHeap;
    MinHeap minHeap;

    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert into Max Heap\n";
        cout << "2. Delete from Max Heap\n";
        cout << "3. Display Max Heap\n";
        cout << "4. Insert into Min Heap\n";
        cout << "5. Delete from Min Heap\n";
        cout << "6. Display Min Heap\n";
        cout << "7. Exit\n";
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
                maxHeap.del();
                cout << "Deleted from Max Heap.\n";
                break;
            case 3:
                cout << "Max Heap: ";
                maxHeap.display();
                break;
            case 4:
                cout << "Enter value to insert into Min Heap: ";
                cin >> value;
                minHeap.insert(value);
                cout << "Value " << value << " inserted into Min Heap.\n";
                break;
            case 5:
                minHeap.del();
                cout << "Deleted from Min Heap.\n";
                break;
            case 6:
                cout << "Min Heap: ";
                minHeap.display();
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 7);

    return 0;
}

