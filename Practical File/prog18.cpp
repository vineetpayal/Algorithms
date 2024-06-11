#include <iostream>
#include <vector>
using namespace std;

bool hasCycleUtil(int v,vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inPath) {
    visited[v] = true;
    inPath[v] = true;
    for (int u = 0; u < adj.size(); ++u) {
        if (adj[v][u]) {
            if (!visited[u]) {
                if (hasCycleUtil(u, adj, visited, inPath))
                    return true;
            } else if (inPath[u]) {
                return true; 
            }
        }
    }
    inPath[v] = false;
    return false;
}

bool hasCycle(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    vector<bool> inPath(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i] && hasCycleUtil(i, adj, visited, inPath))
            return true;
    }
    return false;
}

int main() {
    int V;
    cin >> V; 

    vector<vector<int>> adj(V, vector<int>(V)); 
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> adj[i][j];
        }
    }
    if (hasCycle(adj, V)) {
        cout << "Yes Cycle Exists" << endl;
    } else {
        cout << "No Cycle Exists" << endl;
    }
    return 0;
}
