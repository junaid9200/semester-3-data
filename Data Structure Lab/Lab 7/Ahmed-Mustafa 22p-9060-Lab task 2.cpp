#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string person_name;
    Node* next_ptr;

    Node(string person_name) {
        this->person_name = person_name;
        next_ptr = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
    	if(front == nullptr){
    		return true;
		}
		else{
			return false;
		}
    }

    void enqueue(string visitorName) {
        Node* newNode = new Node(visitorName);
        if(isEmpty()){
            front = rear = newNode;
        }
		else{
            rear->next_ptr = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if(isEmpty()){
            cout << "Queue is empty !" << endl;
        }
		else{
            Node* temp = front;
            front = front->next_ptr;
            cout << temp->person_name << " has purchased a ticket.";
            delete temp;
        }
    }
};

int main() {
    Queue ticketQueue;
    Queue rollerCoasterQueue;
    Queue motionRideQueue;
    Queue roundWheelQueue;

    int user_input;
    string visitorName;
	
	cout << "Welcome To HOLIDAY-PARK !"  << endl;
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Enter visitor in the tickets purchase queue\n";
        cout << "2. Sell a ticket." << endl;
        cout << "3. Process all queues." << endl;
        cout << "4. Exit." << endl;
        cout << "Your Input: ";
        cin >> user_input;
        switch (user_input) {
            case 1:
                cout << "Enter visitor's name: ";
                cin >> visitorName;
                ticketQueue.enqueue(visitorName);
                cout << visitorName << " added to the ticket purchase queue.\n";
                break;
            case 2:
                if (!ticketQueue.isEmpty()) {
                    visitorName = ticketQueue.front->person_name;
                    ticketQueue.dequeue();
                    cout << "Which attraction's ticket "<< visitorName << "wants." << endl;
					cout << "1) Roller Coaster." << endl;
					cout << "2) Motion Ride." << endl;
					cout << "3) Round Wheel." << endl;
					cout << "Your Input: ";
                    int attractionChoice;
                    cin >> attractionChoice;
                    switch (attractionChoice) {
                        case 1:
                            rollerCoasterQueue.enqueue(visitorName);
                            cout << visitorName << " added to the Roller Coaster queue." << endl;
                            break;
                        case 2:
                            motionRideQueue.enqueue(visitorName);
                            cout << visitorName << " added to the Motion Ride queue." << endl;
                            break;
                        case 3:
                            roundWheelQueue.enqueue(visitorName);
                            cout << visitorName << " added to the Round Wheel queue." << endl;
                            break;
                        default:
                            cout << "Invalid Input! Try-Again." << endl;
                    }
                }
				else{
                    cout << "No visitors in the ticket purchase queue." << endl;
                }
                break;
            case 3:
                cout << "Processing queues:" << endl;
                cout << "\nRoller Coaster:" << endl;
                while (!rollerCoasterQueue.isEmpty()) {
                    rollerCoasterQueue.dequeue();
                }
                cout << "Motion Ride:" << endl;
                while (!motionRideQueue.isEmpty()) {
                    motionRideQueue.dequeue();
                }
                cout << "Round Wheel:" << endl;
                while (!roundWheelQueue.isEmpty()) {
                    roundWheelQueue.dequeue();
                }
                cout << "\nAll queues processed." << endl;
                break;
            case 4:
                cout << "Thanks For Using Our Program." << endl;
                return false;
            default:
                cout << "Invalid Input. Please try again." << endl;
        }
    }
    return 0;
}

