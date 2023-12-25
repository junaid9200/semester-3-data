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

    int countNonLeafChildren(Node* node, int& leftCount, int& rightCount) {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
            return 0;
        }

        int total = 0;

        if (node->left != nullptr) {
            if (node->left->left == nullptr && node->left->right == nullptr) {
                ++leftCount;
            }
            total += countNonLeafChildren(node->left, leftCount, rightCount);
        }

        if (node->right != nullptr) {
            if (node->right->left == nullptr && node->right->right == nullptr) {
                ++rightCount;
            }
            total += countNonLeafChildren(node->right, leftCount, rightCount);
        }

        return total;
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertUtil(root, value);
    }

    void countNonLeafChildPosition() {
        if (root == nullptr) {
            std::cout << "The tree is empty!" << std::endl;
            return;
        }

        int leftCount = 0, rightCount = 0;

        int totalNonLeaf = countNonLeafChildren(root, leftCount, rightCount);

        std::cout << "Number of non-leaves that are left children: " << leftCount << std::endl;
        std::cout << "Number of non-leaves that are right children: " << rightCount << std::endl;
        std::cout << "Total non-leaves in the tree: " << totalNonLeaf << std::endl;
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

    tree.countNonLeafChildPosition();

    return 0;
}

