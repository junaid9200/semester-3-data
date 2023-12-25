#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
    int height;
};


int height(Node* node) 
{
    if (node == nullptr)
        return 0;
        
    return node->height;
}

int max(int a, int b) 
{
    if (a > b) 
	{
    return a;
} 
    else  
	{
    return b;
}
}


Node* newNode(int data) 
{
    Node* node = new Node();
    node->data = data;
    node->left= nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}


Node* rightRotate(Node* y) 

{
    Node* x = y->left; 
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;  

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}


Node* leftRotate(Node* x) 
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node* node) 
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* insert(Node* node, int data) 
{
    if (node == nullptr)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right,data);
    else                                                                                                                         
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data) 
	{
        cout << "Tree is imbalanced: Right Rotation needed" << endl;
        return rightRotate(node);
    }

    if (balance < -1 && data> node->right->data) 
	{
        cout << "Tree is imbalanced: Left Rotation needed" << endl;
        return leftRotate(node);
    }

    if (balance > 1 && data > node->left->data) 
	{
        cout << "Tree is imbalanced: Left-Right Rotation needed" << endl;
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) 
	{
        cout << "Tree is imbalanced: Right-Left Rotation needed" << endl;
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(Node* root) 
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node* minValueNode(Node* node) 
{
    Node* current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int data) 
{
    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) 
		{
            Node* temp;
if (root->left) 
{
    temp = root->left;
} 
else 
{
    temp = root->right;
}

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } 
			else
                *root = *temp;

            free(temp);
        } 
		else {
            Node* temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        cout << "Tree is imbalanced: Right Rotation needed" << endl;
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        cout << "Tree is imbalanced: Left-Right Rotation needed" << endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        cout << "Tree is imbalanced: Left Rotation needed" << endl;
        return leftRotate(root); 
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        cout << "Tree is imbalanced: Right-Left Rotation needed" << endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* maxValueNode(Node* node) 
{
    Node* current = node;

    while (current->right != nullptr)
        current = current->right;

    return current;
}

bool search(Node* root, int data) 
{
    if (root == nullptr)
        return false;

    if (root->data == data)
        return true;

    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

int main() 
{
   Node* root = nullptr;
    int choice, value;

    do {
        cout << "-----------------------" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Delete a value" << endl;
        cout << "3. Display tree (In order traversal)" << endl;
        cout << "4. Update a value" << endl;
        cout << "5. Search a value" << endl;
        cout << "6. Find max" << endl;
        cout << "7. Find min" << endl;
        cout << "8. Exit" << endl;
        cout << "-----------------------" << endl;
        cout<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> value;
                root = insert(root, value);
                cout << "Value inserted successfully" << endl;
                break;
            case 2:
                if (root == nullptr) 
				{
                    cout << "Tree is empty." << endl;
                    break;
                }
                cout << "Enter value to be deleted: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Value deleted successfully" << endl;
                break;
            case 3:
                cout << "AVL Tree (In order traversal): ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                 if (root == nullptr) 
				 {
        cout << "Tree is empty." << endl;
        break;
    }
    int oldValue;
    cout << "Enter the value to be updated: ";
    cin >> oldValue;
    if (!search(root, oldValue)) 
	{
        cout << "Value not found in the tree. Update failed." << endl;
        break;
    }
    int newValue;
    cout << "Enter the new value: ";
    cin >> newValue;
    root = deleteNode(root, oldValue); 
    root = insert(root, newValue);     
    cout << "Value updated successfully." << endl;
    break;
            case 5:
                cout << "Enter value to be searched: ";
                cin >> value;
                if (search(root, value))
                    cout << "Value found in the tree" << endl;
                else
                    cout << "Value not found in the tree" << endl;
                break;
            case 6:
                if (root == nullptr) {
                    cout << "Tree is empty." << endl;
                    break;
                }
                cout << "Maximum value in the tree: " << maxValueNode(root)->data << endl;
                break;
            case 7:
                if (root == nullptr) {
                    cout << "Tree is empty." << endl;
                    break;
                }
                cout << "Minimum value in the tree: " << minValueNode(root)->data<< endl;
                break;
            case 8:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    }
	 while (choice != 8);
}

