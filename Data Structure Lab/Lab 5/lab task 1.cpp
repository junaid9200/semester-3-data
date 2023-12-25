#include<iostream>
using namespace std;
class Stack{
	public:
	int top;
	int *arr;

	Stack(){
		top=-1;
		arr=new int[2];
	}

	void push(int val){
			top++;
			arr[top] = val;
			cout<<"Element: "<<val<<" is pushed"<<endl;
		}
		
	int pop(){
			int pop_val = arr[top];
			arr[top] = 0;
			top--;
			return pop_val;
	}
};

int main(){
	Stack list;
	int number_a;
	int number_b;
	cout << "Enter first number: ";
	cin >> number_a;
	list.push(number_a);
	cout << "Enter second number: ";
	cin >> number_b;
	list.push(number_b);
	cout << "\nAfter Swaping." << endl;
	number_a = list.pop();
	number_b = list.pop();
	cout << "First Number: " << number_a << endl;
	cout << "Second Number: " << number_b <<endl;
	return 0;
}
