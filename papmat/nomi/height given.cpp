#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insertUtil(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertUtil(node->left, value);
        } else if (value > node->data) {
            node->right = insertUtil(node->right, value);
        }

        return node;
    }

    void inorderUtil(Node* node) {
        if (node == nullptr) {
            return;
        }

        inorderUtil(node->left);
        std::cout << node->data << " ";
        inorderUtil(node->right);
    }

   int countLeavesAtHeight(Node* node, int currentHeight, int targetHeight) {
    if (node == nullptr) {
        return 0;
    }

    if (currentHeight == targetHeight) {
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        } else {
            return 0;
        }
    }

    int leftCount = countLeavesAtHeight(node->left, currentHeight + 1, targetHeight);
    int rightCount = countLeavesAtHeight(node->right, currentHeight + 1, targetHeight);

    return leftCount + rightCount;
}


public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertUtil(root, value);
    }

    void inorderTraversal() {
        if (root == nullptr) {
            std::cout << "The tree is empty!" << std::endl;
            return;
        }

        std::cout << "Inorder Traversal:" << std::endl;
        inorderUtil(root);
        std::cout << std::endl;
    }

    int countLeavesAtGivenHeight(int height) {
        return countLeavesAtHeight(root, 1, height);
    }
};

int main() {
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    tree.inorderTraversal();

    int heightToCheck = 2; // Change this value to check leaves at different heights
    int leafCount = tree.countLeavesAtGivenHeight(heightToCheck);

    std::cout << "Number of leaves at height " << heightToCheck << ": " << leafCount << std::endl;

    return 0;
}

