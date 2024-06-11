#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> edges, int S)
{
    vector<int> dist(V, 1e9);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int source;
    cin >> source;

    vector<int> dist = bellmanFord(V, edges, source);
    for (int i = 0; i < V; i++)
    {
        cout << "distance of vertex " << i << " from source " << source << " is " << dist[i] << endl;
    }

    bool negativeCycle = false;
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] != 1e9 && dist[u] + wt < dist[v])
        {
            negativeCycle = true;
            dist[v] = dist[u] + wt;
        }
    }
    if (negativeCycle)
    {
        cout << "Yes negative cycle" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}