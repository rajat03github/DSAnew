#include <bits/stdc++.h>
using namespace std;

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;

    for (auto neighbr : adjList[node])
    {
        if (!visited[neighbr])
        {
            bool Cycledetected = isCyclicDFS(neighbr, node, visited, adjList);

            if (Cycledetected)
                return true;
        }
        else if (neighbr != parent)
        {
            // cycle present
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // because undirectd
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;
    // i is source node
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, visited, adjList);
            if (ans == 1)
                return "Yes";
        }
    }
    return "No";
}
