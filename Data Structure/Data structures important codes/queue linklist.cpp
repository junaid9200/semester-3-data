#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
public:
    Node* front;
    Node* back;

    Queue() {
        front = nullptr;
        back = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }

        cout << "Enqueued element: " << data << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
        } else {
            Node* temp = front;
            int dequeuedValue = temp->data;
            front = front->next;
            delete temp;

            cout << "Dequeued element: " << dequeuedValue << endl;

            if (front == nullptr) {
                back = nullptr;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
        } else {
            Node* temp = front;
            cout << "Queue elements: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue obj;
    int user_input, key;
    while (true) {
        cout << "Menu" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Your Input: ";
        cin >> user_input;
        switch(user_input) {
            case 1:
                cout << "Enter data to Enqueue: ";
                cin >> key;
                obj.enqueue(key);
                break;
            case 2:
                obj.dequeue();
                break;
            case 3:
                obj.display();
                break;
            case 4:
                cout << "Thanks For Using Our Program." << endl;
                return 0;
            default:
                cout << "Invalid Input." << endl;    
        }
    }
}

