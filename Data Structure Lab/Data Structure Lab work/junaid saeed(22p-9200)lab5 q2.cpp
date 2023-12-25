
#include<iostream>
using namespace std;

class stack
{
	private:
		
    int size;
    int top;
    char* arr;
	
	public:
	  
	  stack (int size)
	  {
	  	top=-1;
	  	this->size=size;
	  	arr=new char(size);
	  }
	  
	  void push(char value)
	  {
	  	 if (top < size - 1) 
		   {
            arr[++top] = value;
        } 
		else 
		{
            cout << "Stack overflow!" << endl;
        }
    }
	  
	  char pop()
	  {
	  	 if (top >= 0) 
		   {
            return arr[top--];
        } 
		else 
		{
            cout << "Stack underflow!" << endl;
        }
    }

    bool isEmpty() 
	{
        return top == -1;
    }
    
};

string reverseStringUsingStack(string& input) 
{
    int length = input.length();
    stack s(length);

    for (int i = 0; i < length; i++) 
	{
        s.push(input[i]);
    }

    string reversedString = "";
    while (!s.isEmpty()) 
	{
        reversedString += s.pop();
    }

    return reversedString;
}




int main()
{
    string orignal;
    cout << "Enter a string: ";
    cin >> orignal;

    string reversedString = reverseStringUsingStack(orignal);
    cout << "Reversed string: " << reversedString << endl;

     

}

