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

class link_list{
	public:
	node* head;
	node* current;
	node* temp;
	link_list(){
		head = nullptr;
		current = nullptr;
		temp = nullptr;
	}
	
	void add(int value){
		node* new_node = new node(value);
		if(head == nullptr){
			head = new_node;
			current = new_node;
		}
		else{
			current = head;
			while(current->next_ptr != nullptr){
				current = current->next_ptr;
			}
			current->next_ptr = new_node;
		}
	}
	
	void display(){
		current = head;
		while(current != nullptr){
			cout << current->data << " ";
			current = current->next_ptr;
		}
	}
	
	void reverse() {
    if (head == nullptr || head->next_ptr == nullptr) {
        return; // No need to reverse if the list is empty or has only one element
    }

    node* prev = nullptr;
    node* current = head;
    node* next = nullptr;

    while (current != nullptr) {
        next = current->next_ptr;
        current->next_ptr = prev;
        prev = current;
        current = next;
    }

    // Finally, update the head to point to the new first element (which was the last element)
    head = prev;
}

	
	int get_length(){
		int length = 0;
		current = head;
		if(head == nullptr){
			return 0;
		}
		else{
			while(current != nullptr){
				length++;
				current = current->next_ptr;
			}
			return length;
		}
	}
};
int main(){
	link_list list;
	list.add(10);
	list.add(20);
	list.add(30);
	list.add(40);
	list.add(50);
	list.add(60);
	list.add(70);
	list.add(80);
	list.add(90);
	list.add(100);
	list.display();
	cout << endl;
	cout << "displaying reverse." <<endl;
	list.reverse();
	list.display();
	return 0;
}
