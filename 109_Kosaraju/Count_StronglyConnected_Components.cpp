#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &stc, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    // chech adjs connected
    for (auto neighbr : adj[node])
    {
        if (!visited[neighbr])
            dfs(neighbr, visited, stc, adj);
    }
    // if node returned then push in stack for topo Sort
    stc.push(node);
}

void revdfs(int Node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &TransposedGraph)
{
    visited[Node] = true;
    for (auto neighbr : TransposedGraph[Node])
        if (!visited[neighbr])
            revdfs(neighbr, visited, TransposedGraph);
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // adjLIst
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // directed graph
        adj[u].push_back(v);
    }

    // step 1 ~ TOPOSORT
    stack<int> stc;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, stc, adj);
        }
    }

    // step 2=Transpose of graph ( if 2 -> 3 then change to, 3 -> 2)
    unordered_map<int, list<int>> transposedGraph;
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0; // doing false again for transpose
        for (auto neighbr : adj[i])
        {
            transposedGraph[neighbr].push_back(i);
        }
    }

    // step 3 - dfs call using above ordering

    int count = 0;
    while (!stc.empty())
    {
        int topNode = stc.top();
        stc.pop();
        if (!visited[topNode])
        {
            count++;
            revdfs(topNode, visited, transposedGraph);
        }
    }
    return count;
}