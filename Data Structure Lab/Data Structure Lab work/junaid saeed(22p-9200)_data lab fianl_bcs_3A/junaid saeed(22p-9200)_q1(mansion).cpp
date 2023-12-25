#include<iostream>
using namespace std;

class Node 
{
public:
    string val;
    Node* next;
    Node(string val) 
	{
        this->val = val;
        next = NULL;
    }
};

class Stack 
{
public:
    Node* top;

    Stack() 
	{
        top = NULL;
    }

    ~Stack() 
	{
        while (!isEmpty()) 
		{
            pop();
        }
    }

    bool isEmpty() 
	{
        return top == NULL;
    }

    void push(string val) 
	{
        Node* node1 = new Node(val);
        node1->next = top;
        top = node1;
    }

    string pop() 
	{
        if (isEmpty()) 
		{
            cout << "Stack is empty." << endl;
            return "";
        }
        else
        {
        	
            Node* temp1 = top;
            string popval = temp1->val;
            top = top->next;
            delete temp1;
            return popval;
        	
		}
       
    }
};

class Queue 
{
    int front;
    int rear;
    int size;
    string* arr;

public:
    Queue(int size) 
	{
        front = -1;
        rear = -1;
        this->size = size;
        arr = new string[size];
    }

    ~Queue() 
	{
        delete[] arr;
    }

    bool isEmpty() 
	{
        return front == -1;
    }

    bool isFull() 
	{
        return (rear + 1) % size == front;
    }

    void enqueue(string val) 
	{
        if (isFull()) 
		{
            cout << "oops , Queue is full!... Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) 
		{
            front = 0;
        }

        rear = (rear + 1) % size;
        arr[rear] = val;
    }

    string dequeue() 
	{
        if (isEmpty()) 
		{
            cout << "oops , Queue is empty. Cannot dequeue." << endl;
            return "";
        }

        string deqval = arr[front];

        if (front == rear) 
		{
            front = rear = -1;
        } 
		else 
		{
            front = (front + 1) % size;
        }

        return deqval;
    }

    void getFront() 
	{
        if (isEmpty()) 
		{
            cout << "oops, queue is empty!.. so how can be there a front :)" << endl;
        } 
		else 
		{
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main() {
    int choice;
    Stack encounters;
    cout<<"\t\t\t ----{ Welcome to Haunted Mansion Exploration }----"<<endl;
    cout<<endl;

    Queue mansionQueue(6);
    mansionQueue.enqueue("The Gateway to Darkness");
    mansionQueue.enqueue("The Creeping Corridor");
    mansionQueue.enqueue("The Abandoned Lounge");
    mansionQueue.enqueue("The Haunted Gallery");
    mansionQueue.enqueue("The Shadowed Library");
    mansionQueue.enqueue("The Broken Window");
    cout << "Start exploring the mansion? " << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout<<endl;
    cout<<"--> Your option : ";
    cin >> choice;
    cout<<endl;
    if (choice == 1) 
	{
        while (!mansionQueue.isEmpty()) 
		{
            cout << "Current location: " << mansionQueue.dequeue() << endl;
            cout << "Did you encountered a ghost or an evil spirit :( ? "<<endl;
            cout<<"1. Yes "<<endl<<"2. No"<<endl;
             cout<<endl;
             cout<<"--> Your option : ";
            cin >> choice;
            cout<<endl;
            
            if (choice == 1) 
			{
                cout << "What did you see ? was it terrifying ? "<<endl;
                string enc;
                cin.ignore();
                getline(cin, enc);
                encounters.push(enc);
            }

            if (!mansionQueue.isEmpty()) 
			{
                cout << "Continue exploring? (1. Yes / 2. No): ";
                cin >> choice;
            } 
			else 
			{
                cout << "yahoo , we have completed explorations , most recent ghost/evil spirit encounters :  " << endl;
                while (!encounters.isEmpty()) 
				{
                    cout << encounters.pop() << endl;
                }
                cout << "yayy, you escaped safe and sound :)" << endl;
            }

            if (choice == 2) 
			{
                cout << "See you next time" << endl;
                break;
            }
        }
    } 
	else 
	{
        cout << "See you next time" << endl;
    }
}

