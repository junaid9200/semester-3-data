#include <iostream>
using namespace std;

class tree_node{
	public:
		int data;
		tree_node* left_ptr;
		tree_node* right_ptr;
		bool right_thread;
		bool left_thread;
		
		tree_node(int data) {
			this->data = data;
			left_ptr = nullptr;
			right_ptr = nullptr;
			right_thread = true;
			left_thread = true;
		}
};

class tree_function{
	public:
		tree_node* root;
		
		tree_function(){
			root = nullptr;
		}
		
		int findMax(){
			if(root == nullptr){
				cout << "Tree Is Empty." <<endl;
				return 0;
			}
			tree_node* current_ptr = root;
			while(current_ptr->right_thread == false){
				current_ptr = current_ptr->right_ptr;
			}
			return current_ptr->data;			
		}
		
		int findMin(){

			if(root == nullptr){
				cout << "Tree Is Empty." <<endl;
				return 0;
			}
			tree_node* current_ptr = root;
			while(current_ptr->left_thread == false){
				current_ptr = current_ptr->left_ptr;
			}
			return current_ptr->data;
		}
		
		int search(int to_search){
    		if (root == nullptr){
        		return 0;
    		} 
			else{
      			tree_node* temp = root;
      			while(temp != nullptr){
        			if (to_search == temp->data){
          				return temp->data;
        			}
					else if(to_search < temp->data){
          				temp = temp->left_ptr;
        			}
					else{
          				temp = temp->right_ptr;
        			}
      			}
      			return 0;
    		}
  		}

		void insert(tree_node*& root, int data){
			tree_node* new_node = new tree_node(data);
			
			if(root == nullptr){
				tree_node* dummy_node = new tree_node(-1);
				dummy_node->right_ptr = dummy_node;
				dummy_node->left_ptr = new_node;
				dummy_node->left_thread = true; 
				dummy_node->right_thread = true;
				root = new_node;
			}
			else{
				tree_node* current_ptr = root;
				
				while(true){
					if(current_ptr->data < data){
						if(current_ptr->right_thread != true){
							current_ptr = current_ptr->right_ptr;
						}
						else{
							new_node->left_ptr = current_ptr;
                    		new_node->right_ptr = current_ptr->right_ptr;
                    		current_ptr->right_ptr = new_node;
                    		current_ptr->right_thread = false;
                    		return ;
						}
					}
					else if(current_ptr->data > data){
    					if(current_ptr->left_thread != true){
        					current_ptr = current_ptr->left_ptr;
    					}
    					else{
        					new_node->left_ptr = current_ptr->left_ptr;
        					new_node->right_ptr = current_ptr;
        					current_ptr->left_ptr = new_node;
        					current_ptr->left_thread = false; 
        					return;
    					}
					}
					else{
						cout << "Duplicates Exits..." <<endl;
						return;
					}	
				}
			}
		}

		int findNextInorderSuccessor(tree_node* node){
			tree_node* current_ptr = node;
			if(current_ptr->right_thread){
				return current_ptr->right_ptr->data;
			}
			else{
				current_ptr = current_ptr->right_ptr;
				while(!current_ptr->left_thread){
					current_ptr = current_ptr->left_ptr;
				}
				return current_ptr->data;
			}
			 
		}
		
		tree_node* inOrderSuccessor(tree_node* node){
			tree_node* current_ptr = node;
			if(current_ptr->right_thread){
				return current_ptr->right_ptr;
			}
			else{
				current_ptr = current_ptr->right_ptr;
				while(!current_ptr->left_thread){
					current_ptr = current_ptr->left_ptr;
				}
				return current_ptr;
			}
			 
		}
		
		tree_node* find_min_node(){
			tree_node* current = root;
        	while (current != nullptr && !current->left_thread) {
            	current = current->left_ptr;
        	}
        	return current;
		}

		void inorder(tree_node* root){
    		tree_node* current = find_min_node();
    		while(current != nullptr){
            	cout << current->data << " ";
            	current = inOrderSuccessor(current);
        	}
        	cout << endl;
		}
		
		 void delete_node(int to_delete){
        	root = deleteRec(root, to_delete);
    	}

    	tree_node* deleteRec(tree_node* root, int value) {
        	if (root == 0){
            	cout << "Value Not Found In Tree."<<endl;
            	return root;
        	}
        	if(value < root->data){
            	root->left_ptr = deleteRec(root->left_ptr, value);
        	}
			else if(value > root->data){
            	root->right_ptr = deleteRec(root->right_ptr, value);
        	}
			else{
        		if (root->left_thread && root->right_thread){
                	delete root;
                	return 0;
            	}
				else if(root->left_thread){
                	tree_node* temp = root->right_ptr;
                	delete root;
                	return temp;
            	}
				else if (root->right_thread){
                	tree_node* temp = root->left_ptr;
                	delete root;
                	return temp;
            	}
				else{
                	tree_node* inOrderSucc = inOrderSuccessor(root);
                	root->data = inOrderSucc->data;
                	root->right_ptr = deleteRec(root->right_ptr, inOrderSucc->data);
            	}	
        	}
        	return root;
    }

};

int main() {
	tree_function tree;
	int user_input, to_add, search, successor, temp;
	int key = 0;
	while(true){
		cout << "MENU-TBT" <<endl;
		cout << "1. Insert." <<endl;
		cout << "2. Delete." <<endl;
		cout << "3. Find Max." <<endl;
		cout << "4. Find Min." <<endl;
		cout << "5. Search." <<endl;
		cout << "6. Display." <<endl;
		cout << "8. Update." <<endl;
		cout << "7. Exit." <<endl;
		cout << "Your Input: ";
		cin >> user_input;
		switch(user_input){
			case 1:
				cout << "Enter Data To Add: ";
                cin >> to_add;
                tree.insert(tree.root, to_add);
				break;
			case 2:
				cout << "Enter Value To Delete:";
    			cin >> key;
    			tree.delete_node(key);
				break;
			case 3:
				cout << "Displaying Max." <<endl;
				temp = tree.findMax();
				cout << temp <<endl;
				break;
			case 4:
				cout << "Displaying Min." <<endl;
				temp = tree.findMin();
				cout << temp <<endl;
				break;	
			case 5:
				cout << "Enter data to search: ";
                cin >> search;
                key = tree.search(search);
                if(key == 0){
                	cout << "Data Not Found In Tree." <<endl;
				}
				else{
					cout << "Data Found." <<endl;
					cout << key << endl;
				}
                
				break;
			case 6:
				tree.inorder(tree.root);	
				break;
			case 7:
				cout << "Thanks For Using Programe." <<endl;
				return false;
			case 8:
				
				break;	
			default:
				cout << "Invalid Input! Please Try Again." <<endl;	
		}
	}
	return 0;
}
