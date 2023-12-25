#include <iostream>
#include <sstream>
using namespace std;

class Stack {
private:
    string* arr;
    int top;
    int size;

public:
    Stack(int size) {
        arr = new string[size];
        this->size = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(string item) {
        if (isFull()) {
            cout << "Ken's backpack is full! He can't carry more messages." << endl;
        } else {
            arr[++top] = item;
        }
    }

    string pop() {
        if (isEmpty()) {
            cout << "Ken's backpack is empty. There are no more messages." << endl;
            return "";
        } else {
            return arr[top--];
        }
    }
};

struct Node {
    string data;
    Node* next;

    Node(string data) : data(data), next(nullptr) {}
};

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void append(string message) {
        Node* newnode = new Node(message);
        if (tail == nullptr) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    Node* getHead() {
        return head;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
};

// Function to reverse the order of words in a message
string reverseMessageWords(string message) {
    istringstream iss(message);
    string reversedMessage = "";
    string word;
    while (iss >> word) {
        reversedMessage = word + " " + reversedMessage;
    }
    return reversedMessage.substr(0, reversedMessage.length() - 1);
}

int main() {
    int size;
    cout << "Ken can only carry a limited number of messages. How many messages can he carry: ";
    cin >> size;
    cout << endl;

    Stack stack1(size);
    LinkedList messages;
    cin.ignore();

    cout << "Ken's Adventure in the Forest" << endl;
    cout << "Ken follows the decrypted messages to find the treasure...!" << endl;
    cout << endl;

    while (true) {
        cout << "Ken discovers a message on his path. Enter the message (or 's' to stop): ";
        string message;
        getline(cin, message);

        if (message == "s") {
            cout << "Can't proceed further...!" << endl;
            break;
        }

        string decryptedMessage = reverseMessageWords(message);
        cout << "Ken successfully decrypts the message: " << decryptedMessage << endl;
        stack1.push(decryptedMessage);
    }

    cout << "Decrypted Messages:" << endl;
    while (!stack1.isEmpty()) {
        string message = stack1.pop();
        messages.append(message);
        cout << "Ken reads a message: " << message << endl;
    }

    cout << "Following the messages, Ken arrives at the final location:" << endl;
    cout << "X Marks the Treasure!" << endl;
}

