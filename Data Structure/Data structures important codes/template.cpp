#include<iostream>
using namespace std;



int main()
{
	int choice;
      cout << "\t\t\t\t{ Book Management System Menu }" << endl;
    do 
	{
        cout<<endl;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\t1. Add a New Book" << endl;
        cout << "\t\t\t2. Search for a Book" << endl;
        cout << "\t\t\t3. Display Books" << endl;
        cout << "\t\t\t4. Filter Books by Author" << endl;
        cout << "\t\t\t5. Recommend Related Books" << endl;
        cout << "\t\t\t6. Delete a Book" << endl;
        cout << "\t\t\t7. Exit" << endl;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) 
		{
            case 1: 
			{
               
                break;
            }
            case 2: 
			{
                
                break;
            }
            case 3: 
			{
                
                break;
            }
            case 4: 
			{
               
                break;
            }
            case 5: 
			{
                
                break;
            }
            case 6: 
			{
                
                break;
            }
            case 7:
            	{
            	  cout << "Thank you!" << endl;
                  break;
				}
               
            default:
            	{
            		cout << "Invalid choice." << endl;
				}
                
        }
    } 
	while (choice != 7);


}

