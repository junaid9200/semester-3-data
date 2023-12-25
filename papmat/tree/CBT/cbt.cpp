#include <iostream>

using namespace std;

// Node structure for the binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Simple queue implementation for tree traversal
class SimpleQueue {
private:
    struct Node {
        TreeNode* data;
        Node* next;

        Node(TreeNode* value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    SimpleQueue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(TreeNode* value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    TreeNode* dequeue() {
        if (isEmpty()) {
            return nullptr;
        }

        Node* temp = front;
        front = front->next;

        TreeNode* value = temp->data;
        delete temp;

        return value;
    }
};

// Binary Tree class
class CompleteBinaryTree {
private:
    TreeNode* root;

public:
    CompleteBinaryTree() : root(nullptr) {}

    // Function to insert a node into the complete binary tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Function to display the binary tree in level order
    void displayLevelOrder() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        SimpleQueue queue;
        queue.enqueue(root);

        cout << "Level Order Traversal:" << endl;
        while (!queue.isEmpty()) {
            TreeNode* current = queue.dequeue();

            cout << current->data << " ";

            if (current->left != nullptr)
                queue.enqueue(current->left);

            if (current->right != nullptr)
                queue.enqueue(current->right);
        }

        cout << endl;
    }

private:
    // Recursive function to insert a node into the binary tree
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr)
            return new TreeNode(value);

        if (isComplete(node, 1, size(node) + 1)) {
            if (value <= node->data)
                node->left = insertRecursive(node->left, value);
            else
                node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    // Function to check if the binary tree is complete
    bool isComplete(TreeNode* node, int index, int totalNodes) {
        if (node == nullptr)
            return true;

        if (index > totalNodes)
            return false;

        return isComplete(node->left, 2 * index, totalNodes) &&
               isComplete(node->right, 2 * index + 1, totalNodes);
    }

    // Function to get the size of the binary tree
    int size(TreeNode* node) {
        if (node == nullptr)
            return 0;

        return 1 + size(node->left) + size(node->right);
    }
};

// Main function with menu
int main() {
    CompleteBinaryTree binaryTree;
    int choice, value;

    do {
        cout << "\nBinary Tree Menu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Display level order traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                binaryTree.insert(value);
                break;

            case 2:
                binaryTree.displayLevelOrder();
                break;

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

