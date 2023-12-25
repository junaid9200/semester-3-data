#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }
    void remove(int val) {
        Node* curr = head;
        Node* prev = NULL;

        // If the head node itself needs to be removed
        if (curr != NULL && curr->val == val) {
            head = curr->next; // Change head
            delete curr;        // Free old head
            return;
        }

        // Search for the node to be removed, keep track of the previous node
        while (curr != NULL && curr->val != val) {
            prev = curr;
            curr = curr->next;
        }

        // If the node was not found
        if (curr == NULL) return;

        // Unlink the node from the list
        prev->next = curr->next;

        // Free memory
        delete curr;
    }
    void printList() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }
    }
};

class graph {
    LinkedList* adjlist; // pointer to an array of linked list
    int n;

public:
    graph(int size) {
        adjlist = new LinkedList[size]; // initialize the pointer to point to a dynamic array of linked list
        n = size;
    }

    void addedge(int source, int destination, bool bi) {
        adjlist[source].append(destination); // Add edge from source to destination

        if (bi) {
            adjlist[destination].append(source); // If bidirectional, add edge from destination to source
        }
    }

    void removeEdge(int source, int destination, bool bi) {
        adjlist[source].remove(destination); // Remove edge from source to destination

        if (bi) {
            adjlist[destination].remove(source); // If bidirectional, remove edge from destination to source
        }
    }

    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        Node* temp = adjlist[vertex].head;
        while (temp != nullptr) {
            int adj = temp->val;
            if (!visited[adj]) {
                DFSUtil(adj, visited);
            }
            temp = temp->next;
        }
    }

    void DFS(int start) {
    	
        vector<bool> visited(n, false);
        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    void BFS(int start) {
        vector<bool> visited(n, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS: ";
        while (!q.empty()) {
            int vertex = q.front();
            cout << vertex << " ";
            q.pop();

            Node* temp = adjlist[vertex].head;
            while (temp != nullptr) {
                int adj_vertex = temp->val;
                if (!visited[adj_vertex]) {
                    visited[adj_vertex] = true;
                    q.push(adj_vertex);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    void print() {
        // print the adjacency list
        for (int i = 0; i < n; ++i) {
            cout << "Vertex " << i << " -> ";
            adjlist[i].printList();
            cout << endl;
        }
    }
};

int main() {
    graph g(5);
    g.addedge(0, 1, true);
    g.addedge(3, 1, true);
    g.addedge(0, 2, true);
    g.addedge(3, 2, true);
    g.addedge(0, 3, true);

    cout << "Graph before removing edges:" << endl;
    g.print();

    cout<<endl;
    
    cout << "Graph after removing edges:"<<endl;
    g.removeEdge(3, 1, true);
    g.print();

    cout<<endl;
    g.DFS(1);
    g.BFS(1);
}

