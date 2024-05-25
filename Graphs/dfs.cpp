#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int node, vector<int> adj[], vector<int> &visited, vector<int> &dfs)
{
    visited[node] = true;
    dfs.push_back(node);

    // visited adjacant node;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfsUtil(it, adj, visited, dfs);
        }
    }
}

vector<int> DFS(int V, vector<int> adj[])
{
    vector<int> visited(V, false);
    vector<int> dfs;
    int start = 0;
    dfsUtil(start, adj, visited, dfs);
    return dfs;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];

    // input graph in form of adjacency list
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dfs = DFS(V, adj);

    // printing dfs
    for (int i = 0; i < V; i++)
    {
        cout << dfs[i] << " ";
    }
    return 0;
}