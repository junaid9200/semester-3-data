#include<iostream>
using namespace std;

struct employe 
{
    int ID;
    string name;
    string designation;

    employe(int id, string n, string desig) 
    {
    	this->ID=id;
    	this->name=n;
    	this->designation=desig;
	}
};

struct node 
{
    employe data;
    node* left;
    node* right;

    node(employe emp) : data(emp)
    {
    	this->left=nullptr;
    	this->right=nullptr;
	}
};

class avl 
{
public:
	
    int height(node* root) 
	{
        if (root == nullptr) 
		{
            return 0;
        } 
		else 
		{
            int left = height(root->left);
            int right = height(root->right);
            return 1 + max(left, right);
        }
    }

    int balancefactor(node* root) 
	{
        if (root == nullptr) 
		{
            return 0;
        } 
		else
		 {
            return height(root->left) - height(root->right);
        }
    }

    node* rightrotate(node* root) 
	{
        node* newRoot = root->left;
        node* temp = newRoot->right;

        newRoot->right = root;
        root->left = temp;

        return newRoot;
    }

    node* leftrotate(node* root) 
	{
        node* newRoot = root->right;
        node* temp = newRoot->left;

        newRoot->left = root;
        root->right = temp;

        return newRoot;
    }

    node* insert(node* root, employe emp) 
	{
        if (root == nullptr) 
		{
            return new node(emp);
        } 
		else 
		{
            if (emp.ID == root->data.ID) 
			{
                cout << "Duplicates exist, element cannot be inserted." << endl;
                return root;
            } 
			else if (emp.ID < root->data.ID) 
			{
                root->left = insert(root->left, emp);
            } 
			else 
			{
                root->right = insert(root->right, emp);
            }

            int balance = balancefactor(root);

            if (balance > 1 && emp.ID < root->left->data.ID) 
			{
                return rightrotate(root);
            } 
			else if (balance < -1 && emp.ID > root->right->data.ID) 
			{
                return leftrotate(root);
            } 
			else if (balance > 1 && emp.ID > root->left->data.ID) 
			{
                root->left = leftrotate(root->left);
                return rightrotate(root);
            } 
			else if (balance < -1 && emp.ID < root->right->data.ID) 
			{
                root->right = rightrotate(root->right);
                return leftrotate(root);
            }

            return root;
        }
    }

    node* minValue(node* root) 
	{
        node* current = root;
        while (current->left != nullptr) 
		{
            current = current->left;
        }
        return current;
    }

    node* del(node* root, int ID) 
	{
        if (root == nullptr) 
		{
            return root;
        }

        if (ID < root->data.ID) 
		{
            root->left = del(root->left, ID);
        } else if (ID > root->data.ID) 
		{
            root->right = del(root->right, ID);
        } 
		else
		 {
            if (root->left == nullptr || root->right == nullptr) 
			{
               node* temp;
                    if (root->left != nullptr) 
					{
                          temp = root->left;
                      } 
					else 
					{
                        temp = root->right;
                      }

                if (temp == nullptr) 
				{
                    temp = root;
                    root = nullptr;
                } 
				else 
				{
                    *root = *temp;
                }
                delete temp;
            } 
			else 
			{
                node* temp = minValue(root->right);
                root->data = temp->data;
                root->right = del(root->right, temp->data.ID);
            }
        }

        if (root == nullptr) 
		{
            return root;
        }

        int balance = balancefactor(root);

        if (balance > 1 && balancefactor(root->left) >= 0) 
		{
            return rightrotate(root);
        } 
		else if (balance > 1 && balancefactor(root->left) < 0) 
		{
            root->left = leftrotate(root->left);
            return rightrotate(root);
        }
		 else if (balance < -1 && balancefactor(root->right) <= 0) 
		{
            return leftrotate(root);
        }
		 else if (balance < -1 && balancefactor(root->right) > 0) 
		{
            root->right = rightrotate(root->right);
            return leftrotate(root);
        }

        return root;
    }

    node* search(node* root, int ID) 
	{
        if (root == nullptr || root->data.ID == ID) 
		{
            return root;
        }

        if (root->data.ID < ID) 
		{
            return search(root->right, ID);
        }

        return search(root->left, ID);
    }

     void display(node* root) 
	 {
        if (root == nullptr) 
		{
            return;
        }

       
        display(root->left);
        
        cout << "ID: " << root->data.ID << ", Name: " << root->data.name
             << ", Designation: " << root->data.designation << endl;

        display(root->right);
    }
    
     node* modify(node* root, int ID, const string& newName, const string& newDesignation) 
	 {
        node* employee = search(root, ID);
        if (employee != nullptr) 
		{
            employee->data.name = newName;
            employee->data.designation = newDesignation;
            cout << "Employee information updated successfully." << endl;
        } 
		else 
		{
            cout << "Employee not found." << endl;
        }
        return root;
    }
};

int main() 
{
    avl tree;
    node* root = nullptr;
    int option;

	cout<<"\t\t\tOrganizational Hierarchy Management"<<endl;
    do 
	{
    	cout<<endl;
        cout << "\t\t\t-----------------------" << endl;
        cout << "\t\t\t1. Add Employee" << endl;
        cout << "\t\t\t2. Search for Employee" << endl;
        cout << "\t\t\t3. Generate Organizational Chart" << endl;
        cout << "\t\t\t4. Modify Employee Information" << endl;
        cout << "\t\t\t5. Remove Employee" << endl;
        cout << "\t\t\t6. Exit" << endl;
        cout << "\t\t\t-----------------------" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> option;
        cout<<endl;

        switch (option) 
		{
            case 1: 
			{
                int id;
                string name, designation;
                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter employee name: ";
                cin >> name;
                cout << "Enter employee designation: ";
                cin >> designation;
                root = tree.insert(root, employe(id, name, designation));
                cout << "Employee added successfully." << endl;
                break;
            }
            case 2: 
			{
                int id;
                cout << "Enter employee ID to search: ";
                cin >> id;
                node* result = tree.search(root, id);
                if (result != nullptr) 
				{
                    cout << "Employee found" << endl;
                    cout << "ID: " << result->data.ID << ", Name: " << result->data.name
                         << ", Designation: " << result->data.designation << endl;
                } 
				else 
				{
                    cout << "Employee not found." << endl;
                }
                break;
            }
            case 3:
            	{
				
                tree.display(root);
                break;
            }
            case 4: 
			{
                int id;
                string newName, newDesignation;
                cout << "Enter employee ID to modify: ";
                cin >> id;
                cout << "Enter new name: ";
                cin >> newName;
                cout << "Enter new designation: ";
                cin >> newDesignation;
                root = tree.modify(root, id, newName, newDesignation);
                break;
            }
            case 5: 
			{
                int id;
                cout << "Enter employee ID to remove: ";
                cin >> id;
                root = tree.del(root, id);
                cout << "Employee removed successfully." << endl;
                break;
            }
            case 6:
                cout << " Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    while (option!=6);
   
}

