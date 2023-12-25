#include <iostream>
#include <string>
using namespace std;

class Node 
{
public:
    char data;
    Node* next;

    Node(char data) 
	{
        this->data = data;
        next = nullptr;
    }
};

class Stack 
{
private:
    Node* topNode;

public:
    Stack() 
	{
        topNode = nullptr;
    }

    void push(char value) 
	{
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    char pop() {
        if (isEmpty()) 
		{
            cout << "Stack underflow" << endl;
        }

        char value = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return value;
    }

    bool isEmpty() 
	{
        return topNode == nullptr;
    }

    char peek() {
        if (isEmpty()) 
		{
            cout << "Stack is empty" << endl;
        }
        return topNode->data;
    }
};

int main() 
{
    Stack undo;
    Stack redo;

    cout<<"enter name : ";
    string curr;
    cin >> curr;

    while (true) 
	{
        cout << "Current Text: " << curr << endl;
        cout<<endl;
        cout << "Options: " << endl;
        cout << "1. Undo" << endl;
        cout << "2. Redo" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) 
		{
            case 1:
                if (!curr.empty()) 
				{
                    char undoChar = curr.back();
                    curr.pop_back();
                    undo.push(undoChar);
                    redo.push(undoChar); 
                }
                break;
            case 2:
                if (!redo.isEmpty()) 
				{
                    char redoChar = redo.pop();
                    undo.push(redoChar);
                    curr += redoChar;
                }
                break;
            case 3:
            	cout<<"Thanks"<<endl;
            	return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}

