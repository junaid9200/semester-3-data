#include<iostream>
using namespace std;
struct tree_node{
	int data;
	tree_node* left_ptr;
	tree_node* right_ptr;
	
	tree_node(int data){
		this->data = data;
		left_ptr = nullptr;
		right_ptr = nullptr;
	}
};

class binary_tree{
	public:
	tree_node* root;
	
	binary_tree(){
		root = nullptr;
	}
	
	tree_node* add_data(tree_node *root, int data){
		if(root == nullptr){
			return new tree_node(data);
		}
		else if(root->data > data){
			root->left_ptr = add_data(root->left_ptr,data);
		}
		else if(root->data < data){
			root->right_ptr = add_data(root->right_ptr,data);
		}
		else if(root->data == data){
			cout << "duplicate data exists already." << endl;
		}
		return root;
	}
	
	tree_node* find_min(tree_node* node){
        while(node->left_ptr != nullptr){
            node = node->left_ptr;
        }
        return node;
    }
	
	tree_node* delete_data(tree_node* root, int data){
        if(root == nullptr){
        	cout << "Tree is Empty." <<endl;
            return root;
        }
        if(data < root->data){
            root->left_ptr = delete_data(root->left_ptr, data);
        }
		else if(data > root->data){
            root->right_ptr = delete_data(root->right_ptr, data);
        }
		else{// when root data == key
            if(root->left_ptr == nullptr){
                tree_node* temp = root->right_ptr;
                delete root;
                return temp;
            } else if(root->right_ptr == nullptr){
                tree_node* temp = root->left_ptr;
                delete root;
                return temp;
            }
            tree_node* temp = find_min(root->right_ptr);
            root->data = temp->data;
            root->right_ptr = delete_data(root->right_ptr, temp->data);
        }
        return root;
    }
	
	bool search_data(tree_node* root, int data){
        if(root == nullptr){
            return false;
        }
        if(root->data == data){
            return true;
        }
		else if(data < root->data){
            return search_data(root->left_ptr, data);
        }
		else{
            return search_data(root->right_ptr, data);
        }
    }
	
	void display_in_order(tree_node* root){
        if(root == nullptr){
            return;
        }
        display_in_order(root->left_ptr);
        cout << root->data << " ";
        display_in_order(root->right_ptr);
    }	
};
int main(){
	int user_input;
	int data;
	binary_tree tree;
	while(true){
		cout << "\n----" <<endl;
		cout << "Menu" <<endl;
		cout << "----" <<endl;
		cout << "1- Add data." <<endl;
		cout << "2- Delete data." <<endl;
		cout << "3- Search Data." <<endl;
		cout << "4- Display tree (In-Order)." <<endl;
		cout << "5- Exit." <<endl;
		cout << "Your Input: ";
		cin >> user_input;
		switch(user_input){
			case 1:
				cout << "Enter data to add: ";
				cin >> data;
				tree.root = tree.add_data(tree.root,data);
				break;
			case 2:
				cout << "Enter data to delete: ";
                cin >> data;
                tree.root = tree.delete_data(tree.root, data);
				break;
			case 3:
				cout << "Enter data to search: ";
                cin >> data;
                if (tree.search_data(tree.root, data)) {
                    cout << "Data found in the tree." << endl;
                } else {
                    cout << "Data not found in the tree." << endl;
                }
				break;
			case 4:
				cout << "Displaying data:" << endl;
				tree.display_in_order(tree.root);
				break;	
			case 5:
				cout << "Thank You." <<endl;
				return false;
			default:
				cout << "You have entered Invalid input." <<endl;	
		}	
	}
	return 0;
}
