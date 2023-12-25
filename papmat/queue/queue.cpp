#include <iostream>

using namespace std;

// Node structure for the queue
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Function to enqueue a value
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    // Function to dequeue a value
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return -1; // Assuming -1 as an invalid value for this example
        }

        Node* temp = front;
        int value = temp->data;

        front = front->next;
        delete temp;

        cout << "Dequeued: " << value << endl;

        return value;
    }

    // Function to display the queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Main function with menu
int main() {
    Queue queue;
    int choice, value;

    do {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;

            case 2:
                value = queue.dequeue();
                if (value != -1) {
                    cout << "Dequeued value: " << value << endl;
                }
                break;

            case 3:
                queue.display();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

