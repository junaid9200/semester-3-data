#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Graph{
	public:
//	number_of_vertices = 5
	bool matrix[5][5];
	
	Graph(){
		// fill all values equal to zero
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				matrix[i][j] = false; // false -> no edge, true -> edge
			}
		}	
	}
	
	void add_edge(int source, int destination, bool bi_directional){
		matrix[source][destination] = true;
		if(!bi_directional){
			matrix[destination][source] = true;
		}
	}
	
	void remove_edge(int source, int destination, bool bi_directional){
		matrix[source][destination] = false;
		if(!bi_directional){
			matrix[destination][source] = false;
		}
	}
	
	void display_adjmatrix(){
		cout << "Displaying - Matrix (5x5)" << endl;
		cout << endl;
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	void display_adjlist(){
		cout << "Displaying - List" << endl;
		for(int i=0; i<5; i++){
			cout << i <<": ";
			for(int j=0; j<5; j++){
				if(matrix[i][j] == true){
					cout << j << " ";
				}
			}
			cout << endl;
		}
	}
	
	void DFS(int start) {
        stack<int> obj_stack;
        vector<bool> visited(5, false);

        obj_stack.push(start);

        while (!obj_stack.empty()) {
            int current = obj_stack.top();
            obj_stack.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;
            }

            for (int i = 0; i < 5; ++i) {
                if (matrix[current][i] && !visited[i]) {
                    obj_stack.push(i);
                }
            }
        }
        cout << endl;
    }
    
    void BFS(int start) {
        queue<int> obj_queue;
        vector<bool> visited(5, false);

        obj_queue.push(start);
        visited[start] = true;

        while (!obj_queue.empty()) {
            int current = obj_queue.front();
            obj_queue.pop();

            cout << current << " ";

            for (int i = 0; i < 5; ++i) {
                if (matrix[current][i] && !visited[i]) {
                    obj_queue.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }
};

int main(){
	Graph obj;
	int user_input;
	int source, destination;
	bool bi_directional;
	
	cout << "Welcome" << endl;

	while(true){
		cout << endl;
		cout << "--Menu--" << endl;
		cout << "1. Add Edges." << endl;
		cout << "2. Remove Edge." << endl;
		cout << "3. Display Adjacency-Matrix." << endl;
		cout << "4. Display Adjacency-List." << endl;
		cout << "5. BFS Traversal." << endl;
		cout << "6. DFS Traversal." << endl;
		cout << "7. Exit." << endl;
		cout << "Your-Input: ";
		cin >> user_input;
		switch(user_input){
			case 1:
				cout << endl;
				cout << "Enter Source Vertex (0-4): ";
				cin >> source;
				cout << "Enter Destination Vertex (0-4): ";
				cin >> destination;
				cout << "Is Edge Directed (1/0): ";
				cin >> bi_directional;
				obj.add_edge(source, destination, bi_directional);
				break;
			case 2:
				cout << endl;
				cout << "Enter Source Vertex (0-4): ";
				cin >> source;
				cout << "Enter Destination Vertex (0-4): ";
				cin >> destination;
				cout << "Is Edge Directed (1/0): ";
				cin >> bi_directional;
				obj.remove_edge(source, destination, bi_directional);
				break;
			case 3:
				cout << endl;
				obj.display_adjmatrix();
				cout << endl;
				break;
			case 4:
				cout << endl;	
				obj.display_adjlist();
				cout << endl;
				break;
			case 5:
				cout << endl;
            	cout << "Enter Starting Vertex for BFS: ";
            	cin >> source;
            	obj.BFS(source);
            	break;
			case 6:
				cout << endl;
            	cout << "Enter Starting Vertex for DFS: ";
            	cin >> source;
            	obj.DFS(source);
            	break;	
			case 7:
				cout << "Thanks For Using Our Program." << endl;
				return false;		
			default:
				cout << "Invalid Input." << endl;		
		}		
	}
	return 0;
}
