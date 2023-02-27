#include <bits/stdc++.h>
using namespace std;

bool checkCycleDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    dfsVisited[node] = true;

    // for all adjsNodes
    for (auto neighbr : adjList[node])
    {
        if (!visited[neighbr])
        {
            bool Cycledetected = checkCycleDfs(neighbr, visited, dfsVisited, adjList);
            if (Cycledetected)
                return true;
        }
        else if (dfsVisited[neighbr])
        { // visited true and DFS = true
            return true;
        }
    }

    dfsVisited[node] = false;

    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // create adjlist
    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v); // directed graph
    }

    // call dfs for all components

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool Cyclefound = checkCycleDfs(i, visited, dfsVisited, adjList);
            if (Cyclefound)
                return true;
        }
    }

    return false;
}