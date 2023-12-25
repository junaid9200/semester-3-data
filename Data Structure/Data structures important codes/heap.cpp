#include <iostream>
#include <vector>


using namespace std;

class Patient 
{
public:
    string name;
    int urgency;

    Patient(const string& n, int u)
	 {
	 	name=n;
	 	urgency=u;
	 }
};

class MinHeap 
{
private:
    vector<Patient> patients;

    void heapifyUp(int index) 
	{
        int parent = (index - 1) / 2;
        while (index > 0 && patients[parent].urgency > patients[index].urgency) 
		{
            swap(patients[parent], patients[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) 
	{
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < patients.size() && patients[left].urgency < patients[index].urgency)
            smallest = left;

        if (right < patients.size() && patients[right].urgency < patients[smallest].urgency)
            smallest = right;

        if (smallest != index) 
		{
            swap(patients[index], patients[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void scheduleAppointment(const string& name, int urgency) 
	{
        patients.emplace_back(name, urgency);
        heapifyUp(patients.size() - 1);
    }

    void sendNextPatient() 
	{
        if (patients.empty()) 
		{
            cout << "No appointments available." << endl;
            return;
        }

        cout << "Next patient to the doctor: " << patients[0].name << " (Urgency: " << patients[0].urgency << ")" << endl;
        patients[0] = patients.back();
        patients.pop_back();
        heapifyDown(0);
    }

    void updateUrgency(const string& name, int newUrgency) 
	{
        for (int i = 0; i < patients.size(); ++i) 
		{
            if (patients[i].name == name) 
			{
                int oldUrgency = patients[i].urgency;
                patients[i].urgency = newUrgency;

                if (newUrgency < oldUrgency)
                    heapifyUp(i);
                else
                    heapifyDown(i);
                return;
            }
        }
        cout << "Patient not found." << endl;
    }

    void viewAppointments() 
	{
        if (patients.empty()) 
		{
            cout << "No appointments scheduled." << endl;
            return;
        }

        cout << "Appointments:" << endl;
        for (const auto& patient : patients) 
		{
            cout << patient.name << " (Urgency: " << patient.urgency << ")" << endl;
        }
    }
};

int main() 
{
    MinHeap system;

    while (true) 
	{
        cout << "\nOptions:\n1. Schedule Appointment\n2. Send Next Patient to the Doctor\n3. Update Urgency\n4. View Appointments\n5. Exit\nEnter choice: ";
        int choice;
        cin >> choice;

        switch (choice) 
		{
            case 1: 
			{
                string name;
                int urgency;
                cout << "Enter patient's name: ";
                cin >> name;
                cout << "Enter urgency level: ";
                cin >> urgency;
                system.scheduleAppointment(name, urgency);
                break;
            }
            case 2:
               system.sendNextPatient();
                break;
            case 3: 
			{
                string name;
                int newUrgency;
                cout << "Enter patient's name: ";
                cin >> name;
                cout << "Enter new urgency level: ";
                cin >> newUrgency;
                system.updateUrgency(name, newUrgency);
                break;
            }
            case 4:
                system.viewAppointments();
                break;
            case 5:
                cout << "Thanks...." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    }
}

