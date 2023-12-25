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
	
	void arrange(){
		current = head;
		if(head == nullptr){
			return ;
		}
		else{
			while(current != nullptr){
				node* temp = current->next_ptr;
				while(temp != nullptr){
					if(current->data > temp->data){
						int temp_data = current->data;
						current->data = temp->data;
						temp->data = temp_data;
					}
					temp = temp->next_ptr;
				}
				current = current->next_ptr;
			}
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
	
	void middle(){
		current = head;
		if(head == nullptr){
			return ;
		}
		else{
			node* slow_ptr;
			node* fast_ptr;
			slow_ptr = current;
			fast_ptr = current;
			while(fast_ptr != nullptr && fast_ptr->next_ptr != nullptr){
				slow_ptr = slow_ptr->next_ptr;
				fast_ptr = fast_ptr->next_ptr->next_ptr;
			}
			cout << slow_ptr->data <<endl;
		}
	}
	
bool Is_palindrome() {
    if (!head || !head->next_ptr) {
        // An empty list or a list with a single element is a palindrome.
        return true;
    }

    // Find the middle of the linked list using slow and fast pointers.
    node* slow_ptr = head;
    node* fast_ptr = head;
    while (fast_ptr != nullptr && fast_ptr->next_ptr != nullptr) {
        slow_ptr = slow_ptr->next_ptr;
        fast_ptr = fast_ptr->next_ptr->next_ptr;
    }

    // Reverse the second half of the linked list.
    node* second_half = slow_ptr;
    node* prev = nullptr;
    node* current = second_half;
    node* next = nullptr;

    while (current != nullptr) {
        next = current->next_ptr;
        current->next_ptr = prev;
        prev = current;
        current = next;
    }

    // Compare the first half with the reversed second half.
    node* first_half = head;
    while (first_half != nullptr && prev != nullptr) {
        if (first_half->data != prev->data) {
            return false; // Not a palindrome.
        }
        first_half = first_half->next_ptr;
        prev = prev->next_ptr;
    }

    return true; // It's a palindrome.
}


};
int main(){
	link_list list;
	list.add(10);
	list.add(20);
	list.add(30);
	list.add(40);
	list.add(50);
	list.add(40);
	list.add(30);
	list.add(20);
	list.add(10);
	cout << "Original." <<endl;
	list.display();
	cout << endl;
	cout << endl;
	cout << "Arrange." <<endl;
	list.arrange();
	list.display();
	cout << endl;
	cout << endl;
	cout << "Reverse." <<endl;
	list.reverse();
	list.display();
	cout << endl;
	cout << endl;
	cout << "Middle.";
	list.middle();
	cout << endl;
	cout << endl;
	cout << "Palindrome." <<endl;
	cout << list.Is_palindrome();
	return 0;
}
