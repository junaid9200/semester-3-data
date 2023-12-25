#include <iostream>
#include <vector>
using namespace std;

class Employee 
{
public:
    int employeeID;
    string name;
    float sales;
    float customerSatisfaction;
    float projectCompletion;
    float performanceScore;

    Employee(int employeeID, string name, float customerSatisfaction, float projectCompletion) 
	{
        this->employeeID = employeeID;
        this->name = name;
        this->customerSatisfaction = customerSatisfaction;
        this->projectCompletion = projectCompletion;
    }

    void calculatePerformanceScore() 
	{
        performanceScore = sales+customerSatisfaction+projectCompletion; //formula that you provided mam.
    }
};

class MaxHeap 
{
public:
    vector<Employee> employeeHeap;

    int getParent(int child) 
	{
        return (child - 1) / 2;
    }

    int getLeft(int parent) 
	{
        return 2 * parent + 1;
    }

    int getRight(int parent) 
	{
        return 2 * parent + 2;
    }

    void swap(Employee* a, Employee* b) 
	{
        Employee temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node) 
	{
        while (node > 0 && employeeHeap[node].performanceScore > employeeHeap[getParent(node)].performanceScore) 
		{
            swap(&employeeHeap[node], &employeeHeap[getParent(node)]);
            node = getParent(node);
        }
    }

    void heapifyDown(int node) 
	{
        int left = getLeft(node);
        int right = getRight(node);
        int largest = node;

        if (left < employeeHeap.size() && employeeHeap[left].performanceScore > employeeHeap[largest].performanceScore)
        {
        	 largest = left;
	}
        if (right < employeeHeap.size() && employeeHeap[right].performanceScore > employeeHeap[largest].performanceScore)
        {
        	largest = right;
		}
        if (largest != node) 
		{
            swap(&employeeHeap[node], &employeeHeap[largest]);
            heapifyDown(largest);
        }
    }

    void insertEmployee(Employee emp) 
	{
        employeeHeap.push_back(emp);
        int index = employeeHeap.size() - 1;
        heapifyUp(index);
    }

    void getTopRankingEmployee() 
	{
        if (employeeHeap.empty()) 
		{
            cout << "No Employees." << endl;
        }
        else 
		{
            cout << "Top-ranking Employee : ";
            cout << employeeHeap[0].name << " with Performance Score: " << employeeHeap[0].performanceScore << endl;
        }
    }

    void updatePerformance(int employeeID, float newSales, float newCS, float newPCE) 
	{
        for (int i = 0; i < employeeHeap.size(); ++i) 
		{
            if (employeeHeap[i].employeeID == employeeID) 
			{
                employeeHeap[i].sales = newSales;
                employeeHeap[i].customerSatisfaction = newCS;
                employeeHeap[i].projectCompletion = newPCE;
                employeeHeap[i].calculatePerformanceScore();
                heapifyDown(i);
                heapifyUp(i);
                cout << "Performance updated successfully!" << endl;
                return;
            }
        }
        cout << "Employee with ID " << employeeID << " not found." << endl;
    }

    void displayEmployees() 
	{
        if (employeeHeap.empty()) 
		{
            cout << "No Employees." << endl;
            return;
        }
        else
        {
        	 cout << "Employee Rankings:" << endl;
             for (const Employee& emp : employeeHeap) 
		           {
            cout <<"-->"<< "Employee ID: " << emp.employeeID << ", Name: " << emp.name << ", Performance Score: " << emp.performanceScore << endl;
                   }
        	
		}
       
    }
};

int main() {
    MaxHeap employeeMaxHeap;
   
   cout << "\t\t\t\t----{ Employee Performance Evaluation Program }----" << endl;
    while (true) 
	{
		cout<<endl;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tMenu: "<<endl;
        cout << "\t\t\t1. Enter a new employee details"<<endl;;
        cout << "\t\t\t2. Get the top-ranking employee"<<endl;;
        cout << "\t\t\t3. Update an employee's scores"<<endl;;
        cout << "\t\t\t4. Display employee rankings"<<endl;;
        cout << "\t\t\t5. Exit\n";
        cout << "\t\t\t---------------------------------------" << endl;
        cout<<endl;
        int choice;
        
        cout<<"\t\t--> Your option : ";
        cin >> choice;
        cout<<endl;

        switch (choice) 
		{
        case 1: 
		{
            int id;
            string name;
            float sales, cs, pce;
            cout << "Enter Employee ID: ";
            cin >> id;
            cin.ignore(); // Clear newline character from the buffer
            cout << "Enter Employee Name: ";
            getline(cin, name);
            cout << "Enter Sales (in percentage): ";
            cin >> sales;
            cout << "Enter Customer Satisfaction (in percentage): ";
            cin >> cs;
            cout << "Enter Project Completion Efficiency (in percentage): ";
            cin >> pce;

            Employee newEmployee(id, name, cs, pce);
            newEmployee.calculatePerformanceScore();
            employeeMaxHeap.insertEmployee(newEmployee);
            cout << "Employee added successfully!" << endl;
            break;
        }
        case 2: 
		{
            employeeMaxHeap.getTopRankingEmployee();
            break;
        }
        case 3: 
		{
            int empID;
            float newSales, newCS, newPCE;
            cout << "Enter Employee ID to update scores: ";
            cin >> empID;
            cout << "Enter new Sales (in percentage): ";
            cin >> newSales;
            cout << "Enter new Customer Satisfaction (in percentage): ";
            cin >> newCS;
            cout << "Enter new Project Completion Efficiency (in percentage): ";
            cin >> newPCE;
            employeeMaxHeap.updatePerformance(empID, newSales, newCS, newPCE);
            break;
        }
        case 4: 
		{
            employeeMaxHeap.displayEmployees();
            break;
        }
        case 5:
        	{
        		cout << "Thanks :)" << endl;
                return 0;
        		
			}
        default:
        	{
        		cout << "oops , invalid input , try again ..." << endl;
                break;
			}
        }
    }

}

