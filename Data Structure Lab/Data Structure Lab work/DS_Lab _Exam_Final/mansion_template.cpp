#include<iostream>
using namespace std;
class Node 
{
	public:
		string val;
		Node *next;
		Node(string val) 
		{
			this->val=val;
			next=NULL;
		}
};
class Stack 
{
	public:
		Node *top;

		Stack() 
		{
			top=NULL;

		}
		~Stack() 
		{

		}

		bool isEmpty() 
		{
			if(top==NULL) 
			{
				return true;
				cout<<"Stack is empty"<<endl;
			} 
			else 
			{
				return false;
			}
		}

		void push(string val) 
		{
			Node* node1=new Node(val);
			node1->next=top;
			top=node1;

		}

		string pop() 
		{
			if (isEmpty())
			{
				return "Stack is empty";
			}
			else
			{
				Node* temp=top;
				string popval=temp->val;
				top=top->next;
				delete temp;
				return popval;
			}

		}

};

class Queue 
{
		int front;
		int rear;
		int size;
		string *arr;
	public:
		Queue(int size) 
		{
			front=-1;
			rear=-1;
			this->size=size;
			arr=new string[size];
		}
		bool isEmpty() 
		{
			return (front==rear);
		}
		bool isFull() 
		{
			return (rear=size-1);

		}

		void enqueue(string val) 
		{
			if(isFull())
			{
				return;
			}
			
			{
				if(front==-1&&rear==-1)
				{
					front=0;
					rear=0;
				}
				rear++;
				arr[rear]=val;
			}

		}

		string dequeue() 
		{
			if(isEmpty())
			{
				return "Queue is empty!....";
			}
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else
			{
				front ++;
			}

		}

		void getFront() 
		{
			if(isEmpty())
			{
				cout<<"Queue is empty!....";
				return;
			}
			else
			{
					cout<<"Front element : "<<arr[front]<<endl;
			}
		}
};

int main() 
{
	int choice;
	// Set up the stack for encouters
	Stack encounters;
	cout<<"Welcome to the haunted mansion exploration"<<endl;

	Queue mansionQueue(6);
	mansionQueue.enqueue("The Gateway to Darkness");
	mansionQueue.enqueue("The Creeping Corridor");
	mansionQueue.enqueue("The Abandoned Lounge");
	mansionQueue.enqueue("The Haunted Gallery");
	mansionQueue.enqueue("The Shadowed Library");
	mansionQueue.enqueue("The Broken Window");
	cout<<"Start exploring the mansion? "<<endl;
	cout<<"1. Yes"<<endl;
	cout<<"2. No"<<endl;
   if (choice == 1) 
    {
        cout << "Currently at : The Gateway to Darkness" << endl;
        encounters.push("The Gateway to Darkness"); 
        mansionQueue.dequeue(); 
        while (!encounters.isEmpty()) 
        {
            cout << "Choose your next move:" << endl;
            cout << "1. Move forward" << endl;
            cout << "2. Go back" << endl;
            int move;
            cin >> move;
            if (move == 1) 
            {
                string currentLocation = encounters.pop();
                mansionQueue.getFront();
                string nextLocation = mansionQueue.dequeue();
                encounters.push(nextLocation);
                cout << "Currently at : " << nextLocation << endl;
            } 
            else if (move == 2) 
            {
                string currentLocation = encounters.pop();
                if (!encounters.isEmpty()) 
                {
                    string previousLocation = encounters.pop();
                    encounters.push(previousLocation);
                    cout << "Currently at : " << previousLocation << endl;
                } 
                else 
                {
                    cout << "You are at the starting point" << endl;
                    encounters.push(currentLocation); 
                }
            } 
            else 
            {
                cout << "Invalid choice. Try again." << endl;
            }
        }
        cout << "Mansion exploration completed!" << endl;
    } 
    else 
    {
        cout << "See you next time" << endl;
        return 0;
    }
    return 0;
}
