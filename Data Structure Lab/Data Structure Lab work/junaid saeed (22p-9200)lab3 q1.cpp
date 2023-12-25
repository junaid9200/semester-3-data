#include<iostream>
using namespace std;

class list
{
	public : 
	char* array;
	int size;   
	
    list(int size) 
	{
        this->size = size;
        this->array = new char[size];
    }
    
    void insert(int position, char ch) 
	{
        if (position >= 0 && position < size)
		{
            array[position] = ch;
        }
    }

    void remove(int position) 
	{
        if (position >= 0 && position < size) 
		{
            for (int i = position; i < size - 1; ++i) 
			{
                array[i] = array[i + 1];
            }
            array[size - 1] = '\0'; 
        }
    }

    ~list() 
	{
        delete[] array;
    }
};

int main()
{
    string sequence="efabir";
    string target ="fariba";
    
     list arrList(sequence.size());
     
    
    
      for (int i = 0; i < sequence.size(); ++i) 
	  {
        arrList.insert(i, sequence[i]);
        }
        cout<<endl;

    cout << "\t\t-->> e f a b i r" << endl;

    int choice;
    int insertCount = 1; 
    
    do {
       
        cout<<endl;
        cout<<"\t\t\t------------------------"<<endl;
        cout<<"\t\t\tChoose an option : "<<endl<<"\t\t\t\1 Insert(1)"<<endl<<"\t\t\t\1 Remove(2)"<<endl<<"\t\t\t\1 quit(3)"<<endl;
        cout<<"\t\t\t------------------------"<<endl;
        cout<<endl;
        cout<<"Enter option (1-3) : ";
        cin >> choice;

        if (choice == 1) 
		{
            int position;
            char character;
            cout<<endl;
            cout << "Enter position(0-5) to insert: ";
            cin >> position;
            cout << "Enter character to insert: ";
            cin >> character;
            arrList.insert(position, character);
            cout << "Character inserted.\n";
            insertCount++; 


            cout << "Updated array: ";
            for (int i = 0; i < sequence.size(); ++i) 
			{
                cout << arrList.array[i] ;
            }
            cout << endl;
            if (string(arrList.array) == target) 
			{
            cout << "Matched Yahuu!" << endl;
                break;
             }
        }
         else if (choice == 2) {
            int position;
            cout << "Enter position(0-5) to remove: ";
            cin >> position;
            arrList.remove(position);
            cout << "Character removed.\n";
            cout << "Updated array: ";
            for (int i = 0; i < sequence.size(); ++i) {
                cout << arrList.array[i] << " ";
            }
            cout << endl;
        }
         else if (choice == 3) 
	     {
	     	cout<<"\t\t\t \1 THE END"<<endl;
            break; 
        } else {
            cout << "Invalid option. Please choose again.\n";
        }
         cout << "Total steps to match: " << insertCount << endl;
    }

   
    while(choice!=3);

    


}

