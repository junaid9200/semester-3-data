#include <iostream>

// Define a singly linked list node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to delete all nodes in a linked list
void deleteLinkedList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Creating a sample singly linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original linked list: ";
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Call the deleteLinkedList function to delete all nodes
    deleteLinkedList(head);

    std::cout << "Linked list after deletion: ";
    if (head == nullptr) {
        std::cout << "Empty" << std::endl;
    } else {
        std::cout << "Not empty (error)" << std::endl;
    }

    return 0;
}

