#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class graph{
    int number_of_nodes;
    bool matrix[5][5]; // take  2D static array of fixed size for ease

public:
    graph(int size){
        number_of_nodes = size;
        for(int i=0; i<number_of_nodes; ++i){
            for(int j=0; j<number_of_nodes; ++j){
                matrix[i][j] = false;
            }
        }
    }

    void addEdge(int source_node, int destination_node, bool bi){
        // here bool bi means bidirectional or not
        // if true so node 1 should be connected to node 2 and also vice versa
        matrix[source_node][destination_node] = true;
        if(bi == true){
            matrix[destination_node][source_node] = true;
        }
    }

    void removeEdge(int source, int destination, bool bi) {
        matrix[source][destination] = false;
        if(bi){
            matrix[destination][source] = false;
        }
    }

    void DFS(int start){
        // here you can use the built-in stack from stack library.
        stack<int> obj_stack;
        vector<bool> visited(number_of_nodes, false);

        obj_stack.push(start);
        visited[start] = true;

        while(obj_stack.empty() == false){
            int current = obj_stack.top();
            obj_stack.pop();
            cout << current;
            cout << " ";

            for(int i = 0; i < number_of_nodes; ++i){
                if(matrix[current][i] && (!visited[i])){
                    obj_stack.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    void BFS(int start){
        // here you can use the built-in queue from the queue library
        queue<int> obj_queue;
        vector<bool> visited(number_of_nodes, false);

        obj_queue.push(start);
        visited[start] = true;

        while(!obj_queue.empty()){
            int current = obj_queue.front();
            obj_queue.pop();

            cout << current << " ";

            for(int i = 0; i < number_of_nodes; ++i){
                if(matrix[current][i] && !visited[i]){
                    obj_queue.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    void print(){
    	cout << "Displaying..." << endl;
        for(int i=0; i<number_of_nodes; ++i){
            cout << i << ": ";
            for(int j=0; j<number_of_nodes; ++j){
                if(matrix[i][j]){
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};

int main(){
    graph obj(5);

    cout << "Connecting Edges of Graphes..." << endl;
    obj.addEdge(0, 1, true);
    obj.addEdge(1, 4, true);
    obj.addEdge(1, 3, true);
    obj.addEdge(3, 4, true);
    obj.addEdge(2, 4, true);
    obj.print();
	cout << endl;
    cout << "DFS Traversal from Node 0..." << endl;
    obj.DFS(0);
	cout << endl;
    cout << "BFS Traversal from Node 0..." << endl;
    obj.BFS(0);
    return 0;
}

