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
			current = new_node;				current = current->next_ptr;

			new_node->next_ptr = head;
		}
		else{
			current = head;
			while(current->next_ptr != head){
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
	
	void middle() {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    node* slow_ptr = head;
    node* fast_ptr = head;

    while (fast_ptr->next_ptr != head && fast_ptr->next_ptr->next_ptr != head) {
        slow_ptr = slow_ptr->next_ptr;
        fast_ptr = fast_ptr->next_ptr->next_ptr;
    }

    cout << "Middle of the list: " << slow_ptr->data << endl;
}

};
int main(){
	circular_list list;
	list.add();
	list.add();
	list.add();
	list.add();
	list.add();
	list.add();
	list.add();
	list.add();
	list.add();
	list.display();
	list.middle();
	return 0;
}
