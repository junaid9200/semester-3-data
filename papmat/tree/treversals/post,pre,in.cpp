#include <iostream>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
	left = NULL;
	right = NULL;
	}
};

// In-order traversal
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        std::cout << root->val << " ";
        inOrderTraversal(root->right);
    }
}

// Post-order traversal
void postOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->val << " ";
    }
}

// Pre-order traversal
void preOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        std::cout << root->val << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    // Example usage:
    // Constructing a simple binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "In-order traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    postOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    std::cout << std::endl;

    // Remember to free the allocated memory to avoid memory leaks
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

