#include <iostream>
#include <queue>

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

    bool isCompleteBinaryTree() {
        if (root == nullptr) {
            return true;
        }

        std::queue<Node*> q;
        q.push(root);

        bool flag = false;

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left) {
                if (flag) {
                    return false;
                }
                q.push(current->left);
            } else {
                flag = true;
            }

            if (current->right) {
                if (flag) {
                    return false;
                }
                q.push(current->right);
            } else {
                flag = true;
            }
        }

        return true;
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

    bool isComplete = tree.isCompleteBinaryTree();

    if (isComplete) {
        std::cout << "The tree is a complete binary tree." << std::endl;
    } else {
        std::cout << "The tree is not a complete binary tree." << std::endl;
    }

    return 0;
}

