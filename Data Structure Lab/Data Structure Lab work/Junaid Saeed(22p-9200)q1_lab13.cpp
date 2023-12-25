#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class graph {
    int n = 5; // Number of nodes in the graph
    bool matrix[5][5]; // take  2D static array of fixed size for ease

public:
    graph(int size) {
        // initialize all the values of the matrix to false
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = false;
            }
        }
    }

    void addEdge(int source, int destination, bool bi) {
        // here bool bi means bidirectional or not
        // if true so node 1 should be connected to node 2 and same further more.
        matrix[source][destination] = true;
        if (bi) 
		{
            matrix[destination][source] = true;
        }
    }

    void removeEdge(int source, int destination, bool bi) {
        matrix[source][destination] = false;
        if (bi) 
		{
            matrix[destination][source] = false;
        }
    }

    void DFS(int start) {
        // here you can use the built-in stack from stack library.
        stack<int> s;
        vector<bool> visited(n, false);

        s.push(start);
        visited[start] = true;

        while (s.empty()!=1) 
		{
            int current = s.top();
            s.pop();

            cout << current << " ";

            for (int i = 0; i < n; ++i) 
			{
                if (matrix[current][i] && !visited[i]) 
				{
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    void BFS(int start) 
	{
        // here you can use the built-in queue from the queue library
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;

        while (q.empty()!=1) 
		{
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int i = 0; i < n; ++i) 
			{
                if (matrix[current][i] && !visited[i]) 
				{
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    void print() {
        for (int i = 0; i < n; ++i) {
            cout << i << ": ";
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    graph g(5);

    // Connect some edges
    g.addEdge(0, 1, true);
    g.addEdge(0, 4, true);
    g.addEdge(1, 3, true);
    g.addEdge(1, 4, true);
    g.addEdge(2, 3, true);

    cout << "Graph Representation:" << endl;
    g.print();

    cout << "\nDFS Traversal from Node 0: ";
    g.DFS(0);

    cout << "\nBFS Traversal from Node 0: ";
    g.BFS(0);

    // Remove an edge example
    cout << "\nRemoving edge between nodes 0 and 1:" << endl;
    g.removeEdge(0, 1, true);
    g.print(); // Display updated graph after edge removal
}
