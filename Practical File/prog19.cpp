#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;

void dijkstra(const vector<vector<int>>& graph, int src, int dest) {
    int V = graph.size();
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Shortest path from vertex " << dest << " to vertex " << src << ":" << endl;
    int v = dest;
    while (v != -1) {
        cout << v << " ";
        v = parent[v];
    }
    cout << endl;
    cout << "Minimum path weight: " << dist[dest] << endl;
}

int main() {
    int V;
    cin >> V; 
    vector<vector<int>> graph(V, vector<int>(V)); 
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }
    int src, dest;
    cin >> src >> dest;
    dijkstra(graph, src, dest);
    return 0;
}
