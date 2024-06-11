#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(const vector<vector<int>> &adj, int V)
{
    vector<int> color(V, -1); 
    vector<bool> visited(V, false);

    for (int start = 0; start < V; ++start)
    {
        if (!visited[start])
        {
            queue<int> q;
            q.push(start);
            color[start] = 0; 

            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                visited[u] = true;

                for (int v = 0; v < V; ++v)
                {
                    if (adj[u][v])
                    {
                        if (color[v] == -1)
                        {
                            color[v] = 1 - color[u];
                            q.push(v);
                        }
                        else if (color[v] == color[u])
                        {
                            return false; 
                        }
                    }
                }
            }
        }
    }

    return true; 
}

int main()
{
    int V;
    cin >> V; 

    vector<vector<int>> adj(V, vector<int>(V)); 

    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            cin >> adj[i][j];
        }
    }

    if (isBipartite(adj, V))
    {
        cout << "Yes Bipartite" << endl;
    }
    else
    {
        cout << "Not Bipartite" << endl;
    }

    return 0;
}
