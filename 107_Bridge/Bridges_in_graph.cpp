#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for (auto neighbr : adj[node])
    {
        if (neighbr == parent)
            continue;
        else if (!visited[neighbr])
        {
            dfs(neighbr, node, timer, disc, low, result, adj, visited);
            // update low now
            low[node] = min(low[node], low[neighbr]);
            // check bridge or not
            if (low[neighbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbr);
                result.push_back(ans);
            }
        }
        else
        // node already visited and not parent
        {
            // back - edge
            low[node] = min(low[node], disc[neighbr]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // adjList
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // requirements
    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> visited;

    // initialise them
    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }
    vector<vector<int>> result;
    // dfs
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, timer, disc, low, result, adj, visited);
        }
    }
    return result;
}