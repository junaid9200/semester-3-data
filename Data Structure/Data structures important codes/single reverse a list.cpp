#include <iostream>

// Define the structure of a singly linked list node
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a singly linked list
Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next; // Store the next node
        current->next = prev; // Change the direction of the pointer
        
        // Move to the next nodes
        prev = current;
        current = next;
    }
    
    // 'prev' will now point to the new head of the reversed list
    return prev;
}

// Function to print the elements of a linked list
void printLinkedList(Node* head) {
    Node* current = head;
    
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    
    std::cout << std::endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    std::cout << "Original Linked List: ";
    printLinkedList(head);
    
    // Reverse the linked list
    head = reverseLinkedList(head);
    
    std::cout << "Reversed Linked List: ";
    printLinkedList(head);
    
    // Don't forget to free the memory allocated for the linked list nodes
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}

