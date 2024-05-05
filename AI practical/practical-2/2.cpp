#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Graph {
    int V; 
    vector<vector<int>> adj; 

public:
    Graph(int V) : V(V), adj(V) {}
    void addEdge(int v, int w) 
    {
        adj[v].push_back(w);
        adj[w].push_back(v); 

    }
    void DFSUtil(int v, unordered_set<int>& visited) 
    {
        visited.insert(v);
        cout << v << " ";       
        for (int neighbor : adj[v])
         {
            if (visited.find(neighbor) == visited.end()) 
            {
                DFSUtil(neighbor, visited);
            }
        }
    }
    void DFS() {
        unordered_set<int> visited;

        for (int i = 0; i < V; ++i) {
            if (visited.find(i) == visited.end()) {
                DFSUtil(i, visited);
            }
        }
    }
};

int main() {
    Graph g(6); 
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "Depth First Traversal starting from vertex 0:\n";
    g.DFS();
    cout << endl;

    return 0;
}
