#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstras(int V, vector<vector<int>> adj[], int S)
{
    // min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // distance of all nodes from source
    // by default distance of all the nodes from source is infinity
    vector<int> dist(V, INT_MAX);

    // distance of source from source is 0
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // exploring adjacent nodes of source
        for (auto it : adj[node])
        {
            int edgeWeight = it[1];
            int adjNode = it[0];

            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    // v = nodes
    // e = edges
    int V, E;
    cin >> V;
    cin >> E;

    vector<vector<int>> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int S;
    cin >> S;
    int D;
    cin >> D;

    vector<int> dist = dijkstras(V, adj, S);

    cout << "Ditance of source " << S << " from destination " << D << " is " << dist[D];

    for (int i = 0; i < V; i++)
    {
        cout << "Distance from vertex " << S << " to vertex " << i << " is " << dist[i] << endl;
    }
    return 0;
}