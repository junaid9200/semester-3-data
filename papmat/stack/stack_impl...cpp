#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int top;
    int arr[MAX_SIZE];

public:
    Stack() : top(-1) {}

    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push more elements." << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed to the stack." << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
        } else {
            cout << arr[top--] << " popped from the stack." << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Check if Empty\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.display();
                break;

            case 4:
                if (stack.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;

            case 5:
                cout << "Exiting program. Bye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 5);

    return 0;
}

