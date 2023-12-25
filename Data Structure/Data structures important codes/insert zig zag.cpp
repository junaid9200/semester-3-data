#include <iostream>

using namespace std;

// Define a structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
class tree{
	public:
	Node* root;
	bool check;
	
	tree(){
		root = nullptr;
		check = true;
	}
	
	
void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    } else {
        // Insert in a zig-zag pattern based on the current height
        while(root->left!=nullptr || root->right!=nullptr){
        	if(root->left==nullptr){
        		root = root->right;
			}
			if(root->right==nullptr){
				root = root->left;
			}
		}
        if (check) {
            insert(root->right, value);
            check = false;
        } else {
            insert(root->left, value);
            check = true;
        }
    }
}


// Function to print the tree in-order (for verification)
void printInOrder(Node* root) {
    if (root == nullptr)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}
};


int main() {
    Node* root = nullptr;
	tree obj;
    // Let the user input data values until a specific sentinel value is entered
    int value;
    cout << "Enter data values to insert into the tree (enter -1 to stop): ";
    while (cin >> value && value != -1) {
        obj.insert(root, value);
    }

    // Print the tree in-order (for verification)
    cout << "Tree in-order traversal:" << endl;
    obj.printInOrder(root);

    return 0;
}

