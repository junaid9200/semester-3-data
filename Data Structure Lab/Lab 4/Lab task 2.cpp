#include<iostream>
using namespace std;
class Node{
	public:
	string name;
	Node* next;
	
	Node(string name){
		this->name = name;
		next = nullptr;
	}	
};

class circular_list{
	public:
	Node* head;
	Node* current;
	Node* start;
	
	circular_list(){
		head = nullptr;
		current = nullptr;
		start = nullptr;
	}
	
	void Add_Node(int player_no){
		string name;
		cout<<"Enter Name Of Player no "<<player_no + 1<<": ";
		cin>>name;
		Node* new_player = new Node(name);
		if(head == nullptr){
			head = new_player;
			current = new_player;
			start = new_player;
			current->next = head;	
		}
		else{
			current->next = new_player;
			new_player->next = head;
			current = new_player;
		}
	}
	
	void simulation(){
		int round = 0;
		current = start;
		Node* pre_ptr = start;
		while(round < 6){
			pre_ptr = current;
			current = current->next;
			round++;
		}
		pre_ptr->next = current->next;
		if(current == start){
            if(current->next == current){
                start = nullptr;
            }
            else{
                start = current->next;
            }
        }
		delete current;
	}
	
	void display(){
		current = start;
		Node* winner = nullptr;
		int number = 1;
		do{
        	cout<<"Name Of Player "<<number<<": "<<current->name<<endl;
            number++;
            winner = current;
            current = current->next;
        }
		while(current != start);
		if(number == 2){
			cout<<"\nCongratulations !!!"<<endl;
			cout<<"Winner Is "<<winner->name<<endl;
			abort();
		}
	}
};
int main(){
	circular_list list;
	int user_input;
	cout<<"Enter Names Of 5 Players."<<endl;
		for(int i=0; i<5; i++){
			list.Add_Node(i);
		}
	while(true){
		cout<<"Menu Of Game."<<endl;
		cout<<"Press 1 To Play Simulation."<<endl;
		cin>>user_input;
		switch(user_input){
			case 1:
				list.display();
				list.simulation();
				break;
			default:
				cout<<"You have entered Invalid Input ! Try Again."<<endl;
		}
	}
	return 0;
}
