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

class tree_function{
	public:
	tree_node* root;
	
	tree_function(){
		root = nullptr;
	}	
	
	tree_node* add_data(tree_node* root, int to_add){
		if(root == nullptr){
			return new tree_node(to_add);
		}
		else if(root->data > to_add){
			root->left_ptr = add_data(root->left_ptr, to_add);
		}
		else if(root->data < to_add){
			root->right_ptr = add_data(root->right_ptr, to_add);
		}
		else if(root->data == to_add){
			cout << "Duplicate Exits." <<endl;
		}
		return root;
	}
	
	void display_tree(tree_node* root){
		if(root == nullptr){
			return;
		}
		else{
			display_tree(root->left_ptr);
			cout <<"Data = "<< root->data <<"." <<endl;
			display_tree(root->right_ptr);
		}
	}
	
	void search_data(tree_node* root, int to_search){
		if(root == nullptr){
			cout << "Data not found in tree." <<endl;
			return;
		}
		else{
			if(root->data > to_search){
				search_data(root->left_ptr, to_search);
			}
			else if(root->data < to_search){
				search_data(root->right_ptr, to_search);
			}
			else if(root->data == to_search){
					cout << "Data found in tree." <<endl;
					cout << "Data: " << root->data <<endl;
			}	
		}
	}
	
	tree_node* find_min(tree_node* root){
		while(root->left_ptr != nullptr){
			root = root->left_ptr;
		}
		return root;
	}
	
	tree_node* delete_data(tree_node* root, int key){
		if(root == nullptr){
			cout << "Tree is empty." <<endl;
			return root;
		}
		else{
			if(root->data > key){
				root->left_ptr = delete_data(root->left_ptr, key);
			}
			else if(root->data < key){
				root->right_ptr = delete_data(root->right_ptr, key);
			}
			else{
				if(root->data == key){
					if(root->left_ptr == nullptr){
						tree_node* temp = root->right_ptr;
						delete root;
						return temp;
					}
					else if(root->right_ptr == nullptr){
						tree_node* temp = root->left_ptr;
						delete root;
						return temp;
					}
					else{
						tree_node* temp = find_min(root->right_ptr);
						root->data = temp->data;
						root->right_ptr = delete_data(root->right_ptr , temp->data);
					}
				}
			}
		}
	}	
};

int main(){
	int user_input, user_data = 0, search, to_delete;
	tree_function tree;
	while(true){
		cout << "Menu" <<endl;
		cout << "1. Add Data" <<endl;
		cout << "2. Delete Data" <<endl;
		cout << "3. Search Data" <<endl;
		cout << "4. Display Data" <<endl;
		cout << "5. Exit" <<endl;
		cout << "Your Input: ";
		cin >> user_input;
		switch(user_input){
			case 1:
				cout << "Enter data to add: ";
				cin >> user_data;
				tree.root = tree.add_data(tree.root, user_data);
				break;
			case 2:
				cout << "Enter data to delete: ";
				cin >> to_delete;
				tree.root= tree.delete_data(tree.root, to_delete);
				break;
			case 3:
				cout << "Enter data to search: ";
				cin >> search;
				if(tree.root == nullptr){
					cout << "Tree is empty." <<endl;
					break;
				}
				tree.search_data(tree.root, search);
				break;
			case 4:
				cout << "Displaying Tree Data:" <<endl;
				tree.display_tree(tree.root);
				break;	
			case 5:
				cout << "Thank You !" <<endl;
				return false;
			default:
				cout << "Invalid Input ! Try Again." <<endl;	
		}		
	}
	return 0;
}
