#include <iostream>
#include <vector>
using namespace std;
class Patient{
public:
    string patient_name;
    int urgency;

    Patient(string patient_name, int urgency){
	 	this->patient_name = patient_name;
	 	this->urgency = urgency;
	 }
};

class MinHeap{
private:
    vector<Patient> patients;
    
    void heapifyDown(int index){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if(patients[left].urgency < patients[index].urgency && left < patients.size()){
            smallest = left;
		}
        if(patients[right].urgency < patients[smallest].urgency && patients.size() > right){
            smallest = right;
		}
        if(smallest != index){
            swap(patients[index], patients[smallest]);
            heapifyDown(smallest);
        }
    }
    
    void heapifyUp(int index){
        int parent = (index - 1) / 2;
        while(index > 0 && patients[parent].urgency > patients[index].urgency){
            swap(patients[parent], patients[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }
    
public:
    void scheduleAppointment(const string& name, int urgency){
        patients.emplace_back(name, urgency);
        heapifyUp(patients.size() - 1);
    }

    void sendNextPatient(){
        if(patients.empty()){
            cout << "No Patient Left for Appointments." << endl;
            return;
        }
        cout << "Patient In-line: " << patients[0].patient_name << endl;
		cout << "Urgency Of Patient: " << patients[0].urgency << endl;
        patients[0] = patients.back();
        patients.pop_back();
        heapifyDown(0);
    }

    void updateUrgency(const string& name, int newUrgency){
        for(int i=0; i<patients.size(); ++i){
            if(patients[i].patient_name == name){
                int oldUrgency = patients[i].urgency;
                patients[i].urgency = newUrgency;
                if(newUrgency < oldUrgency){
                    heapifyUp(i);
            	}
                else{
                    heapifyDown(i);
                	return;
            	}
        	}
        cout << "Patient Not Found. Please Try Again." << endl;
    	}
	}
	
    void viewAppointments(){
        if (patients.empty()){
            cout << "No-Appointments For Now." << endl;
            return;
        }
        cout << "Displaying-Appointments:" << endl;
        for (const auto& patient : patients){
            cout << "Name: " << patient.patient_name << endl;
			cout << "Urgency: " << patient.urgency << endl;
        }
    }
};

int main(){
    MinHeap obj;
	string patient_name;
    int urgency;
    int new_urgency; 
    
    while(true){
    	cout << "\n**MENU**" << endl;
        cout << "1. Schedule Appointment." << endl;
		cout << "2. Send Patient For Check-Up." << endl;
		cout << "3. Update Patient's Urgency." << endl;
		cout << "4. View Appointments." << endl;
		cout << "5. Exit." << endl;
		cout << "Your Input: ";
        int user_input;
        cin >> user_input;
        switch(user_input){
            case 1: 
                cout << "Enter Patient's Name: ";
                cin >> patient_name;
                cout << "Enter Urgency Level: ";
                cin >> urgency;
                obj.scheduleAppointment(patient_name, urgency);
                break;
            case 2:
               obj.sendNextPatient();
                break;
            case 3: 
                cout << "Enter Patient's Name: ";
                cin >> patient_name;
                cout << "Enter New Urgency Level: ";
                cin >> new_urgency;
                obj.updateUrgency(patient_name, new_urgency);
                break;
            case 4:
                obj.viewAppointments();
                break;
            case 5:
                cout << "Thanks For Using Our Programe." << endl;
                return 0;
            default:
                cout << "Invalid Input !Please Try Again." << endl;
        }
    }
}
