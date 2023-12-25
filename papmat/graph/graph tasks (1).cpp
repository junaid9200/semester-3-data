#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    
    Node(int value){
        this->value = value;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    
    LinkedList(){
        head = NULL;
    }

    void append(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        }
		else{
            Node* current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void remove(int val){
        Node* current = head;
        Node* previous = NULL;

        // If the head node itself needs to be removed
        if(current != NULL && current->value == val){
            head = current->next; // Change head
            delete current;       // Free old head
            return;
        }

        // Search for the node to be removed, keep track of the previous node
        while(current != NULL && current->value != val){
            previous = current;
            current = current->next;
        }

        // If the node was not found
        if(current == NULL){
			return;
		}

        // Unlink the node from the list
        previous->next = current->next;

        // Free memory
        delete current;
    }

    void printList(){
        Node* curr = head;
        while(curr != NULL){
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

class graph{
    LinkedList* adjlist; // pointer to an array of linked list
    int number_of_nodes;

	public:
    graph(int size){
        adjlist = new LinkedList[size]; // initialize the pointer to point to a dynamic array of linked list
        number_of_nodes = size;
    }

    void addedge(int source, int destination, bool bi){
        adjlist[source].append(destination);
        if(bi){	
            adjlist[destination].append(source); // Add the reverse edge for bidirectional graph
    	}
	}

    void removeEdge(int source, int destination, bool bi) {
        adjlist[source].remove(destination);
        if(bi){
            adjlist[destination].remove(source); // Remove the reverse edge for bidirectional graph
		}
	}

    void DFS(int start){
        // you can use the built-in stack and vector to use in this method
        vector<bool> visited(number_of_nodes, false);
        stack<int> obj_stack;

        obj_stack.push(start);
        visited[start] = true;

        while(obj_stack.empty() == false){
            int current = obj_stack.top();
            obj_stack.pop();

            cout << current;
            cout << " ";

            Node* temp = adjlist[current].head;
            while(temp != NULL){
                if(visited[temp->value] == false){
                    obj_stack.push(temp->value);
                    visited[temp->value] = true;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    void BFS(int start){
        // you can use the built-in queue and vector to use in this method
        vector<bool> visited(number_of_nodes, false);
        queue<int> obj_queue;

        obj_queue.push(start);
        visited[start] = true;

        while(obj_queue.empty() == false){
            int current = obj_queue.front();
            obj_queue.pop();

            cout << current << " ";

            Node* temp = adjlist[current].head;
            while(temp != NULL){
                if(visited[temp->value] == false){
                    obj_queue.push(temp->value);
                    visited[temp->value] = true;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    void print(){
        cout << "Printing graph (alist)..." << endl;
        for(int i=0; i<number_of_nodes; ++i){
            cout << i << ": ";
            adjlist[i].printList();
        }
    }
};

int main(){
    graph obj_graph(5);
    obj_graph.addedge(0, 1, true);
    obj_graph.addedge(3, 1, true);
    obj_graph.addedge(0, 2, true);
    obj_graph.addedge(3, 2, true);
    obj_graph.addedge(0, 3, true);
    obj_graph.print();
	cout << endl;
    cout << "Graph after removing edges:" << endl;
    obj_graph.removeEdge(3, 2, true);
    obj_graph.removeEdge(0, 3, true);
    obj_graph.print();
	cout << endl;
    cout << "DFS from Node 1: ";
    obj_graph.DFS(1);
	cout << endl;
    cout << "BFS from Node 1: ";
    obj_graph.BFS(1);

    return 0;
}
