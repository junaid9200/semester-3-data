#include<iostream>
#include<cstring>
using namespace std;

class Arraylist{
	public:
	char *arr;
	int size_of_string;
	int capacity;
	string arranged = "ahmed";
	string temp;
	Arraylist(int size_of_string , char *ptr){
		this->size_of_string = size_of_string;
		arr = new char[size_of_string];
		for(int i=0; i<size_of_string; i++){
			arr[i] = ptr[i];
		}
		capacity = size_of_string;
	}
	void insert(char character,int index){
		if(index<0 || index>capacity){
			cout<<"Invalid position! Try Again."<<endl;
		}
		else if(size_of_string == capacity) {
            cout << "List is full." << endl;
        }
        else{
        	for (int i=size_of_string; i>index; i--) {
            arr[i] = arr[i - 1];
        	}
        	arr[index] = character;
        	size_of_string++;	
		}
	}
	void remove(int position) {
        if(position<0 || position>=size_of_string) {
            cout<<"Invalid position."<<endl;
        }
        for(int i=position; i<size_of_string-1; i++) {
            arr[i] = arr[i+1];
        }
        size_of_string--;
    }
    
    void check(){
    	string temp(arr);
		if(temp == arranged){
			cout<<"Congrats! Words Matched."<<endl;
			abort();
		}
		else{
			cout<<"Continue Playing..."<<endl;
		}
	}
    
	void display_array(){
		cout<<"Displaying Default random string."<<endl;
		for(int i=0; i<size_of_string; i++){
			cout<<arr[i];
		}
	}
	
};
int main(){
	char random_char[] = "ahdme";
	char arranged_char[] = "ahmed";
	int user_input;
	int size_of_string = strlen(arranged_char);
	Arraylist list(size_of_string,random_char);
	
	list.display_array();
	while(true){
		cout<<"\n\nChoose an option below:"<<endl;
		cout<<"1- Insert"<<endl;
		cout<<"2- Remove"<<endl;
		cout<<"3. Exit\n";
		cout<<"Your Input: ";
		cin>>user_input;
		
		switch(user_input){
			case 1:
				char character_to_insert;
                int position_to_insert;
                cout << "Enter the character to insert: ";
                cin >> character_to_insert;
                cout << "Enter the position to insert: ";
                cin >> position_to_insert;
                list.insert(character_to_insert, position_to_insert);
                list.display_array();
                cout<<"\nChecking..."<<endl;
                list.check();
				break;
			case 2:
				int position_to_remove;
                cout << "Enter the position to remove: ";
                cin >> position_to_remove;
                list.remove(position_to_remove);
                list.display_array();
                cout<<"\nChecking..."<<endl;
                list.check();
				break;
			case 3:
				cout << "Exiting the program.\n";
                return 0;	
			default:
                cout<<"Invalid choice. Please try again.\n";
		}
	}
	
}
