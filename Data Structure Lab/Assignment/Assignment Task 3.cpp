#include<iostream>
using namespace std;

class Student{
	public:
	string name;
	int merit;
	
	Student(string name, int merit){
		this->name = name;
		this->merit = merit;
	}
};

class Node{
	public:
	Student student;
	Node* next;
	
	Node(Student obj):student(obj){
		next = nullptr;
	}
};

class Queue_functions{
	private:
	Node* front;
	Node* rear;
	
	public:
	Queue_functions(){
		front = nullptr;
		rear = nullptr;
	}
	
	bool Is_Empty(){
		if(front == nullptr){
			return true;
		}
	}
	
	void Enqueue(Student obj){
		Node* new_node = new Node(obj);
		if(Is_Empty()){
			front = new_node;
			rear = new_node;
		}
		else{
			rear->next = new_node;
			rear = new_node;
		}
	}
	
	void Dequeue(){
		if(!Is_Empty()){
			Node* temp = front;
			front = front->next;
			delete temp;
		}
	}
	
	int get_queue_size(){
		int size = 0;
		Node* temp = front;
		while(temp != nullptr){
			size = size + 1;
			temp = temp->next;
		}
		return size;
	}
	
	Student get_student(){
		return front->student;
	}	
};

int get_random(){
	return rand() % 3;
}

void Queue_Status(Queue_functions queues[], int queue_number){
    cout << "Displaying Queue Status:" << endl;
    for (int i=0; i<queue_number; ++i) {
        cout << "Queue " << i + 1 <<" Size: "<< queues[i].get_queue_size() << " students" <<endl;
    }
}
int main(){
	Queue_functions queues[3];
	int user_input;
	string name;
	int merit;
	int random_queue;
	int queue_number;
	while(true){
		cout << endl;
		cout << "**CCity-Admission-System**" << endl;
		cout << "1. Add Student To Queue." << endl;
		cout << "2. Process Admission." << endl;
		cout << "3. Check Queue Status." << endl;
		cout << "4. Display Next Applicant." << endl;
		cout << "5. Exit." << endl;
		cout << "Your Input: ";
		cin >> user_input;
		switch(user_input){
			case 1:
				cout << endl;
				cout << "Enter Student Name: ";
				cin >> name;
				cout << "Enter Student Merit (int): ";
				cin >> merit;
				
				random_queue = get_random();
				queues[random_queue].Enqueue(Student(name, merit));
				
				cout << "Student Added To Queue (random): " << random_queue + 1 <<endl;
				break;
			case 2:
				cout << "Processing Applicants..." <<endl;
				cout << endl;
				for(int i=0; i<3; ++i){
					cout << "Processing Queue "<< i + 1 <<endl;
					while(!queues[i].Is_Empty()){
						Student first_student = queues[i].get_student();
						queues[i].Dequeue();
						cout << "Processing: " << first_student.name << endl;
						cout << endl;
						if(first_student.merit > 50){
							cout << "Student " << first_student.name << " Admitted..." <<endl;
						}
						else{
							cout << "Student " << first_student.name << "Not-Admitted..." <<endl;
						}
						cout << endl;
					}
				}
				break;
			case 3:
				Queue_Status(queues, 3);
				break;
			case 4:
				cout << "Enter Queue Number (1,2,3): ";
				cin >> queue_number;
				
				if(queue_number >=1 && queue_number <=3){
					if(!queues[queue_number - 1].Is_Empty()){
						Student next_student = queues[queue_number - 1].get_student();
						cout << "Next In Applicant in Queue " << queue_number << ": " << next_student.name << endl;						
					}
					else{
						cout << "Queue" << queue_number << "Is Empty Now." << endl;
					}
				}
				else{
					cout << "Invalid Queue-Number. Try-Again !" << endl;
				}
				break;
			case 5:
				cout << "Thanks For Choosing CCity-Admission-System. See You Soon !" << endl;
				return false;
			default:
				cout << "Invalid Input. Please Try Again !" << endl;	
		}
	}
	return 0;
}
