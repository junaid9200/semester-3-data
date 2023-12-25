#include<iostream>
using namespace std;

struct tree_node{
	int power;
	string gem_name;
	tree_node* left_ptr;
	tree_node* right_ptr;
	
	tree_node(int power, string gem_name){
		this->power = power;
		this->gem_name = gem_name;
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
	
	tree_node* add_data(tree_node *root, int power, string gem_name){
		if(root == nullptr){
			return new tree_node(power, gem_name);
		}
		else if(root->power > power){
			root->left_ptr = add_data(root->left_ptr,power, gem_name);
		}
		else if(root->power < power){
			root->right_ptr = add_data(root->right_ptr,power, gem_name);
		}
		else if(root->power == power){
			cout << "duplicate data exists already." << endl;
		}
		return root;
	}
	
	bool display(tree_node* root){
		if(root == nullptr){
			cout << "No-tree data exist." <<endl;
            return 0;
        }
        else{
        	int user_input;
			while(true){
				cout << "\nDisplaying BST:" <<endl;
				cout << "Select an option below:" << endl;
				cout << "1. Display in pre-order." << endl;
				cout << "2. Display in post-order." << endl;
				cout << "3. Display in in-order." << endl;
				cout << "Your Input:" ;
				cin >> user_input;
				switch(user_input){
					case 1:
						cout << "\nDisplaying in pre-order:\n" << endl;
						display_pre_order(root);
						return true;
					case 2:
						cout << "\nDisplaying in post-order:\n" << endl;
						display_post_order(root);
						return true;
					case 3:
						cout << "\nDisplaying in in-order:\n" << endl;
						display_in_order(root);
						return true;
					default:
						cout << "Invalid Input ! Please try again." <<endl;	
				}	
			}
    	}
	}
	
	void display_in_order(tree_node* root){
		if(root == nullptr){
			return;
		}
        display_in_order(root->left_ptr);
        cout << root->power << " " << root->gem_name <<endl;
        display_in_order(root->right_ptr);
    }
    
    void display_pre_order(tree_node* root){
    	if(root == nullptr){
			return;
		}
    	cout << root->power << " " << root->gem_name <<endl;
        display_pre_order(root->left_ptr);
        display_pre_order(root->right_ptr);
    }
	
	void display_post_order(tree_node* root){
		if(root == nullptr){
			return;
		}
		display_post_order(root->left_ptr);
		display_post_order(root->right_ptr);
    	cout << root->power << " " << root->gem_name <<endl;   
    }
	
	bool search_data(tree_node* root, int power){
        if(root == nullptr){
            return false;
        }
        if(root->power == power){
        	cout << "Gem found in tree !" <<endl;
        	cout << root->gem_name;
        	cout << "\nProceeding ahead..." <<endl;
            return true;
        }
		else if(power < root->power){
            return search_data(root->left_ptr, power);
        }
		else{
            return search_data(root->right_ptr, power);
        }
    }
	
	void find_highest(tree_node* root){
		if(root == nullptr){
			cout << "\nTree is Empty. " << endl;
		}
        if(root->right_ptr != nullptr){
        	find_highest(root->right_ptr);
		}
        if(root->right_ptr == nullptr){
			cout << "\nHighest power of gem: " << endl;
			cout << "Name: " << root->gem_name <<endl;
			cout << "Power: " << root->power << endl;
		}
	}
	
	tree_node* find_min(tree_node* node){
        while(node->left_ptr != nullptr){
            node = node->left_ptr;
        }
        return node;
    }
	
	tree_node* delete_data(tree_node* root, int data){
        if(root == nullptr){
        	cout << "\nTree is empty." <<endl;
            return root;
        }
        if(data < root->power){
            root->left_ptr = delete_data(root->left_ptr, data);
        }
		else if(data > root->power){
            root->right_ptr = delete_data(root->right_ptr, data);
        }
		else{
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
            root->power = temp->power;
            root->right_ptr = delete_data(root->right_ptr, temp->power);
        }
        return root;
    }
	
	~binary_tree(){
		destroyTree(root);
	}
	
	void destroyTree(tree_node* root){
		if (root == NULL) {
			return;
		}
		destroyTree(root->left_ptr);
		destroyTree(root->right_ptr);
		delete root;
	}	
};

int main(){
	int user_input, bag_limit, magic_pwr_player = 0;
	binary_tree tree;
	cout << "Welcome to the magical forest." << endl;
	cout << "\nHow much magical power can your bag hold?" <<endl;
	cout << "Your Input: ";
	cin >> bag_limit;
	
	tree.root = tree.add_data(tree.root, 50 ,"Diamond");
	tree.root = tree.add_data(tree.root, 30 ,"Ruby");
	tree.root = tree.add_data(tree.root, 70 ,"Sapphire");
	tree.root = tree.add_data(tree.root, 40 ,"Pearl");
	tree.root = tree.add_data(tree.root, 10 ,"Opal");
	tree.root = tree.add_data(tree.root, 60 ,"Garnet");
	tree.root = tree.add_data(tree.root, 20 ,"Zircon");
	tree.root = tree.add_data(tree.root, 5 ,"Jade");
	while(true){
		cout << "\nSelect an option:" <<endl;
		cout << "1. Display the magical tree." <<endl;
		cout << "2. Search for a gem by specifying its power." <<endl;
		cout << "3. Find the gem with the highest magical power." <<endl;
		cout << "4. Pluck a gem from the tree." <<endl;
		cout << "5. Exit Game." <<endl;
		cout << "Your Input: ";
		cin >> user_input;
		switch(user_input){
			case 1:
				tree.display(tree.root);
				break;
			case 2:
				int power;
				cout << "Enter the power of gem to search: ";
				cin >> power;
				tree.search_data(tree.root, power);
				break;
			case 3:
				tree.find_highest(tree.root);
				break;
			case 4:
				cout << "\nDisplaying Magical-tree:" << endl;
				tree.display_in_order(tree.root);
				int power_to_delete;
				cout << "Enter the power of gem to pluck: ";
				cin >> power_to_delete;
				if(!tree.search_data(tree.root, power_to_delete)){
					cout << "\nGem not found in tree." << endl;
				}
				else{
					tree.root = tree.delete_data(tree.root, power_to_delete);
					magic_pwr_player = magic_pwr_player + power_to_delete;
					if(magic_pwr_player == bag_limit){
						cout << "You won! Now take your bag and run from the forest !" << endl;
						return false;
					}
					if(magic_pwr_player > bag_limit){
						cout << "You lost! You bag burst. Now run a save yourself from the witch." << endl;
						return false;
					}
				} 
				break;
			case 5:
				cout << "Hope you had fun !" <<endl;
				return false;
			default:
				cout << "Invalid Input ! please try again." <<endl;	
		}
	}
}
