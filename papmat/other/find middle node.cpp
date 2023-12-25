#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int countNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

TreeNode* findMiddleNode(TreeNode* root, int& count, int target) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* left = findMiddleNode(root->left, count, target);

    count++;
    if (count == target) {
        return root; // Return the middle node
    }

    TreeNode* right = findMiddleNode(root->right, count, target);

    return left != nullptr ? left : right;
}

TreeNode* findMiddleNode(TreeNode* root) {
    int totalNodes = countNodes(root);
    int target = totalNodes / 2 + 1; // Adjust target for 1-based indexing
    int count = 0;
    return findMiddleNode(root, count, target);
}

TreeNode* constructBST() {
    // Implement tree creation logic here based on your requirements
    // For simplicity, you can hardcode a tree or take user input to create one.
    // Example: TreeNode* root = new TreeNode(10); root->left = new TreeNode(5); ...
    return /* Constructed BST */;
}

void printMenu() {
    std::cout << "1. Create BST\n";
    std::cout << "2. Find Middle Node\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    TreeNode* root = nullptr;

    int choice;
    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Create BST
                root = constructBST();
                break;
            case 2:
                // Find Middle Node
                if (root != nullptr) {
                    TreeNode* middleNode = findMiddleNode(root);
                    std::cout << "Middle node is: " << middleNode->data << std::endl;
                } else {
                    std::cout << "Tree is empty." << std::endl;
                }
                break;
            case 3:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}

