#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next_ptr;
	node(int data){
		this->data = data;
		next_ptr = nullptr;
	}
};

class circular_list{
	
	public:
	node* head;
	node* current;
	
	circular_list(){
		head = nullptr;
		current = nullptr;
	}
	
	void add(){
		int data;
		cout<<"Enter list data: ";
		cin>>data;
		node* new_node = new node(data);
		if(head == nullptr){
			head = new_node;
			current = new_node;
			new_node->next_ptr = head;
		}
		else{
			current = head;
			while(current->next_ptr != head){
				current = current->next_ptr;
			}
			current->next_ptr = new_node;
			new_node->next_ptr = head;	
		}	
	}
	
	void display(){
    current = head;
    	do {
        	cout << "Display..." << endl;
        	cout << current->data << endl;
        	current = current->next_ptr;
    	} while(current != head);
	}
	
	int get_length(){
		int length = 0;
		current = head;
		do{
			current = current->next_ptr;
			length++;
		}
		while(current != head);
		return length;
	}
	
	void treverse(){
    	current = head;
    	int size = get_length(); // Get the length of the circular list
    	int array[size]; // Create an array to store the data

    	for(int i = 0; i < size; i++){
        	array[i] = current->data;
        	current = current->next_ptr; // Move to the next node
    	}

    	for(int i = size - 1; i >= 0; i--){
        	cout << "traverse..." << endl;
        	cout << array[i] << endl;
    	}
	}

};
int main(){
	circular_list list;
	list.add();
	list.add();
	list.add();
	list.display();
	list.treverse();
	return 0;
}
