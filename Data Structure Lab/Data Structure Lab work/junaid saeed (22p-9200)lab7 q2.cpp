#include <iostream>
#include <string>

using namespace std;

struct Visitor 
{
    string name;
    Visitor* next;

    Visitor(string n) 
	{
        name = n;
        next = nullptr;
    }
};

class Queue {
private:
    Visitor* front;
    Visitor* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string name) 
	{
        Visitor* newVisitor = new Visitor(name);
        newVisitor->next = nullptr;
        if (isEmpty()) 
		{
            front = newVisitor;
            rear = newVisitor;
        } 
		else 
		{
            rear->next = newVisitor;
            rear = newVisitor;
        }
    }

    string dequeue() 
	{
        if (isEmpty()) 
		{
            cout << "Queue is empty." << endl;
            return "";
        } 
		else 
		{
            Visitor* temp = front;
            string visitorName = front->name;
            front = front->next;
            delete temp;
            return visitorName;
        }
    }

    void display() 
	{
        Visitor* current = front;
        if (isEmpty()) 
		{
            cout << "Queue is empty" << endl;
        } 
		else 
		{
            while (current != nullptr) 
			{
                cout << current->name << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue ticket;
    Queue roller;
    Queue motion;
    Queue round;

    int choice;
    string visitorName;

    while (true) {
        cout << "\t\t\t---------------------------------------------" << endl;
        cout << "\t\t\t1. Enter visitor " << endl; 
        cout << "\t\t\t2. Sell a ticket " << endl;
        cout << "\t\t\t3. Process all queues" << endl;
        cout << "\t\t\t4. Exit" << endl;
        cout << "\t\t\t---------------------------------------------" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter visitor name: ";
                cin >> visitorName;
                ticket.enqueue(visitorName);
                break;
            case 2:
                if (!ticket.isEmpty()) {
                    string visitor = ticket.dequeue();
                    cout << "Sold a ticket to " << visitor << "." << endl;
                    cout << "Select attraction (1. Roller Coaster, 2. Motion Ride, 3. Round Wheel): ";
                    int attractionChoice;
                    cin >> attractionChoice;
                    switch (attractionChoice) 
					{
                        case 1:
                            roller.enqueue(visitor);
                            break;
                        case 2:
                            motion.enqueue(visitor);
                            break;
                        case 3:
                            round.enqueue(visitor);
                            break;
                        default:
                            cout << "Invalid attraction choice." << endl;
                            break;
                    }
                }
				 else 
				 {
                    cout << "No visitors in the ticket purchase queue." << endl;
                }
                break;
            case 3:
                cout << "Processing queues:" << endl;
                cout << "Roller Coaster Queue: ";
                roller.display();
                cout << "Motion Ride Queue: ";
                motion.display();
                cout << "Round Wheel Queue: ";
                round.display();
                break;
            case 4:
                cout << "thanks for using.." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

