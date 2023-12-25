#include <iostream>

// Define the structure of a singly linked list node
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to traverse and print all elements of the linked list in reverse order
void printReverseLinkedList(Node* head) {
    if (head == nullptr) {
        return;
    }
    
    // Recursively call the function for the next node
    printReverseLinkedList(head->next);
    
    // Print the data of the current node
    std::cout << head->data << " ";
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Traverse and print the linked list in reverse order
    printReverseLinkedList(head);
    
    // Don't forget to free the memory allocated for the linked list nodes
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}

