#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9; 

void bellmanFord(const vector<vector<int>>& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INF);

    dist[src] = 0;
    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    for (int i = 0; i < V; ++i) {
        cout << "Distance from friend " << i << " to Akshay's house: " << dist[i] << endl;
    }
}

int main() {
    int V;
    cin >> V; 
    vector<vector<int>> graph(V, vector<int>(V)); // Initialize adjacency matrix
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }
    int src;
    cin >> src;
    bellmanFord(graph, src);
    return 0;
}
