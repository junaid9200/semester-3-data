#include<iostream>
#include<string>

using namespace std;

class Node{
	public:
	char data;
	Node* next_node;

	Node(char data){
		this->data = data;
		next_node = nullptr;
	}
	
};

class stack_list{
	public:
	Node* top;
	Node* temp;
	
	stack_list(){
		top = nullptr;
		temp = nullptr;
	}
	
	void push(char data){
		Node* new_node = new Node(data);
		if(top == nullptr){
			top = new_node;
		}
		else{
			temp = top;
			top = new_node;
			new_node->next_node = temp;
		}
	}
	
	char pop(){
		if(top == nullptr){
			cout << "Stack is empty !" << endl;
			return '\O';
		}
		
		char pop_val;
		pop_val = top->data;
		temp = top;
		top = top->next_node;
		delete temp;
		temp = nullptr;
		
		return pop_val;
	}
	
	void display() {
    	temp = top;
    	string output;
    	while (temp != nullptr) {
        	output = temp->data + output; // Prepend the character to the output string
        	temp = temp->next_node;
    	}
    	cout << output << endl;
	}
};
int main(){
	string original_string;
	int length_of_string;
	stack_list list;
	stack_list list1;
	cout << "Enter a string: ";
	cin >> original_string;
	length_of_string = original_string.length();
	
	for(int i=0; i<length_of_string; i++){
		list.push(original_string[i]);
	}
	
	int user_input;
	while(true){
		cout << "Menu" << endl;
		cout << "1) Undo" << endl;
		cout << "2) Redo" << endl;
		cout << "3) Exit" << endl;
		cout << "Your Input: ";
		cin >> user_input;
		switch(user_input){
			case 1:
				char popped;
				popped = list.pop();
				if (popped != '\O'){
					list1.push(popped);
					list.display();
				}
				break;
			case 2:
				char push_back;
				push_back = list1.pop();
				if(push_back != '\O'){
					list.push(push_back);
					list.display();
				}
				break;
			case 3:
				cout << "Thanks For Using Programe." << endl;
				return 0;				
			default:
				cout << "Invalid Input ! Please Try Again." << endl;	
		}
	}
}
