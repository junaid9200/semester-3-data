#include<iostream>
using namespace std;

struct tree_node{
    int data, balance_factor;
    tree_node* left_ptr;
    tree_node* right_ptr;

    tree_node(int data) {
        this->data = data;
        left_ptr = nullptr;
        right_ptr = nullptr;
        balance_factor = 0;
    }
};

class tree_function {
public:
    tree_node* root;

    tree_function(){
        root = nullptr;
    }

    int cal_height(tree_node* root){
        if(root == nullptr){
            return -1;
        }
        int leftHeight = cal_height(root->left_ptr);
    	int rightHeight = cal_height(root->right_ptr);

    	// Use conditional statements instead of max function
    	if(leftHeight > rightHeight){
        	return leftHeight + 1;
    	} 
		else{
        	return rightHeight + 1;
    	} 
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

    tree_node* add_data(tree_node* root, int data){
        if(root == nullptr){
            return new tree_node(data);
        }

        if(data < root->data){
            root->left_ptr = add_data(root->left_ptr, data);
        }
		else if(data > root->data){
            root->right_ptr = add_data(root->right_ptr, data);
        }
		else{
            cout << "Duplicate exists." << endl;
            return root;
        }

        root->balance_factor = cal_balance_factor(root);

        if(root->balance_factor > 1){
            if(data < root->left_ptr->data){
                return right_rotate(root);
            }
			else{
                root->left_ptr = left_rotate(root->left_ptr);
                return right_rotate(root);
            }
        }

        if(root->balance_factor < -1){
            if(data > root->right_ptr->data){
                return left_rotate(root);
            }
			else{
                root->right_ptr = right_rotate(root->right_ptr);
                return left_rotate(root);
            }
        }                                                                
        return root;
    }

    tree_node* delete_node(tree_node* node, int data){
        if(node == nullptr){
            cout << "Data not found in tree." << endl;
            return node;
        }

        if(data < node->data){
            node->left_ptr = delete_node(node->left_ptr, data);
        }
		else if(data > node->data){
            node->right_ptr = delete_node(node->right_ptr, data);
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
                node->data = temp->data;
                node->right_ptr = delete_node(node->right_ptr, temp->data);
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
        cout << root->data << endl;
        display_in_order(root->right_ptr);
    }

    void search_data(tree_node* root, int to_search) {
        if(root == nullptr){
            cout << "Data not found in tree." << endl;
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
                cout << "Data found in tree." << endl;
                cout << "Data: " << root->data << endl;
                return;
            }
        }
    }

    tree_node* find_min(tree_node* root){
        if(root == nullptr){
            cout << "Tree is empty." << endl;
            return nullptr;
        }
        while(root->left_ptr != nullptr){
            root = root->left_ptr;
        }
        return root;
    }

    int find_min_data(tree_node* root){
        if(root == nullptr){
            cout << "Tree is empty." << endl;
            return 0;
        }
        while(root->left_ptr != nullptr){
            root = root->left_ptr;
        }
        return root->data;
    }

    tree_node* find_max(tree_node* root){
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return nullptr;
        }
        while(root->right_ptr != nullptr){
            root = root->right_ptr;
        }
        return root;
    }

    int find_max_data(tree_node* root){
        if(root == nullptr){
            cout << "Tree is empty." << endl;
            return 0;
        }
        while(root->right_ptr != nullptr){
            root = root->right_ptr;
        }
        return root->data;
    }
    
    tree_node* update_data(tree_node* root){
    	int update_to, to_update;
    	cout << "Enter data to update to: ";
    	cin >> update_to;
    	root = delete_node(root, update_to);
    	cout << "Enter data to update: ";
    	cin >> to_update;
    	root = add_data(root, to_update);
    	return root;
	}
};

int main() {
    int user_input, search, to_add, to_delete;
    tree_function tree;
    while (true) {
        int min = 0, max = 0;
        cout << "MENU-AVL" << endl;
        cout << "1. Insert Data." << endl;
        cout << "2. Delete Data." << endl;
        cout << "3. Display Data." << endl;
        cout << "4. Update Data." << endl;
        cout << "5. Search Data." << endl;
        cout << "6. Find max Data." << endl;
        cout << "7. Find min Data." << endl;
        cout << "8. Exit Program." << endl;
        cout << "Your Input: ";
        cin >> user_input;
        switch (user_input) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> to_add;
                tree.root = tree.add_data(tree.root, to_add);
                break;
            case 2:
                cout << "Enter data to delete: ";
                cin >> to_delete;
                tree.root = tree.delete_node(tree.root, to_delete);
                break;
            case 3:
                cout << "Displaying tree data." << endl;
                tree.display_in_order(tree.root);
                break;
            case 4:
                tree.root = tree.update_data(tree.root);
                break;
            case 5:
                cout << "Enter data to search: ";
                cin >> search;
                if (tree.root == nullptr) {
                    cout << "Tree is empty." << endl;
                    break;
                }
                tree.search_data(tree.root, search);
                break;
            case 6:
                max = tree.find_max_data(tree.root);
                cout << "Maximum value is: " << max << endl;
                break;
            case 7:
                min = tree.find_min_data(tree.root);
                cout << "Minimum value is: " << min << endl;
                break;
            case 8:
                cout << "Thanks for using program." << endl;
                return 0;
            default:
                cout << "Invalid Input, Please Try Again." << endl;
                break;
        }
    }
    return 0;
}

