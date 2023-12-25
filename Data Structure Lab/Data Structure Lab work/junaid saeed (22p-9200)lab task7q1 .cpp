#include <iostream>
#include <string>

using namespace std;

class Queue {
private:
    string* patients;
    int front;
    int rear;
    int maxSeats;

public:
    Queue(int maxSeats) {
        front = -1;
        rear = -1;
        this->maxSeats = maxSeats;
        patients = new string[maxSeats];
    }

    void enqueue(string patient) {
        if ((rear + 1) % maxSeats == front) {
            cout << "Queue is full. Cannot add more patients." << endl;
            return;
        } else if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSeats;
        }
        patients[rear] = patient;
        cout << "Added " << patient << " to the queue." << endl;
    }

    void dequeue() {
        if (front == -1 && rear == -1) {
            cout << "Queue is empty. No patient to send to the doctor." << endl;
        } else {
            string patient = patients[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % maxSeats;
            }
            cout << "Sent " << patient << " to the doctor." << endl;
        }
    }

    void peek() 
	{
        if (front == -1 && rear == -1) {
            cout << "Queue is empty. No patient next." << endl;
        } 
		else {
            cout << "Next patient: " << patients[front] << endl;
        }
    }

    void display() 
	{
        if (front == -1 && rear == -1) 
		{
            cout << "Queue is empty." << endl;
        } 
		else 
		{
            cout << "Patient Queue:" << endl;
            int i = front;
            while (i != rear) {
                cout << patients[i] << endl;
                i = (i + 1) % maxSeats;
            }
            cout << patients[rear] << endl;
        }
    }
};

int main() {
    int choice, maxSeats;
    string patientName;
    cout << "Enter the maximum number of seats : ";
    cin >> maxSeats;
    Queue queue(maxSeats);

    while (true) 
	{
        cout << "\t\t\t--------------------------------------" << endl;
        cout << "\t\t\t1.Add Patient to Queue" << endl;
        cout << "\t\t\t2.Send the next patient to the doctor" << endl;
        cout << "\t\t\t3.See who is next" << endl;
        cout << "\t\t\t4.Display Patient Queue" << endl;
        cout << "\t\t\t5.Exit" << endl;
        cout << "\t\t\t--------------------------------------" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) 
		{
            case 1:
                cout << "Enter patient name: ";
                cin >> patientName;
                queue.enqueue(patientName);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.peek();
                break;
            case 4:
                queue.display();
                break;
            case 5:
                cout << "thnks for using .." << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}

