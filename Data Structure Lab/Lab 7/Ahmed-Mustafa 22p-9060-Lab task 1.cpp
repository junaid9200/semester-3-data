#include<iostream>
#include<string>

using namespace std;

class Queue{
	public:
	int front;
	int rear;
	int queue_size;
	string* array;
	Queue(int queue_size){
		this->queue_size = queue_size;
		front = -1;
		rear = -1;
		array = new string[queue_size];
	}
	
	bool isEmpty(){
		if(front == -1 && rear == -1) {
		return true;
		}
		else{
			return false;
		}
	}
	
	bool isFull(){
		if(((rear+1)%queue_size) == front) {
			return true;
		}
		else{
			return false;
		}
	}
	
	void enqueue(){
		string name_to_add;
		cout << "Enter Patient name to queue: ";
		cin >> name_to_add;
		if(isFull()){
			cout << "Queue is full ! "<< name_to_add << ", Kindly wait your turn." << endl; 
			return;
		}
		else if(isEmpty()){
			front = 0;
			rear = 0;
		}
		else{
			rear = (rear+1) % queue_size;
		}
		array[rear] = name_to_add;
		cout << "Patient " << name_to_add <<" is now in queue." << endl;
	}
	
	void dequeue(){
		if(isEmpty()){
			cout << "Queue is empty." << endl;
			return;
		}
		string name_to_remove = array[front];
		if(!isEmpty()) {
			if(front == rear) {
				front = -1;
				rear = -1;
			}
			else{
				front = (front+1) % queue_size;
			}
			cout << "Patient " << name_to_remove << " is now with Doctor." << endl;
		}
	}
	
	void next_in_queue(){
		if(isEmpty()){
			cout << "Queue is Empty !" << endl;
			return;
		}
		else{
			cout << "Next is queue: " << array[front] << endl;
		}
	}
	
	void displayAll(){
		cout << "Patient in Queue: "<<endl;
		if(isEmpty()){
			cout << "no-patient" << endl;
			return;
		}
		int i = front;
		do {
			cout << array[i] << " ";
			i = (i + 1) % queue_size;
		}
		while (i != (rear + 1) % queue_size);
		cout << endl;
	}
};
int main(){
	int number_of_seats;
	int user_input;
	cout << "Welcome to Doctor's Apple Office." << endl;
	cout << "\nEnter the number of seats in waiting area: ";
	cin >> number_of_seats;
	Queue object(number_of_seats);
	while(true){
		cout << "\nSelect one of the options below !" << endl;
		cout << "\n1) Enter a patient in waiting queue." << endl;
		cout << "2) Send next patient to the doctor." << endl;
		cout << "3) See next in Queue." << endl;
		cout << "4) Display all patient in queue." << endl;
		cout << "5) Exit the programe." << endl;
		cout << "\nYour Input: ";
		cin >> user_input;
		switch(user_input){
			case 1:
				object.enqueue();
				break;
			case 2:
				object.dequeue();
				break;
			case 3:
				object.next_in_queue();
				break;
			case 4:
				object.displayAll();
				break;
			case 5:
				cout << "Thanks for using programe." << endl;
				return false;
			default:
				cout << "Your Have Entered Invalid Input ! Please try again." << endl;
				break;	
		}
	}	
	return 0;
}
