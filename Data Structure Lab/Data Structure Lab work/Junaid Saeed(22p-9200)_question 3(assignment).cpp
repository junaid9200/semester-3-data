#include <iostream>

using namespace std;

class student 
{
public:
    string name;
    int merit;

    student(string n, int m)
    {
    	this->merit=m;
    	this->name=n;
	}
};

class node 
{
public:
    student data;
    node* next;

    node(student s):data(s)
    {
       this->next=nullptr;
	}
};

class queue 
{
private:
    node* front;
    node* rear;

public:
    queue()
    {
    	this->rear=nullptr;
    	this->front=nullptr;
	}

    bool isEmpty() 
	{
        return front == nullptr;
    }

    void enqueue(student s) 
	{
        node* node1 = new node(s);

        if (isEmpty()) 
		{
            front = rear = node1;
        } 
		else 
		{
            rear->next = node1;
            rear = node1;
        }
    }

    student dequeue()
	 {
        if (isEmpty()) 
		{
            cout << "Queue is empty." << endl;
            return student("", 0);
        } 
		else 
		{
            node* temp = front;
            student remove = front->data;
            front = front->next;
            delete temp;
            return remove;
        }
    }

    student getfront() 
	{
        if (isEmpty()) 
		{
            cout << "Queue is empty." << endl;
            return student("", 0);
        } 
		else 
		{
            return front->data;
        }
    }

    void display() 
	{
        node* current = front;
        
        cout << "Queue Status:" << endl;
        while (current != nullptr) 
		{
            cout << "Name: " << current->data.name << ", Merit: " << current->data.merit << endl;
            current = current->next;
        }
        cout << "Number of students in queue: " << count() << endl;
    }

    int count() 
	{
        int count = 0;
        node* current = front;
        while (current != nullptr) 
		{
            count++;
            current = current->next;
        }
        return count;
    }

    ~queue() 
	{
        while (!isEmpty()) 
		{
            dequeue();
        }
    }
};

class admission 
{
private:
    queue queues[3];

public:
    void add(string name, int merit) 
	{
        int shortl = 0;
        int shortlen = queues[0].count();

        for (int i = 1; i < 3; ++i) 
		{
            int currentl = queues[i].count();
            if (currentl < shortl) 
			{
                shortl = i;
                shortlen = currentl;
            }
        }

        queues[shortl].enqueue(student(name, merit));
        cout << name << " added to Queue " << shortl + 1 << endl;
    }

    void process() 
	{
        for (int i = 0; i < 3; ++i) 
		{
            while (!queues[i].isEmpty()) 
			{
                student current = queues[i].getfront();
                queues[i].dequeue();

                if (current.merit > 50)
				 {
                    cout << current.name << " admitted from Queue " << i + 1 << endl;
                } 
				else 
				{
                    cout << current.name << " not admitted from Queue " << i + 1 << endl;
                }
            }
        }
    }

    void check() 
	{
        for (int i = 0; i < 3; ++i) 
		{
            cout << "Queue " << i + 1 << ":" << endl;
            queues[i].display();
            cout << endl;
        }
    }

    void Next(int qn) 
	{
         if (qn >= 1 && qn <= 3) 
		 {
             if (queues[qn - 1].isEmpty()) 
		 {
            cout << "No student in Queue " << qn << "." << endl;
        } 
		else 
		{
            cout << "Next student in Queue " << qn << ": ";
            cout << queues[qn - 1].getfront().name;
        }
        cout << endl;
    }
		else 
		{
            cout << "Invalid queue number." << endl;
        }
    }
};

int main() 
{
     admission a;
    int choice;
    
    cout << "\t\t\t\tUniversity Admission:" << endl;
    do {
        
        cout<<endl;
        cout<<"\t\t\t---------------------------------------"<<endl;
        cout << "\t\t\t1. Add Student to Queue" << endl;
        cout << "\t\t\t2. Process Admissions" << endl;
        cout << "\t\t\t3. Check Queue Status" << endl;
        cout << "\t\t\t4. See who is next (Enter Queue Number)" << endl;
        cout << "\t\t\t5. Exit" << endl;
        cout<<"\t\t\t---------------------------------------"<<endl;
        cout<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1: 
			{
                string name;
                int merit;
                cin.ignore(); 
                cout << "Enter student name: ";
                getline(cin, name);
                cout << "Enter student merit: ";
                cin >> merit;
                a.add(name, merit);
                break;
            }
            case 2:
            	{
                cout << "Processing Admissions..." << endl;
                a.process();
                break;
            }
            case 3:
            	{
                a.check();
                break;
            }
            case 4: 
			{
                int queueNumber;
                cout << "Enter Queue Number (1, 2, or 3): ";
                cin >> queueNumber;
                a.Next(queueNumber);
                break;
            }
            case 5:
            	{
                cout << "Thank you!" << endl;
                break;
				}
            default:
                cout << "Invalid choice." << endl;
        }
    } 
	
	while (choice != 5);

}

