#include<iostream>
#include<string>
using namespace std;

struct tree_node{
    string Name;
	string Designation;
	int ID; 
	int balance_factor;
    tree_node* left_ptr;
    tree_node* right_ptr;

    tree_node(string Name, string Designation, int ID){
        this->Name = Name;
        this->ID = ID;
        this->Designation = Designation;
        left_ptr = nullptr;
        right_ptr = nullptr;
        balance_factor = 0;
    }
};

class tree_function{
public:
    tree_node* root;

    tree_function(){
        root = nullptr;
    }

    int cal_height(tree_node* root){
        if(root == nullptr){
            return -1;
        }
        return max(cal_height(root->left_ptr), cal_height(root->right_ptr)) + 1;
    }

    int cal_balance_factor(tree_node* node){
        if(node == nullptr){
            return 0;
        }
        return cal_height(node->left_ptr) - cal_height(node->right_ptr);
    }

    tree_node* left_rotate(tree_node* root){
        tree_node* temp = root->right_ptr;
        root->right_ptr = temp->left_ptr;
        temp->left_ptr = root;
	    root->balance_factor = cal_balance_factor(root);
        temp->balance_factor = cal_balance_factor(temp);
        return temp;
    }

    tree_node* right_rotate(tree_node* root){
        tree_node* temp2 = root->left_ptr; 
        root->left_ptr = temp2->right_ptr;
        temp2->right_ptr = root;
        temp2->balance_factor = cal_balance_factor(temp2);
        root->balance_factor = cal_balance_factor(root);
        return temp2;
    }

    tree_node* add_data(tree_node* root, string Name, string Designation, int ID){
        if(root == nullptr){
            return new tree_node(Name, Designation, ID);
        }

        if(ID < root->ID){
            root->left_ptr = add_data(root->left_ptr, Name, Designation, ID);
        }
		else if(ID > root->ID){
            root->right_ptr = add_data(root->right_ptr, Name, Designation, ID);
        }
		else{
            cout << "Duplicate exists." << endl;
            return root;
        }

        root->balance_factor = cal_balance_factor(root);

        if(root->balance_factor > 1){
            if(ID < root->left_ptr->ID){
                return right_rotate(root);
            }
			else{
                root->left_ptr = left_rotate(root->left_ptr);
                return right_rotate(root);
            }
        }

        if(root->balance_factor < -1){
            if(ID > root->right_ptr->ID){
                return left_rotate(root);
            }
			else{
                root->right_ptr = right_rotate(root->right_ptr);
                return left_rotate(root);
            }
        }
		cout << endl;      
		cout << "Employee Added Successfully !" <<endl;
		cout << endl;                                                          
        return root;
    }
    
    tree_node* find_min(tree_node* root){
        if(root == nullptr){
            cout << "Data-Base Is Empty !" << endl;
            return nullptr;
        }
        while(root->left_ptr != nullptr){
            root = root->left_ptr;
        }
        return root;
    }

    tree_node* delete_node(tree_node* node, int ID){
        if(node == nullptr){
            cout << "Employee Not Found In Data-Base." << endl;
            return node;
        }

        if(ID < node->ID){
            node->left_ptr = delete_node(node->left_ptr, ID);
        }
		else if(ID > node->ID){
            node->right_ptr = delete_node(node->right_ptr, ID);
        }
		else{
            if(node->left_ptr == nullptr || node->right_ptr == nullptr){
                tree_node* temp = node->left_ptr ? node->left_ptr : node->right_ptr;
                if(temp == nullptr){
                    temp = node;
                    node = nullptr;
                }
				else{
                    *node = *temp;
                }
                delete temp;
            }
			else{
                tree_node* temp = find_min(node->right_ptr);
                node->ID = temp->ID;
                node->right_ptr = delete_node(node->right_ptr, temp->ID);
            }
        }

        if(node == nullptr){
            return node;
        }

        node->balance_factor = cal_balance_factor(node);

        if(node->balance_factor > 1){
            if(cal_balance_factor(node->left_ptr) >= 0){
                return right_rotate(node);
            }
			else{
                node->left_ptr = left_rotate(node->left_ptr);
                return right_rotate(node);
            }
        }

        if(node->balance_factor < -1){
            if(cal_balance_factor(node->right_ptr) <= 0){
                return left_rotate(node);
            }
			else{
                node->right_ptr = right_rotate(node->right_ptr);
                return left_rotate(node);
            }
        }

        return node;
    }

    void display_in_order(tree_node* root){
        if(root == nullptr){
            return;
        }
        display_in_order(root->left_ptr);
        cout << endl;
        cout << "Displaying Employee Details..." <<endl;
        cout << endl;
        cout << "Employee-ID: " << root->ID << endl;
        cout << "Employee-Name: " << root->Name << endl;
        cout << "Employee-Designation: " << root->Designation << endl;
        cout << endl;
        display_in_order(root->right_ptr);
    }

    void search_data(tree_node* root, int ID_to_search) {
        if(root == nullptr){
            cout << "Employee Not Found In Data-Base." << endl;
            return ;
        }
		else{
            if(root->ID > ID_to_search){
                search_data(root->left_ptr, ID_to_search);
            }
			else if(root->ID < ID_to_search){
                search_data(root->right_ptr, ID_to_search);
            }
			else if(root->ID == ID_to_search){
				cout << endl;
                cout << "Data Found In Data-Base." << endl;
                cout << endl;
        		cout << "Displaying Employee Details..." <<endl;
        		cout << endl;
        		cout << "Employee-ID: " << root->ID << endl;
        		cout << "Employee-Name: " << root->Name << endl;
        		cout << "Employee-Designation: " << root->Designation << endl;
                return ;
            }
        }
    }

    
    tree_node* update_data(tree_node* root){
    	int ID_to_update;
    	string Name;
    	string Designation;
    	int ID;
    	cout << "Enter Employee ID To Update Details: ";
    	cin >> ID_to_update;
    	root = delete_node(root, ID_to_update);
    	cout << "Enter The Following Employee Details To Update: ";
    	cout << "Enter Employee Name: ";
    	cin >> Name;
    	cout << "Enter Employee Designation: ";
    	cin >> Designation;
    	cout << "Enter New-ID For Employee: ";
    	cin >> ID;
    	root = add_data(root, Name, Designation, ID);
    	return root;
	}
};

int main(){
    int user_input;
    string Name;
    string Designation;
    int ID;
    tree_function tree;
    while(true){
    	cout << endl;
        cout << "**CCity-Employee-Info-System**" << endl;
        cout << "1. Add New Employee." << endl;
        cout << "2. Search Employee." << endl;
        cout << "3. Generate Organizational Chart." << endl;
        cout << "4. Modify Employee Details VIA ID." << endl;
        cout << "5. Remove Employee From Data-Base." << endl;
        cout << "6. Exit Program." << endl;
        cout << "Your Input: ";
        cin >> user_input;
        switch(user_input){
            case 1:
            	cout << endl;
                cout << "Enter The Following Employee Details." << endl;
    			cout << "Enter Employee Name: ";
    			cin >> Name;
    			cout << "Enter Employee Designation: ";
    			cin >> Designation;
    			cout << "Enter ID For Employee: ";
    			cin >> ID;
                tree.root = tree.add_data(tree.root, Name, Designation, ID);
                break;
            case 2:
            	int ID_to_search;
            	cout << endl;
                cout << "Enter Employee ID To Search: ";
                cin >> ID_to_search;
                tree.search_data(tree.root, ID_to_search);
                break;
            case 3:
                cout << "Displaying Organizational Chart." << endl;
                tree.display_in_order(tree.root);
                break;
            case 4:
                tree.root = tree.update_data(tree.root);
                break;
            case 5:
            	int ID_to_delete;
                cout << "Enter Employee ID To Remove: ";
                cin >> ID_to_delete;
                if (tree.root == nullptr) {
                    cout << "Data-Base Is Empty !" << endl;
                    break;
                }
                tree.delete_node(tree.root, ID_to_delete);
                break;
            case 6:
                cout << "Thanks For Choosing CCity-Employee-Info-System. See You Soon" << endl;
                return 0;
            default:
                cout << "Invalid Input, Please Try Again." << endl;
                break;
        }
    }
    return 0;
}

