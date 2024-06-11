#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int v, vector<vector<int>> &adj, vector<int> &visited)
{
    visited[v] = true;
    for (int u = 0; u < v; u++)
    {
        if (adj[v][u] && !visited[u])
        {
            dfsUtil(u, adj, visited);
        }
    }
}

bool hasPath(int V, vector<vector<int>> adj, int src, int dest)
{
    vector<int> visited(V, false);
    dfsUtil(src, adj, visited);
    return visited[dest];
}

int main()
{
    int V, src, dest;
    cin >> V;
    vector<vector<int>> adj(V, vector<int>(V));
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            cin >> adj[i][j];
        }
    }

    cin >> src >> dest;
    if (hasPath(V, adj, src, dest))
        cout << "Yes Path Exists" << endl;
    else
        cout << "No Path does not exist" << endl;
    return 0;
}