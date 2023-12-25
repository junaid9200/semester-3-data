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
	link_list(){
		head = nullptr;
		current = nullptr;
	}
	
	void add(int value){
		node* new_node = new node(value);
		if(head == nullptr){
			head = new_node;
			current = new_node;
			return;
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
		cout << "Display." << endl;
		while(current != nullptr){
			cout << current->data << " ";
			current = current->next_ptr;
		}
	}	
	
	void arrange() {

	}
};
int main(){
	link_list list;
	list.add(17);
	list.add(132);
	list.add(104);
	list.add(17);
	list.add(1);
	list.add(19);
	list.add(11);
	list.add(14);
	list.add(12);
	list.add(10);
	list.add(5);
	list.add(9);
	list.display();
	cout << " junaid bhai arrange these integers in ascending order in link list using pointers :/ "<<endl;
	list.arrange();
	list.display();
}

