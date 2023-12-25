#include <iostream>
using namespace std;

class Node {
public:
    string description;
    int priority;
    Node* next_ptr;
    Node* pre_ptr;
    bool completed_flag;
    
    Node(string description, int priority) {
        this->description = description;
        this->priority = priority;
        completed_flag = false; 
        next_ptr = nullptr;    
        pre_ptr = nullptr;     
    }
};

class doubly_linked {
public:
    Node* head = nullptr;
    Node* current = nullptr;

    void Add_Task(){
        string description;
        int priority;
        cout<<"Enter task description: ";
        cin.ignore();
        getline(cin, description);
        cout<<"Select Priority level."<<endl;
        cout<<"1. Top Priority."<<endl;
        cout<<"2. Least Priority."<<endl;
        cout<<"3. Custom."<<endl;
        cout<<"Enter your choice: ";
        cin>>priority;
        Node* new_task = new Node(description, priority);
        
        if(head == nullptr || priority == 1){
            if(head == nullptr){
                head = new_task;
                current = new_task;
            }
            else if(head != nullptr && priority == 1){
                head->pre_ptr = new_task;
                new_task->next_ptr = head;
                head = new_task;
            }
        }
        else if(priority == 2){
            if (head == nullptr) {
                head = new_task;
            }
            else{
                Node* current = head;
                while(current->next_ptr != nullptr){
                    current = current->next_ptr;
                }
                current->next_ptr = new_task;
                new_task->pre_ptr = current;
            }
        }
        else if(priority == 3){
            int custom_level;
            int num_tasks = Task_List_Length();
            if(num_tasks == 0){
                head = new_task;
            }
            else{
                cout<<"Enter custom priority (between 2 and "<<num_tasks + 2 <<"): ";
                cin>>custom_level;
                if(custom_level < 2){
                    custom_level = 2;
                }
                else if(custom_level > num_tasks + 2){
                    custom_level = num_tasks + 2;
                }
                if(custom_level == 2){
                    new_task->next_ptr = head;
                    head = new_task;
                }
                else {
                    Node* temp1 = head;
                    current = head->next_ptr;
                    int current_level = 3;
                    while(current != nullptr && current_level < custom_level){
                        temp1 = current;
                        current = current->next_ptr;
                        current_level++;
                    }
                    temp1->next_ptr = new_task;
                    new_task->next_ptr = current;
                    current->pre_ptr = new_task; 
                }
            }
        }
        cout<<"Task added successfully."<<endl;
    }

    void printlist(){
    	int choice;
    	cout<<"In which order to display task list:"<<endl;
    	cout<<"1. Ascending."<<endl;
    	cout<<"2. Decending."<<endl;
    	cout<<"Your Input: ";
    	cin>>choice;
        if (head == nullptr) {
        cout<<"Task List is empty."<<endl;
    	}
		else{
        cout<<"Task list:"<<endl;
        Node* current;
        if(choice == 1){
            current = head;
            while (current != nullptr) {
                cout << "Task-Description: " << current->description << " ,Completed-Status: " << (current->completed_flag ? "Completed" : "Not Completed") << "." << endl;
                current = current->next_ptr;
            }
        }
		else if(choice == 2){
            current = head;
            while(current->next_ptr != nullptr){
                current = current->next_ptr;
            }
            while(current != nullptr){
                cout<< "Task-Description: "<<current->description<<" ,Completed-Status: "<<(current->completed_flag ? "Completed" : "Not Completed")<<"."<<endl;
                current = current->pre_ptr;
            }
        }
		else{
            cout << "Invalid choice. Please try again." << endl;
        }
    	}
	}

    int Task_List_Length(){
        int length = 0;
        Node* current = head;
        while(current != nullptr){
            length++;
            current = current->next_ptr;
        }
        return length;
    }

    void mark_task(string key){
        current = head;
        while(current != nullptr){
            if(current->description == key){
                current->completed_flag = true;
                cout<<"Description Matched !"<<endl;
                cout<<"Task Completed Status: "<<(current->completed_flag ? "Completed" : "Not Completed")<<endl;
                break;
            }
            if(current->next_ptr == nullptr){
                cout<<"Description Not Matched ! Failed To change status."<<endl;
            }
            current = current->next_ptr;
        }
    }
    
    void remove(){
    current = head;
    while(current != nullptr){
        if(current->completed_flag == true){
            Node* temp_next = current->next_ptr;
            Node* temp_prev = current->pre_ptr;
            if(temp_prev != nullptr){
                temp_prev->next_ptr = temp_next;
            }
            if(temp_next != nullptr){
                temp_next->pre_ptr = temp_prev;
            }
			else{
                head = temp_next;
            }
            delete current;
        }
        current = current->next_ptr;
    }
}

};

int main() {
    int user_input;
    doubly_linked list;
    string key;
    while(true){
        cout<<"Menu."<<endl;
        cout<<"1. Add Task."<<endl;
        cout<<"2. Mark a Task."<<endl;
        cout<<"3. Remove Completed Task."<<endl;
        cout<<"4. Display Tasks."<<endl;
        cout<<"5. Exit."<<endl;
        cout<<"Your Input: ";
        cin>>user_input;
        switch(user_input){
        case 1:
            list.Add_Task();
            break;
        case 2:
            cout<<"Enter the description of task to mark completed: ";
            cin.ignore();
            getline(cin, key);
            list.mark_task(key);
            break;
        case 3:
			list.remove();
            break;
        case 4:
            list.printlist();
            break;
        case 5:
            cout<<"Thanks For Using Our Programme."<<endl;
            return 0; 
        default:
            cout<<"Invalid choice. Please try again."<<endl;
        }
    }
}

