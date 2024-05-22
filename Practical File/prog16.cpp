#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // No. of vertices
    vector<vector<int>> adj; // Adjacency matrix

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // Function to add an edge to graph
    bool isReachable(int s, int d); // Returns true if there is a path from source 's' to destination 'd'
};

Graph::Graph(int V) {
    this->V = V;
    adj = vector<vector<int>>(V, vector<int>(V, 0));
}

void Graph::addEdge(int v, int w) {
    adj[v][w] = 1; // Add edge from v to w
    adj[w][v] = 1; // Add edge from w to v
}

bool Graph::isReachable(int s, int d) {
    if (s == d)
        return true;

    vector<bool> visited(V, false);
    visited[s] = true;

    vector<int> stack;
    stack.push_back(s);

    while (!stack.empty()) {
        s = stack.back();
        stack.pop_back();

        for (int i = 0; i < V; i++) {
            if (adj[s][i] == 1 && !visited[i]) {
                if (i == d)
                    return true;
                stack.push_back(i);
                visited[i] = true;
            }
        }
    }

    return false;
}

// Driver code
int main() {
    int V;
    cin >> V;
    Graph g(V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int edge;
            cin >> edge;
            if (edge == 1)
                g.addEdge(i, j);
        }
    }

    int u, v;
    cin >> u >> v;
    if (g.isReachable(u, v))
        cout << "Yes Path Exists";
    else
        cout << "No Such Path Exists";

    return 0;
}
