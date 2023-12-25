#include<iostream>
#include<string>

using namespace std;
class Stack{
	public:
		char word;
		int top;
		int size;
		char *arr;
		
		Stack(int size){
			top = -1;
			this->size = size;
			arr = new char[size];
		}
		
		void push(char val){
			top++;
			arr[top] = val;
		}
		
		char pop(){
			char pop_val = arr[top];
			arr[top] = 0;
			top--;
			return pop_val;
		}
		
};

int main(){
	string original_string;
	int length_of_string;
	cout << "Enter a string: ";
	cin >> original_string;
	length_of_string = original_string.length();

	Stack list(length_of_string);
	for(int i=0; i<length_of_string; i++){
		list.push(original_string[i]);
	}
	for(int i=0; i<length_of_string; i++){
		original_string[i] = list.pop();
	}
	cout << "Reversed String: " << original_string << endl;
	return 0;
}
