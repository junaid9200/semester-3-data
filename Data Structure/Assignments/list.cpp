#include <iostream>
using namespace std;

class Array {
    int size;
    int *ptr1;
    int currentIndex;

public:
    Array(int size) {
        this->size = size;
        ptr1 = new int[size];
        currentIndex = 0; // Initialize current index
    }

    void add(int value) {
        if (currentIndex < size) {
            ptr1[currentIndex] = value;
            currentIndex++;
            cout << "Value added successfully." << endl;
        } else {
            cout << "Array is full. Cannot add more elements." << endl;
        }
    }

    void update(int index, int value) {
        if (index >= 0 && index < currentIndex) {
            ptr1[index] = value;
            cout << "Value updated successfully." << endl;
        } else {
            cout << "Invalid index. Cannot update value." << endl;
        }
    }

    int length() {
        return currentIndex;
    }

    void moveBack() {
        if (currentIndex > 0) {
            currentIndex--;
        } else {
            cout << "Already at the beginning of the array." << endl;
        }
    }

    void moveNext() {
        if (currentIndex < size) {
            currentIndex++;
        } else {
            cout << "Already at the end of the array." << endl;
        }
    }

    void moveToStart() {
        currentIndex = 0;
    }

    void moveToEnd() {
        currentIndex = length();
    }

    void remove(int index) {
        if (index >= 0 && index < currentIndex) {
            for (int i = index; i < currentIndex - 1; i++) {
                ptr1[i] = ptr1[i + 1];
            }
            currentIndex--;
            cout << "Value removed successfully." << endl;
        } else {
            cout << "Invalid index. Cannot remove value." << endl;
        }
    }

    int get(int index) {
        if (index >= 0 && index < currentIndex) {
            return ptr1[index];
        } else {
            cout << "Invalid index. Cannot get value." << endl;
            return -1; // Return a default value indicating failure
        }
    }

    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < currentIndex; i++) {
            cout << ptr1[i] << " ";
        }
        cout << endl;
    }

    ~Array() {
        delete[] ptr1;
    }
};

int main() {
    int size;
    int user_input;
    cout << "Enter the size of Array: ";
    cin >> size;

    Array object(size);
    do {
        cout << "\nSelect One of The Option Below." << endl;
        cout << "\n1-  Add Item." << endl;
        cout << "2-  Update Value." << endl;
        cout << "3-  Length Of List Items." << endl;
        cout << "4-  Move Back." << endl;
        cout << "5-  Move Next." << endl;
        cout << "6-  Move To Start." << endl;
        cout << "7-  Move To End." << endl;
        cout << "8-  Remove Item." << endl;
        cout << "9-  Get Value." << endl;
        cout << "10- Display Item." << endl;
        cout << "\nYour Input: ";
        cin >> user_input;

        int index, value;

        switch (user_input) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                object.add(value);
                break;
            case 2:
                cout << "Enter index to update: ";
                cin >> index;
                cout << "Enter new value: ";
                cin >> value;
                object.update(index, value);
                break;
            case 3:
                cout << "Length of the list: " << object.length() << endl;
                break;
            case 4:
                object.moveBack();
                break;
            case 5:
                object.moveNext();
                break;
            case 6:
                object.moveToStart();
                break;
            case 7:
                object.moveToEnd();
                break;
            case 8:
                cout << "Enter index to remove: ";
                cin >> index;
                object.remove(index);
                break;
            case 9:
                cout << "Enter index to get value: ";
                cin >> index;
                value = object.get(index);
                if (value != -1) {
                    cout << "Value at index " << index << ": " << value << endl;
                }
                break;
            case 10:
                object.display();
                break;
            default:
                cout << "Invalid input." << endl;
        }
    } while (user_input > 0 && user_input < 11);

    return 0;
}
