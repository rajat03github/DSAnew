#include <bits/stdc++.h>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    // parent is required to maintain the condition
    unordered_map<int, int> parent;

    // first parent ko -1 maark krdo iska koi parent nhi h
    parent[src] = -1;
    // ab isko visited mark krdo
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neighbr : adjList[frontNode])
        {
            if (visited[neighbr] == true && neighbr != parent[frontNode])
                return true;

            else if (!visited[neighbr])
            {
                q.push(neighbr);
                visited[neighbr] = 1;
                parent[neighbr] = frontNode;
            }
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
            bool ans = isCyclicBFS(i, visited, adjList);
            if (ans == 1)
                return "Yes";
        }
    }
    return "No";
}
