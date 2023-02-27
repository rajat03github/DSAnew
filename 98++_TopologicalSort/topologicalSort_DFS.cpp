#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, set<int>> &adj, vector<bool> &visited, stack<int> &s)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, adj, visited, s);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, set<int>> adj;
    vector<bool> visited(v);
    // creating adjacency List from edges vector
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].insert(v);
    }

    // calling dfs function to detect cylce
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, s);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}