#include<iostream>
using namespace std;

class Queue {
public:
    int *arr;
    int front, back;
    int size;
    
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        back = -1;
    }
    
    bool isFull() {
        return back == size - 1;
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    void enqueue(int data){
        if (isFull()) {
            cout << "Queue is Full." << endl;
        } else {
            back++;
            arr[back] = data;
            if (front == -1) {
                front++;
            }
            cout << "Enqueued element: " << data << endl;
        }
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
        } else {
            int dequeuedValue = arr[front];
            front++;
            cout << "Dequeued element: " << dequeuedValue << endl;
            if (front > back) {
                front = -1;
                back = -1;
            }
        }
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= back; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    
    ~Queue() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter Queue size: "; 
    cin >> size;
    Queue obj(size);
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

