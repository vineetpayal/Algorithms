#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int prims(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(V, 0);

    // push (weight, node)
    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (!visited[node])
        {
            visited[node] = 1;
            sum = sum + weight;

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int adjweight = it[1];

                if (!visited[adjNode])
                {
                    pq.push({adjweight, adjNode});
                }
            }
        }
    }
    return sum;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int minWeight = prims(V, adj);
    cout << "minimum weight: " << minWeight << endl;
}