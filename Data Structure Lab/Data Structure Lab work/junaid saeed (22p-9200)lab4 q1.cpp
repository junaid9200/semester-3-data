#include <iostream>
#include <string>

using namespace std;

class ToDoList {
private:
    string description;
    bool completed;
    int priority;
    ToDoList* next;
    ToDoList* prev;

    ToDoList* head;
    ToDoList* tail;

public:
    ToDoList() 
	{
		this->head=NULL;
		this->tail=NULL;
	}

    void addTask() 
	{
        string description;
        int priority;

        cout << "Enter task description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter task priority: ";
        cin >> priority;

        ToDoList* newTask = new ToDoList();
        newTask->description = description;
        newTask->priority = priority;
        newTask->completed = false;

        cout << "Where do you want to add the task?\n";
        cout << "1. Add at the head\n";
        cout << "2. Add at the tail\n";
        cout << "3. Add at a specific position\n";
        int choice;
        cin >> choice;

        if (choice == 1) 
		{
            newTask->next = head;
            newTask->prev = nullptr;

            if (head != nullptr) 
			{
                head->prev = newTask;
            }

            head = newTask;
        } 
		else if (choice == 2) 
		{
            newTask->next = nullptr;
            newTask->prev = tail;

            if (tail != nullptr) 
			{
                tail->next = newTask;
            }

            tail = newTask;
        } 
		else if (choice == 3)
		 {
            int position;
            cout << "Enter the position where you want to add the task: ";
            cin >> position;

            ToDoList* current = head;
            int currentPosition = 1;

            while (current != nullptr && currentPosition < position) 
			{
                current = current->next;
                currentPosition++;
            }

            if (currentPosition != position) 
			{
                cout << "Invalid position. Task not added.\n";
                delete newTask;
            } 
			else 
			{
                newTask->next = current;
                newTask->prev = current->prev;

                if (current->prev != nullptr) 
				{
                    current->prev->next = newTask;
                } else {
                    head = newTask;
                }

                current->prev = newTask;
            }
        }
		 else 
		 {
            cout << "Invalid choice. Task not added.\n";
            delete newTask;
        }
    }

    void markAsCompleted() 
	{
        int taskNumber = 1;
        ToDoList* current = head;

        cout << "Tasks:\n";
        while (current != nullptr) 
		{
            cout << taskNumber << ". " << current->description << " (Priority: " << current->priority << ", Completed: " << (current->completed ? "Yes" : "No") << ")\n";
            current = current->next;
            taskNumber++;
        }

        cout << "Enter the task number to mark as completed (0 to cancel): ";
        int choice;
        cin >> choice;

        if (choice >= 1) 
		{
            current = head;
            for (int i = 1; i < choice; i++) 
			{
                current = current->next;
            }
            current->completed = true;
            cout << "Task marked as completed: " << current->description << "\n";
        }
    }

    void removeCompletedTasks() 
	{
        ToDoList* current = head;

        while (current != nullptr) 
		{
            ToDoList* nextTask = current->next;

            if (current->completed) 
			{
                if (current == head) 
				{
                    head = nextTask;
                    if (head != nullptr) 
					{
                        head->prev = nullptr;
                    }
                    delete current;
                    current = nextTask;
                } 
				else if (current == tail) 
				
				{
                    tail = current->prev;
                    if (tail != nullptr) 
					{
                        tail->next = nullptr;
                    }
                    delete current;
                    current = nullptr;
                } 
				
				
				else 
				{
                    current->prev->next = nextTask;
                    nextTask->prev = current->prev;
                    delete current;
                    current = nextTask;
                }
            } 
			else 
			{
                current = nextTask;
            }
        }

        cout << "Completed tasks removed.\n";
    }

    void displayTasks(bool ascendingOrder) 
	{
        cout << "Tasks:\n";

        if (ascendingOrder) 
		{
            ToDoList* current = head;
            while (current != nullptr) 
			{
                cout << "Description: " << current->description << " (Priority: " << current->priority << ", Completed: " << (current->completed ? "Yes" : "No") << ")\n";
                current = current->next;
            }
        } 
		else 
		{
            ToDoList* current = tail;
            while (current != nullptr) 
			{
                cout << "Description: " << current->description << " (Priority: " << current->priority << ", Completed: " << (current->completed ? "Yes" : "No") << ")\n";
                current = current->prev;
            }
        }
    }
};

int main() 
{
    ToDoList todoList;
    int choice = 0;
    cout<<endl;
    cout << "\t\t\t---------- TODO List Manager ----------\n";

    while (choice < 5) 
	
	{
		cout<<endl;
		cout<<"\t\t\t-------------------------------"<<endl;
        cout << "\t\t\tMenu Options:\n";
        cout << "\t\t\t1. Add Task\n";
        cout << "\t\t\t2. Mark Task as Completed\n";
        cout << "\t\t\t3. Remove Completed Tasks\n";
        cout << "\t\t\t4. Display Tasks\n";
        cout << "\t\t\t5. Exit\n";
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<endl;
        cout << "\t\tEnter Option: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
            	cout<<endl;
                todoList.addTask();
                break;
            case 2:
            	cout<<endl;
                todoList.markAsCompleted();
                break;
            case 3:
            	cout<<endl;
                todoList.removeCompletedTasks();
                break;
            case 4:
            	cout<<endl;
                bool ascendingOrder;
                cout << "Display tasks in ascending order? (1 for yes, 0 for no): ";
                cin >> ascendingOrder;
                todoList.displayTasks(ascendingOrder);
                break;
            case 5:
            	cout<<endl;
                cout << "\t\t\t-----------THNKS-------------";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

