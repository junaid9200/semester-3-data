 #include<iostream>
#include<string>
using namespace std;

struct stack_node{
    char data;
    stack_node* next_ptr;
    stack_node(char data) {
        this->data = data;
        next_ptr = nullptr;
    }
};

class list_node {
public:
    string word;
    list_node* next_ptr;
    list_node(string word) {
        this->word = word;
        next_ptr = nullptr;
    }
};

class link_list {
public:
    list_node* head;
    list_node* current;
    list_node* temp;

    link_list() {
        head = nullptr;
        current = nullptr;
    }

    void add_word(string word) {
        if (head == nullptr) {
            list_node* new_node = new list_node(word);
            head = new_node;
            current = new_node;
        }
        else {
            list_node* new_node = new list_node(word);
            current->next_ptr = new_node;
            current = new_node;
        }
    }

    void reverse_words(){
        current = head;
        while(current != nullptr){
            string reversed_word;
            stack_node* stack_top = nullptr;

            // Push characters into stack
            for(char letter : current->word){
                stack_node* new_node = new stack_node(letter);
                new_node->next_ptr = stack_top;
                stack_top = new_node;
            }

            // Pop characters from stack to reverse the word
            while (stack_top != nullptr) {
                reversed_word += stack_top->data;
                stack_node* temp = stack_top;
                stack_top = stack_top->next_ptr;
                delete temp;
            }

            current->word = reversed_word;
            current = current->next_ptr;
        }
    }

    void display_list() {
        current = head;
        while (current != nullptr) {
            cout << current->word << " ";
            current = current->next_ptr;
        }
    }
    
};

int main() {
	while(true){
		int no_of_words = 0;
		int ken_reply = 0;
    	string user_word;
    	link_list obj_list;
		cout << "Hello Ken, let's help you out with the message!" << endl;
    	cout << "How many words are in the message to work my magic on: ";
    	cin >> no_of_words;
    	for (int i = 0; i < no_of_words; i++) {
        	cout << "Enter the word " << i + 1 << ": ";
        	cin >> user_word;
        	obj_list.add_word(user_word);
    	}

    	cout << "\n\nDisplaying Original Message." << endl;
    	obj_list.display_list();

    	obj_list.reverse_words();

    	cout << "\n\nDecrypted Message: ";
    	obj_list.display_list();
    	cout << endl;
    	cout << "Ken, Now head there and get your treasure !" <<endl;
    	cout << "Your Wizard friend got your back to help ya out." <<endl;
    	cout << "Ken, You got another message?" <<endl;
    	cout << "Press 1 to enter message again." <<endl;
    	cout << "Press 2 to exit." <<endl;
    	cin >> ken_reply;
    	switch(ken_reply){
    		case 1:
    			break;
    		case 2:
    			cout << "Good Job ken you found your treasure !" <<endl;
    			return false;
			default:
				cout << "Invalid-Input." <<endl;	
		}
	}
    return 0;
}


